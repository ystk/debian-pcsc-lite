/*
 * MUSCLE SmartCard Development ( http://www.linuxnet.com )
 *
 * Copyright (C) 2001-2004
 *  David Corcoran <corcoran@linuxnet.com>
 *  Damien Sauveron <damien.sauveron@labri.fr>
 *  Ludoic Rousseau <ludovic.rousseau@free.fr>
 *
 * $Id: winscard_msg_srv.c 3260 2009-01-02 15:19:59Z rousseau $
 */

/**
 * @file
 * @brief client/server communication (on the server side only)
 *
 * A file based socket (\c commonSocket) is used to send/receive only messages
 * among clients and server.\n
 * The messages' data are passed throw a memory mapped file: \c sharedSegmentMsg.
 */

#include "config.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#ifdef HAVE_SYS_FILIO_H
#include <sys/filio.h>
#endif

#include "misc.h"
#include "pcscd.h"
#include "winscard.h"
#include "debuglog.h"
#include "winscard_msg.h"
#include "sys_generic.h"

/**
 * Socket to a file, used for clients-server comminication.
 */
static int commonSocket = 0;
extern char AraKiri;
extern char ReCheckSerialReaders;

static const char *CommandsText[] = {
	"CMD_VERSION",	/* mtype = 0xF8 and command = 0x00 */
	"ESTABLISH_CONTEXT",	/* mtype = 0xF1 */
	"RELEASE_CONTEXT",
	"LIST_READERS",
	"CONNECT",
	"RECONNECT",
	"DISCONNECT",
	"BEGIN_TRANSACTION",
	"END_TRANSACTION",
	"TRANSMIT",
	"CONTROL",
	"STATUS",
	"GET_STATUS_CHANGE",
	"CANCEL",
	"CANCEL_TRANSACTION",
	"GET_ATTRIB",
	"SET_ATTRIB",
	"TRANSMIT_EXTENDED",
	"CONTROL_EXTENDED",
	"NULL"
};

/**
 * @brief Accepts a Client connection.
 *
 * Called by \c SHMProcessEventsServer().
 *
 * @param[out] pdwClientID Connection ID used to reference the Client.
 *
 * @return Error code.
 * @retval 0 Success.
 * @retval -1 Can not establish the connection.
 * @retval -1 Can not set the connection to non-blocking mode.
 */
static int SHMProcessCommonChannelRequest(/*@out@*/ uint32_t *pdwClientID)
{
	socklen_t clnt_len;
	int new_sock;
	struct sockaddr_un clnt_addr;
	int one;

	clnt_len = sizeof(clnt_addr);

	if ((new_sock = accept(commonSocket, (struct sockaddr *) &clnt_addr,
				&clnt_len)) < 0)
	{
		Log2(PCSC_LOG_CRITICAL, "Accept on common socket: %s",
			strerror(errno));
		return -1;
	}

	*pdwClientID = new_sock;

	one = 1;
	if (ioctl(*pdwClientID, FIONBIO, &one) < 0)
	{
		Log2(PCSC_LOG_CRITICAL, "Error: cannot set socket nonblocking: %s",
			strerror(errno));
		(void)SYS_CloseFile(*pdwClientID);
		*pdwClientID = -1;
		return -1;
	}

	return 0;
}

/**
 * @brief Prepares the communication channel used by the server to talk to the
 * clients.
 *
 * This is called by the server to create a socket for local IPC with the
 * clients. The socket is associated to the file \c PCSCLITE_CSOCK_NAME.
 * Each client will open a connection to this socket.
 *
 * @return Error code.
 * @retval 0 Success
 * @retval -1 Can not create the socket.
 * @retval -1 Can not bind the socket to the file \c PCSCLITE_CSOCK_NAME.
 * @retval -1 Can not put the socket in listen mode.
 */
INTERNAL int32_t SHMInitializeCommonSegment(void)
{
	static struct sockaddr_un serv_adr;

	/*
	 * Create the common shared connection socket
	 */
	if ((commonSocket = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
	{
		Log2(PCSC_LOG_CRITICAL, "Unable to create common socket: %s",
			strerror(errno));
		return -1;
	}

	serv_adr.sun_family = AF_UNIX;
	strncpy(serv_adr.sun_path, PCSCLITE_CSOCK_NAME,
		sizeof(serv_adr.sun_path));
	(void)SYS_RemoveFile(PCSCLITE_CSOCK_NAME);

	if (bind(commonSocket, (struct sockaddr *) &serv_adr,
			sizeof(serv_adr.sun_family) + strlen(serv_adr.sun_path) + 1) < 0)
	{
		Log2(PCSC_LOG_CRITICAL, "Unable to bind common socket: %s",
			strerror(errno));
		SHMCleanupSharedSegment(commonSocket, PCSCLITE_CSOCK_NAME);
		return -1;
	}

	if (listen(commonSocket, 1) < 0)
	{
		Log2(PCSC_LOG_CRITICAL, "Unable to listen common socket: %s",
			strerror(errno));
		SHMCleanupSharedSegment(commonSocket, PCSCLITE_CSOCK_NAME);
		return -1;
	}

	/*
	 * Chmod the public entry channel
	 */
	(void)SYS_Chmod(PCSCLITE_CSOCK_NAME, S_IRWXO | S_IRWXG | S_IRWXU);

	return 0;
}

/**
 * @brief Looks for messages sent by clients.
 *
 * This is called by the Server's function \c SVCServiceRunLoop().
 *
 * @param[out] pdwClientID Connection ID used to reference the Client.
 *
 * @return Error code.
 * @retval 0 Success.
 * @retval -1 Error accessing the communication channel.
 * @retval -1 Can not set the connection to non-blocking mode.
 * @retval 2 Timeout.
 */
#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
#define DO_TIMEOUT
#endif
INTERNAL int32_t SHMProcessEventsServer(uint32_t *pdwClientID)
{
	fd_set read_fd;
	int selret;
#ifdef DO_TIMEOUT
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
#endif

	FD_ZERO(&read_fd);

	/*
	 * Set up the bit masks for select
	 */
	FD_SET(commonSocket, &read_fd);

	selret = select(commonSocket + 1, &read_fd, (fd_set *) NULL,
		(fd_set *) NULL,
#ifdef DO_TIMEOUT
		&tv
#else
		NULL
#endif
		);

	if (selret < 0)
	{
		if (EINTR == errno)
			return -2;

		Log2(PCSC_LOG_CRITICAL, "Select returns with failure: %s",
			strerror(errno));
		return -1;
	}

	if (selret == 0)
		/* timeout. On *BSD only */
		return 2;

	/*
	 * A common pipe packet has arrived - it could be a new application
	 */
	if (FD_ISSET(commonSocket, &read_fd))
	{
		Log1(PCSC_LOG_DEBUG, "Common channel packet arrival");
		if (SHMProcessCommonChannelRequest(pdwClientID) == -1)
		{
			Log2(PCSC_LOG_ERROR,
				"error in SHMProcessCommonChannelRequest: %d", *pdwClientID);
			return -1;
		} else
		{
			Log2(PCSC_LOG_DEBUG,
				"SHMProcessCommonChannelRequest detects: %d", *pdwClientID);
			return 0;
		}
	}

	return -1;
}

/**
 * @brief
 *
 * Called by \c ContextThread().
 */
INTERNAL int32_t SHMProcessEventsContext(uint32_t dwClientID,
	psharedSegmentMsg msgStruct)
{
	fd_set read_fd;
	int selret, rv;
#ifdef DO_TIMEOUT
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
#endif

	FD_ZERO(&read_fd);
	FD_SET(dwClientID, &read_fd);

	selret = select(dwClientID + 1, &read_fd, (fd_set *) NULL,
		(fd_set *) NULL,
#ifdef DO_TIMEOUT
		&tv
#else
		NULL
#endif
		);

	if (selret < 0)
	{
		Log2(PCSC_LOG_ERROR, "select returns with failure: %s",
			strerror(errno));
		return -1;
	}

	if (selret == 0)
		/* timeout */
		return 2;

	if (FD_ISSET(dwClientID, &read_fd))
	{
		/*
		 * Return the current handle
		 */
		rv = SHMMessageReceive(msgStruct, sizeof(*msgStruct), dwClientID,
				       PCSCLITE_SERVER_ATTEMPTS);

		if (rv == -1)
		{	/* The client has died */
			Log2(PCSC_LOG_DEBUG, "Client has disappeared: %d", dwClientID);
			msgStruct->mtype = CMD_CLIENT_DIED;
			msgStruct->command = 0;
			(void)SYS_CloseFile(dwClientID);

			return 0;
		}

		/*
		 * Set the identifier handle
		 */
		Log3(PCSC_LOG_DEBUG, "command %s received by client %d", CommandsText[msgStruct->command], dwClientID);
		return 1;
	}

	return -1;
}

