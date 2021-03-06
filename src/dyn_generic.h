/*
 * MUSCLE SmartCard Development ( http://www.linuxnet.com )
 *
 * Copyright (C) 1999
 *  David Corcoran <corcoran@linuxnet.com>
 *
 * $Id: dyn_generic.h 3260 2009-01-02 15:19:59Z rousseau $
 */

/**
 * @file
 * @brief This abstracts dynamic library loading functions.
 */

#ifndef __dyn_generic_h__
#define __dyn_generic_h__

#ifdef __cplusplus
extern "C"
{
#endif

	int DYN_LoadLibrary(void **, char *);
	int DYN_CloseLibrary(void **);
	int DYN_GetAddress(void *, /*@out@*/ void **, const char *);

#ifdef __cplusplus
}
#endif

#endif
