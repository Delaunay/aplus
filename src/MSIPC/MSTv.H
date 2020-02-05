#ifndef MSTvHEADER
#define MSTvHEADER

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1997-2008 Morgan Stanley All rights reserved.
// See .../src/LICENSE for terms of distribution
//
//
///////////////////////////////////////////////////////////////////////////////

#include <MSIPC/MSLimits.H>
#include <MSTypes/MSDefines.H>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>

#define MILLION_USECS ((long)(1000000))

extern MSIPCExport int tvcmp(struct timeval* p1, struct timeval* p2);
extern MSIPCExport int tvdiff(struct timeval* p1, struct timeval* p2, struct timeval* p3);
extern MSIPCExport int tvnorm(struct timeval* p);
extern MSIPCExport int tvsum(struct timeval* p1, struct timeval* p2, struct timeval* p3);

extern MSIPCExport struct timeval tod_l;
extern MSIPCExport struct timeval* tod(void);
extern MSIPCExport time_t todsec(void);

#endif
