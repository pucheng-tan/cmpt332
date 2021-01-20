/* 
#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <math.h>

#include "list.h"

/*
Purpose:
    returns the number of items in list.
In:
    list - a pointer to a list structure
Out:
    an integer
*/
int ListCount(LIST* list) 
{
    return list->size;
}

/*
Purpose:
    returns a pointer to the first item in list and makes the first item the current item.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
*/
void *ListFirst(LIST* list)
{
    if (list->size == 0){
        return NULL;
    }
    list->curr = list->first;
    return list->first->data;
}

/*
Purpose:
    returns a pointer to the last item in list and makes the last item the current one.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
*/
void *ListLast(LIST* list)
{
    if (list->size == 0){
        return NULL;
    }
    list->curr = list->last;
    return list->last->data;
}

/*
Purpose:
    advances the list's current node by one, and returns a pointer to the new current item. 
    If this operation attempts to advances the current item beyond the end of the list, 
    a NULL pointer is returned.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
    NULL - if failure to advance the current item
*/
void *ListNext(LIST* list)
{
    if (list->size == 0){
        return NULL;
    }
    if (list->curr == list->last){
        return NULL;
    }
    list->curr = list->curr->next; 
    return list->curr->data;
}

/*
Purpose:
    backs up the list's current node by one, and returns a pointer to the new current item. 
    If this operation attempts to back up the current item beyond the start of the list, 
    a NULL pointer is returned.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
    NULL - if failure to back up the current item
*/
void *ListPrev(LIST* list)
{
    if (list->size == 0){
        return NULL;
    }
    if (list->curr == list->first){
        return NULL;
    }
    list->curr = list->curr->prev; 
    return list->curr->data;
}

/*
Purpose:
    returns a pointer to the current item in list.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
*/
void *ListCurr(LIST* list)
{
    if (list->size == 0){
        return NULL;
    }
    return list->curr->data;
}
