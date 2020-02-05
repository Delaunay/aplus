/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
/* contributed by Daniel F. Fisher */

/* header file inclusions */
#include <dap/conn.h>
#include <dap/tod.h>

/* external function definitions */
void connackestb(struct conn* p)
{
    if ((p != (struct conn*)(0))
        && (p->estbd == 0)) {
        p->estbtod = todsec();
        (p->estbcount)++;
        p->estbd = 1;
    }
    return;
}
