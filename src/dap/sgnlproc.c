/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
/* contributed by Daniel F. Fisher */

/* header file inclusions */
#include <dap/sgnl.h>
#include <stdio.h>

/* external function definitions */
int sgnlproc(void)
{
    int n;
    struct sgnl* p;
    sigset_t savemask;
    struct sigaction act;

    int didwork = 0;

    for (n = 1; n < NSIG; n++) {
        if ((p = sgnls + n)->flag) {

            sigaction(n, NULL, &act);
            savemask = act.sa_mask;
            sigemptyset(&act.sa_mask);
            sigaddset(&act.sa_mask, n);
            sigaction(n, &act, NULL);
            p->flag = 0;
            act.sa_mask = savemask;
            sigaction(n, &act, NULL);

            (*(p->func))(n);
            didwork = 1;
        }
    }
    return didwork;
}
