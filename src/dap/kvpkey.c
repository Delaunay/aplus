/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
/* contributed by Daniel F. Fisher */

/* header file inclusions */
#include <dap/kvp.h>
#include <dap/node.h>

/* external function definitions */
void* kvpkey(struct node* np)
{
    return KVPAT(np)->key;
}
