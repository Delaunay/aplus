#ifndef AplusHashTableHEADER
#define AplusHashTableHEADER

///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1997-2008 Morgan Stanley All rights reserved.
// See .../src/LICENSE for terms of distribution.
//
//
///////////////////////////////////////////////////////////////////////////////

#include <MSTypes/MSHashTable.H>
#include <MSTypes/MSTime.H>
#include <a/k.h>

class AplusHashTable : public MSHashTable {
public:
    AplusHashTable(unsigned = 0);
    virtual ~AplusHashTable(void);

    A listAllEntries(void) const;
};

#endif //AplusHashTableHEADER
