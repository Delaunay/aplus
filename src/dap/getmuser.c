/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include <rpcsvc/ypclnt.h>
#include <sys/types.h>

int getmuser(char* name, char* Unix, char* Mainframe)
{
    int ret, len;
    static char *val, *dom;

    if (dom == (char*)(0))
        (void)yp_get_default_domain(&dom);
    if (val)
        free(val);

    if ((ret = yp_match(dom, "musers", name,
             strlen(name), &val, &len))
        == 0) {
        (void)sscanf(val, "%s %s", Unix, Mainframe);
        return (0);
    } else
        return (ret);
}
