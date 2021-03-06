/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
/* contributed by Daniel F. Fisher */

/* header file inclusions */
#include <dap/balloc.h>

/* external function definitions */
void* bdup_r(void* p, int size)
{
    void* r = balloc_r(size);

    if ((r != (void*)(0))
        && (p != (void*)(0))) {
        /*
     * size is not negative because balloc_r would have returned (void *)(0)
     */
        bcopy((char*)p, (char*)r, size);
    }
    return r;
}
