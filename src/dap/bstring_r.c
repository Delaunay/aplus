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
#include <errno.h>
#include <string.h>

/* external function definitions */
char* bstring_r(char* s)
{

    if (s != (char*)(0)) {
        int size = strlen((DEV_STRARG)s) + 1;
        char* p = (char*)balloc_r(size);

        if (p != (char*)(0)) {
            bcopy(s, p, size);
        }
        return p;
    }
    errno = EDOM;
    return (char*)(0);
}
