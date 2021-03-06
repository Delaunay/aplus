/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
/* contributed by Daniel F. Fisher */

/* header file inclusions */
#include <dap/chan.h>
#include <dap/fds.h>

/* external function definitions */
void chandsbl(struct chan* p)
{
    if (p != (struct chan*)(0)) {
        fdsclr(p->fds, p->fd);
    }
    return;
}
