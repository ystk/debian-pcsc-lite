/*
 * MUSCLE SmartCard Development ( http://www.linuxnet.com )
 *
 * Copyright (C) 1999
 *  David Corcoran <corcoran@linuxnet.com>
 *
 * $Id: atrhandler.h 4291 2009-07-01 12:23:22Z rousseau $
 */

/**
 * @file
 * @brief This keeps track of smartcard protocols, timing issues
 * and Answer to Reset ATR handling.
 */

#ifndef __atrhandler_h__
#define __atrhandler_h__

#ifdef __cplusplus
extern "C"
{
#endif

#define SCARD_CONVENTION_DIRECT  0x0001
#define SCARD_CONVENTION_INVERSE 0x0002

	typedef struct _SMARTCARD_EXTENSION
	{

		struct _ATR
		{
			int Length;
			int HistoryLength;
			UCHAR Value[MAX_ATR_SIZE];
			UCHAR HistoryValue[MAX_ATR_SIZE];
		}
		ATR;

		struct _CardCapabilities
		{
			UCHAR AvailableProtocols;
			UCHAR CurrentProtocol;
			UCHAR Convention;
		}
		CardCapabilities;
	}
	SMARTCARD_EXTENSION, *PSMARTCARD_EXTENSION;

	/*
	 * Decodes the ATR and fills the structure
	 */

	short ATRDecodeAtr(/*@out@*/ PSMARTCARD_EXTENSION psExtension,
		PUCHAR pucAtr, DWORD dwLength);

#ifdef __cplusplus
}
#endif

#endif							/* __atrhandler_h__ */
