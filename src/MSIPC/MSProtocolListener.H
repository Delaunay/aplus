#ifndef MSProtocolListenerHEADER
#define MSProtocolListenerHEADER

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1997-2008 Morgan Stanley All rights reserved.
// See .../src/LICENSE for terms of distribution
//
//
///////////////////////////////////////////////////////////////////////////////

#include <MSIPC/MSHostPort.H>
#include <MSIPC/MSIPService.H>
#include <MSIPC/MSListener.H>
#include <MSTypes/MSString.H>
#include <fcntl.h>
#include <stdio.h>

class MSIPCExport MSProtocolListener : public MSListener {
protected:
    MSHostPort _hostPort;
    MSString _name;
    MSIPService _service;

    MSHostPort& hostPort(void) { return _hostPort; }
    MSIPService& service(void) { return _service; }

public:
    MSProtocolListener(const char* name_, int port_);
    MSProtocolListener(const char* name_, const MSString& serviceName_);
    ~MSProtocolListener(void);

    const MSString& name(void) const { return _name; }
    const MSString& host(void) const { return _hostPort.host(); }
    int port(void) const { return _hostPort.port(); }

    virtual MSBoolean establish(void);
};

#endif
