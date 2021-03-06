#include <sys/types.h>
#include <time.h>
#include <stddef.h>

#include "PCSC/pcsclite.h"
#include "pcscd.h"
#include "readerfactory.h"
#include "eventhandler.h"
#include "winscard_msg.h"

#include "lassert.h"

int pcsc_assert_wire_constants(void);
int pcsc_assert_wire_constants(void)
{

        /* Constants... */

        LASSERTF(PROTOCOL_VERSION_MAJOR == 3," found %lld\n",
                 (long long)PROTOCOL_VERSION_MAJOR);
        LASSERTF(PROTOCOL_VERSION_MINOR == 0," found %lld\n",
                 (long long)PROTOCOL_VERSION_MINOR);

        LASSERTF(PCSCLITE_MSG_KEY_LEN == 16," found %lld\n",
                 (long long)PCSCLITE_MSG_KEY_LEN);
        LASSERTF(PCSCLITE_MAX_MESSAGE_SIZE == 2048," found %lld\n",
                 (long long)PCSCLITE_MAX_MESSAGE_SIZE);

        LASSERTF(MAX_READERNAME == 100," found %lld\n",
                 (long long)MAX_READERNAME);
        LASSERTF(MAX_ATR_SIZE == 33," found %lld\n",
                 (long long)MAX_ATR_SIZE);
        LASSERTF(MAX_BUFFER_SIZE == 264," found %lld\n",
                 (long long)MAX_BUFFER_SIZE);

        /* enum pcsc_adm_commands */
        LASSERTF(CMD_FUNCTION == 241, " found %lld\n",
                 (long long)CMD_FUNCTION);
        LASSERTF(CMD_FAILED == 242, " found %lld\n",
                 (long long)CMD_FAILED);
        LASSERTF(CMD_SERVER_DIED == 243, " found %lld\n",
                 (long long)CMD_SERVER_DIED);
        LASSERTF(CMD_CLIENT_DIED == 244, " found %lld\n",
                 (long long)CMD_CLIENT_DIED);
        LASSERTF(CMD_READER_EVENT == 245, " found %lld\n",
                 (long long)CMD_READER_EVENT);
        LASSERTF(CMD_SYN == 246, " found %lld\n",
                 (long long)CMD_SYN);
        LASSERTF(CMD_ACK == 247, " found %lld\n",
                 (long long)CMD_ACK);
        LASSERTF(CMD_VERSION == 248, " found %lld\n",
                 (long long)CMD_VERSION);

        /* enum pcsc_msg_commands */
        LASSERTF(SCARD_ESTABLISH_CONTEXT == 1, " found %lld\n",
                 (long long)SCARD_ESTABLISH_CONTEXT);
        LASSERTF(SCARD_RELEASE_CONTEXT == 2, " found %lld\n",
                 (long long)SCARD_RELEASE_CONTEXT);
        LASSERTF(SCARD_LIST_READERS == 3, " found %lld\n",
                 (long long)SCARD_LIST_READERS);
        LASSERTF(SCARD_CONNECT == 4, " found %lld\n",
                 (long long)SCARD_CONNECT);
        LASSERTF(SCARD_RECONNECT == 5, " found %lld\n",
                 (long long)SCARD_RECONNECT);
        LASSERTF(SCARD_DISCONNECT == 6, " found %lld\n",
                 (long long)SCARD_DISCONNECT);
        LASSERTF(SCARD_BEGIN_TRANSACTION == 7, " found %lld\n",
                 (long long)SCARD_BEGIN_TRANSACTION);
        LASSERTF(SCARD_END_TRANSACTION == 8, " found %lld\n",
                 (long long)SCARD_END_TRANSACTION);
        LASSERTF(SCARD_TRANSMIT == 9, " found %lld\n",
                 (long long)SCARD_TRANSMIT);
        LASSERTF(SCARD_CONTROL == 10, " found %lld\n",
                 (long long)SCARD_CONTROL);
        LASSERTF(SCARD_STATUS == 11, " found %lld\n",
                 (long long)SCARD_STATUS);
        LASSERTF(SCARD_GET_STATUS_CHANGE == 12, " found %lld\n",
                 (long long)SCARD_GET_STATUS_CHANGE);
        LASSERTF(SCARD_CANCEL == 13, " found %lld\n",
                 (long long)SCARD_CANCEL);
        LASSERTF(SCARD_CANCEL_TRANSACTION == 14, " found %lld\n",
                 (long long)SCARD_CANCEL_TRANSACTION);
        LASSERTF(SCARD_GET_ATTRIB == 15, " found %lld\n",
                 (long long)SCARD_GET_ATTRIB);
        LASSERTF(SCARD_SET_ATTRIB == 16, " found %lld\n",
                 (long long)SCARD_SET_ATTRIB);
        /* Types... */

        /* Checks for struct rxSharedSegment */
        LASSERTF((int)sizeof(struct rxSharedSegment) == 2088, " found %lld\n",
                 (long long)(int)sizeof(struct rxSharedSegment));
        LASSERTF((int)offsetof(struct rxSharedSegment, mtype) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, mtype));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->mtype) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->mtype));
        LASSERTF((int)offsetof(struct rxSharedSegment, user_id) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, user_id));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->user_id) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->user_id));
        LASSERTF((int)offsetof(struct rxSharedSegment, group_id) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, group_id));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->group_id) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->group_id));
        LASSERTF((int)offsetof(struct rxSharedSegment, command) == 12, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, command));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->command) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->command));
        LASSERTF((int)offsetof(struct rxSharedSegment, date) == 16, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, date));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->date) == 8, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->date));
        LASSERTF((int)offsetof(struct rxSharedSegment, key) == 24, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, key));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->key) == 16, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->key));
        LASSERTF((int)offsetof(struct rxSharedSegment, data) == 40, " found %lld\n",
                 (long long)(int)offsetof(struct rxSharedSegment, data));
        LASSERTF((int)sizeof(((struct rxSharedSegment *)0)->data) == 2048, " found %lld\n",
                 (long long)(int)sizeof(((struct rxSharedSegment *)0)->data));

        /* Checks for struct version_struct */
        LASSERTF((int)sizeof(struct version_struct) == 12, " found %lld\n",
                 (long long)(int)sizeof(struct version_struct));
        LASSERTF((int)offsetof(struct version_struct, major) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct version_struct, major));
        LASSERTF((int)sizeof(((struct version_struct *)0)->major) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct version_struct *)0)->major));
        LASSERTF((int)offsetof(struct version_struct, minor) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct version_struct, minor));
        LASSERTF((int)sizeof(((struct version_struct *)0)->minor) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct version_struct *)0)->minor));
        LASSERTF((int)offsetof(struct version_struct, rv) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct version_struct, rv));
        LASSERTF((int)sizeof(((struct version_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct version_struct *)0)->rv));

        /* Checks for struct client_struct */
        LASSERTF((int)sizeof(struct client_struct) == 4, " found %lld\n",
                 (long long)(int)sizeof(struct client_struct));
        LASSERTF((int)offsetof(struct client_struct, hContext) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct client_struct, hContext));
        LASSERTF((int)sizeof(((struct client_struct *)0)->hContext) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct client_struct *)0)->hContext));

        /* Checks for struct establish_struct */
        LASSERTF((int)sizeof(struct establish_struct) == 12, " found %lld\n",
                 (long long)(int)sizeof(struct establish_struct));
        LASSERTF((int)offsetof(struct establish_struct, dwScope) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct establish_struct, dwScope));
        LASSERTF((int)sizeof(((struct establish_struct *)0)->dwScope) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct establish_struct *)0)->dwScope));
        LASSERTF((int)offsetof(struct establish_struct, hContext) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct establish_struct, hContext));
        LASSERTF((int)sizeof(((struct establish_struct *)0)->hContext) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct establish_struct *)0)->hContext));
        LASSERTF((int)offsetof(struct establish_struct, rv) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct establish_struct, rv));
        LASSERTF((int)sizeof(((struct establish_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct establish_struct *)0)->rv));

        /* Checks for struct release_struct */
        LASSERTF((int)sizeof(struct release_struct) == 8, " found %lld\n",
                 (long long)(int)sizeof(struct release_struct));
        LASSERTF((int)offsetof(struct release_struct, hContext) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct release_struct, hContext));
        LASSERTF((int)sizeof(((struct release_struct *)0)->hContext) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct release_struct *)0)->hContext));
        LASSERTF((int)offsetof(struct release_struct, rv) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct release_struct, rv));
        LASSERTF((int)sizeof(((struct release_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct release_struct *)0)->rv));

        /* Checks for struct connect_struct */
        LASSERTF((int)sizeof(struct connect_struct) == 124, " found %lld\n",
                 (long long)(int)sizeof(struct connect_struct));
        LASSERTF((int)offsetof(struct connect_struct, hContext) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, hContext));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->hContext) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->hContext));
        LASSERTF((int)offsetof(struct connect_struct, szReader) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, szReader));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->szReader) == 100, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->szReader));
        LASSERTF((int)offsetof(struct connect_struct, dwShareMode) == 104, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, dwShareMode));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->dwShareMode) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->dwShareMode));
        LASSERTF((int)offsetof(struct connect_struct, dwPreferredProtocols) == 108, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, dwPreferredProtocols));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->dwPreferredProtocols) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->dwPreferredProtocols));
        LASSERTF((int)offsetof(struct connect_struct, hCard) == 112, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, hCard));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct connect_struct, dwActiveProtocol) == 116, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, dwActiveProtocol));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->dwActiveProtocol) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->dwActiveProtocol));
        LASSERTF((int)offsetof(struct connect_struct, rv) == 120, " found %lld\n",
                 (long long)(int)offsetof(struct connect_struct, rv));
        LASSERTF((int)sizeof(((struct connect_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct connect_struct *)0)->rv));

        /* Checks for struct reconnect_struct */
        LASSERTF((int)sizeof(struct reconnect_struct) == 24, " found %lld\n",
                 (long long)(int)sizeof(struct reconnect_struct));
        LASSERTF((int)offsetof(struct reconnect_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct reconnect_struct, hCard));
        LASSERTF((int)sizeof(((struct reconnect_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct reconnect_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct reconnect_struct, dwShareMode) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct reconnect_struct, dwShareMode));
        LASSERTF((int)sizeof(((struct reconnect_struct *)0)->dwShareMode) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct reconnect_struct *)0)->dwShareMode));
        LASSERTF((int)offsetof(struct reconnect_struct, dwPreferredProtocols) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct reconnect_struct, dwPreferredProtocols));
        LASSERTF((int)sizeof(((struct reconnect_struct *)0)->dwPreferredProtocols) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct reconnect_struct *)0)->dwPreferredProtocols));
        LASSERTF((int)offsetof(struct reconnect_struct, dwInitialization) == 12, " found %lld\n",
                 (long long)(int)offsetof(struct reconnect_struct, dwInitialization));
        LASSERTF((int)sizeof(((struct reconnect_struct *)0)->dwInitialization) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct reconnect_struct *)0)->dwInitialization));
        LASSERTF((int)offsetof(struct reconnect_struct, dwActiveProtocol) == 16, " found %lld\n",
                 (long long)(int)offsetof(struct reconnect_struct, dwActiveProtocol));
        LASSERTF((int)sizeof(((struct reconnect_struct *)0)->dwActiveProtocol) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct reconnect_struct *)0)->dwActiveProtocol));
        LASSERTF((int)offsetof(struct reconnect_struct, rv) == 20, " found %lld\n",
                 (long long)(int)offsetof(struct reconnect_struct, rv));
        LASSERTF((int)sizeof(((struct reconnect_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct reconnect_struct *)0)->rv));

        /* Checks for struct disconnect_struct */
        LASSERTF((int)sizeof(struct disconnect_struct) == 12, " found %lld\n",
                 (long long)(int)sizeof(struct disconnect_struct));
        LASSERTF((int)offsetof(struct disconnect_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct disconnect_struct, hCard));
        LASSERTF((int)sizeof(((struct disconnect_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct disconnect_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct disconnect_struct, dwDisposition) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct disconnect_struct, dwDisposition));
        LASSERTF((int)sizeof(((struct disconnect_struct *)0)->dwDisposition) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct disconnect_struct *)0)->dwDisposition));
        LASSERTF((int)offsetof(struct disconnect_struct, rv) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct disconnect_struct, rv));
        LASSERTF((int)sizeof(((struct disconnect_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct disconnect_struct *)0)->rv));

        /* Checks for struct begin_struct */
        LASSERTF((int)sizeof(struct begin_struct) == 8, " found %lld\n",
                 (long long)(int)sizeof(struct begin_struct));
        LASSERTF((int)offsetof(struct begin_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct begin_struct, hCard));
        LASSERTF((int)sizeof(((struct begin_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct begin_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct begin_struct, rv) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct begin_struct, rv));
        LASSERTF((int)sizeof(((struct begin_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct begin_struct *)0)->rv));

        /* Checks for struct end_struct */
        LASSERTF((int)sizeof(struct end_struct) == 12, " found %lld\n",
                 (long long)(int)sizeof(struct end_struct));
        LASSERTF((int)offsetof(struct end_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct end_struct, hCard));
        LASSERTF((int)sizeof(((struct end_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct end_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct end_struct, dwDisposition) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct end_struct, dwDisposition));
        LASSERTF((int)sizeof(((struct end_struct *)0)->dwDisposition) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct end_struct *)0)->dwDisposition));
        LASSERTF((int)offsetof(struct end_struct, rv) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct end_struct, rv));
        LASSERTF((int)sizeof(((struct end_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct end_struct *)0)->rv));

        /* Checks for struct cancel_struct */
        LASSERTF((int)sizeof(struct cancel_struct) == 8, " found %lld\n",
                 (long long)(int)sizeof(struct cancel_struct));
        LASSERTF((int)offsetof(struct cancel_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct cancel_struct, hCard));
        LASSERTF((int)sizeof(((struct cancel_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct cancel_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct cancel_struct, rv) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct cancel_struct, rv));
        LASSERTF((int)sizeof(((struct cancel_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct cancel_struct *)0)->rv));

        /* Checks for struct status_struct */
        LASSERTF((int)sizeof(struct status_struct) == 160, " found %lld\n",
                 (long long)(int)sizeof(struct status_struct));
        LASSERTF((int)offsetof(struct status_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, hCard));
        LASSERTF((int)sizeof(((struct status_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct status_struct, mszReaderNames) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, mszReaderNames));
        LASSERTF((int)sizeof(((struct status_struct *)0)->mszReaderNames) == 100, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->mszReaderNames));
        LASSERTF((int)offsetof(struct status_struct, pcchReaderLen) == 104, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, pcchReaderLen));
        LASSERTF((int)sizeof(((struct status_struct *)0)->pcchReaderLen) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->pcchReaderLen));
        LASSERTF((int)offsetof(struct status_struct, dwState) == 108, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, dwState));
        LASSERTF((int)sizeof(((struct status_struct *)0)->dwState) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->dwState));
        LASSERTF((int)offsetof(struct status_struct, dwProtocol) == 112, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, dwProtocol));
        LASSERTF((int)sizeof(((struct status_struct *)0)->dwProtocol) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->dwProtocol));
        LASSERTF((int)offsetof(struct status_struct, pbAtr) == 116, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, pbAtr));
        LASSERTF((int)sizeof(((struct status_struct *)0)->pbAtr) == 33, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->pbAtr));
        LASSERTF((int)offsetof(struct status_struct, pcbAtrLen) == 152, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, pcbAtrLen));
        LASSERTF((int)sizeof(((struct status_struct *)0)->pcbAtrLen) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->pcbAtrLen));
        LASSERTF((int)offsetof(struct status_struct, rv) == 156, " found %lld\n",
                 (long long)(int)offsetof(struct status_struct, rv));
        LASSERTF((int)sizeof(((struct status_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct status_struct *)0)->rv));

        /* Checks for struct transmit_struct */
        LASSERTF((int)sizeof(struct transmit_struct) == 560, " found %lld\n",
                 (long long)(int)sizeof(struct transmit_struct));
        LASSERTF((int)offsetof(struct transmit_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, hCard));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct transmit_struct, ioSendPciProtocol) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, ioSendPciProtocol));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->ioSendPciProtocol) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->ioSendPciProtocol));
        LASSERTF((int)offsetof(struct transmit_struct, ioSendPciLength) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, ioSendPciLength));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->ioSendPciLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->ioSendPciLength));
        LASSERTF((int)offsetof(struct transmit_struct, pbSendBuffer) == 12, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, pbSendBuffer));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->pbSendBuffer) == 264, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->pbSendBuffer));
        LASSERTF((int)offsetof(struct transmit_struct, cbSendLength) == 276, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, cbSendLength));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->cbSendLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->cbSendLength));
        LASSERTF((int)offsetof(struct transmit_struct, ioRecvPciProtocol) == 280, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, ioRecvPciProtocol));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->ioRecvPciProtocol) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->ioRecvPciProtocol));
        LASSERTF((int)offsetof(struct transmit_struct, ioRecvPciLength) == 284, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, ioRecvPciLength));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->ioRecvPciLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->ioRecvPciLength));
        LASSERTF((int)offsetof(struct transmit_struct, pbRecvBuffer) == 288, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, pbRecvBuffer));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->pbRecvBuffer) == 264, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->pbRecvBuffer));
        LASSERTF((int)offsetof(struct transmit_struct, pcbRecvLength) == 552, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, pcbRecvLength));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->pcbRecvLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->pcbRecvLength));
        LASSERTF((int)offsetof(struct transmit_struct, rv) == 556, " found %lld\n",
                 (long long)(int)offsetof(struct transmit_struct, rv));
        LASSERTF((int)sizeof(((struct transmit_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct transmit_struct *)0)->rv));

        /* Checks for struct control_struct */
        LASSERTF((int)sizeof(struct control_struct) == 552, " found %lld\n",
                 (long long)(int)sizeof(struct control_struct));
        LASSERTF((int)offsetof(struct control_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, hCard));
        LASSERTF((int)sizeof(((struct control_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct control_struct, dwControlCode) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, dwControlCode));
        LASSERTF((int)sizeof(((struct control_struct *)0)->dwControlCode) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->dwControlCode));
        LASSERTF((int)offsetof(struct control_struct, pbSendBuffer) == 8, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, pbSendBuffer));
        LASSERTF((int)sizeof(((struct control_struct *)0)->pbSendBuffer) == 264, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->pbSendBuffer));
        LASSERTF((int)offsetof(struct control_struct, cbSendLength) == 272, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, cbSendLength));
        LASSERTF((int)sizeof(((struct control_struct *)0)->cbSendLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->cbSendLength));
        LASSERTF((int)offsetof(struct control_struct, pbRecvBuffer) == 276, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, pbRecvBuffer));
        LASSERTF((int)sizeof(((struct control_struct *)0)->pbRecvBuffer) == 264, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->pbRecvBuffer));
        LASSERTF((int)offsetof(struct control_struct, cbRecvLength) == 540, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, cbRecvLength));
        LASSERTF((int)sizeof(((struct control_struct *)0)->cbRecvLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->cbRecvLength));
        LASSERTF((int)offsetof(struct control_struct, dwBytesReturned) == 544, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, dwBytesReturned));
        LASSERTF((int)sizeof(((struct control_struct *)0)->dwBytesReturned) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->dwBytesReturned));
        LASSERTF((int)offsetof(struct control_struct, rv) == 548, " found %lld\n",
                 (long long)(int)offsetof(struct control_struct, rv));
        LASSERTF((int)sizeof(((struct control_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct control_struct *)0)->rv));

        /* Checks for struct getset_struct */
        LASSERTF((int)sizeof(struct getset_struct) == 280, " found %lld\n",
                 (long long)(int)sizeof(struct getset_struct));
        LASSERTF((int)offsetof(struct getset_struct, hCard) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct getset_struct, hCard));
        LASSERTF((int)sizeof(((struct getset_struct *)0)->hCard) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct getset_struct *)0)->hCard));
        LASSERTF((int)offsetof(struct getset_struct, dwAttrId) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct getset_struct, dwAttrId));
        LASSERTF((int)sizeof(((struct getset_struct *)0)->dwAttrId) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct getset_struct *)0)->dwAttrId));
        LASSERTF((int)offsetof(struct getset_struct, cbAttrLen) == 272, " found %lld\n",
                 (long long)(int)offsetof(struct getset_struct, cbAttrLen));
        LASSERTF((int)sizeof(((struct getset_struct *)0)->cbAttrLen) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct getset_struct *)0)->cbAttrLen));
        LASSERTF((int)offsetof(struct getset_struct, rv) == 276, " found %lld\n",
                 (long long)(int)offsetof(struct getset_struct, rv));
        LASSERTF((int)sizeof(((struct getset_struct *)0)->rv) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct getset_struct *)0)->rv));

        /* Checks for struct pubReaderStatesList */
        LASSERTF((int)sizeof(struct pubReaderStatesList) == 156, " found %lld\n",
                 (long long)(int)sizeof(struct pubReaderStatesList));
        LASSERTF((int)offsetof(struct pubReaderStatesList, readerID) == 0, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, readerID));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->readerID) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->readerID));
        LASSERTF((int)offsetof(struct pubReaderStatesList, readerName) == 4, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, readerName));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->readerName) == 100, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->readerName));
        LASSERTF((int)offsetof(struct pubReaderStatesList, readerState) == 104, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, readerState));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->readerState) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->readerState));
        LASSERTF((int)offsetof(struct pubReaderStatesList, readerSharing) == 108, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, readerSharing));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->readerSharing) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->readerSharing));
        LASSERTF((int)offsetof(struct pubReaderStatesList, cardAtr) == 112, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, cardAtr));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->cardAtr) == 33, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->cardAtr));
        LASSERTF((int)offsetof(struct pubReaderStatesList, cardAtrLength) == 148, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, cardAtrLength));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->cardAtrLength) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->cardAtrLength));
        LASSERTF((int)offsetof(struct pubReaderStatesList, cardProtocol) == 152, " found %lld\n",
                 (long long)(int)offsetof(struct pubReaderStatesList, cardProtocol));
        LASSERTF((int)sizeof(((struct pubReaderStatesList *)0)->cardProtocol) == 4, " found %lld\n",
                 (long long)(int)sizeof(((struct pubReaderStatesList *)0)->cardProtocol));

return 0;
}
