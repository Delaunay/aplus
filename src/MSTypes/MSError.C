///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1997-2008 Morgan Stanley All rights reserved.
// See .../src/LICENSE for terms of distribution
//
//
///////////////////////////////////////////////////////////////////////////////

#include <MSTypes/MSError.H>
#include <stdarg.h> // varargs

int MSError::error(MSError::ErrorStatus, const char*, const char*, ...) { return 0; }
