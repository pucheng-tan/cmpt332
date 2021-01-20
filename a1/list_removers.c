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

extern NODE* curr_free_node;
extern LIST* curr_free_list;

/*
Purpose:
    Return current item and take it out of list. Make the next item the current one.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
    NULL - if the list is empty
*/
void *ListRemove(LIST* list)
{
    if (list->size == 0){
        return NULL;
    }
    
    NODE* nodeReturn = list->curr;

    // delete when there is only one node in the list
    if (list->size == 1){
        list->first = NULL;
        list->last = NULL;
        list->curr = NULL;
    }

    // delete the first node in the list
    else if (list->curr == list->first){
        list->first = list->curr->next;
        list->first->prev = NULL;
        list->curr = list->first;
    }

    // delete the last node in the list
    else if (list->curr == list->last){
        list->last = list->curr->prev;
        list->last->next = NULL;
        list->curr = list->last;
    }

    // delete node in the middle of the list
    else{
        list->curr->prev->next = list->curr->next;
        list->curr->next->prev = list->curr->prev;
        list->curr = list->curr->next;
    }

    list->size --;

    // free the node to be deleted
    nodeReturn->next_free_node = curr_free_node;
    curr_free_node = nodeReturn;

    void* dataReturn = nodeReturn->data;

    curr_free_node->data = NULL;
    curr_free_node->next = NULL;
    curr_free_node->prev = NULL;

    return dataReturn;
}

/*
Purpose:
    adds list2 to the end of list1. The current pointer is set to the current pointer of list1. 
    List2 no longer exists after the operation.
In:
    list1 - a pointer to a list structure
    list2 - a pointer to a list structure
Out:
    NONE
*/
void ListConcat(LIST* list1, LIST* list2)
{
    // if both lists are not empty
    if (list1->size != 0 && list2->size != 0){
        list1->last->next = list2->first;
        list2->first->prev = list1->last;
        list1->last = list2->last;
    }
    // if list1 is empty but list2 is not empty, set the current pointer 
    // of the newlist to the current pointer of list2
    else if (list1->size == 0 && list2->size != 0){
        list1->first = list2->first;
        list1->last = list2->last;
        list1->curr = list2->curr;
    }
    // For the scenario that both lists are empty and the scenario that list1
    // is not empty but list2 is empty, there is no need to update list1.
    // The following manipulation is for all scenarios
    list1->size = list1->size + list2->size;

    // free list2
    list2->next_free_list = curr_free_list;
    curr_free_list = list2;

    curr_free_list->curr = NULL;
    curr_free_list->first = NULL;
    curr_free_list->last = NULL;
    curr_free_list->size = 0;
}

/*
Purpose:
    delete list. itemFree is a pointer to a routine that frees an item. 
In:
    list - a pointer to a list structure
    itemFree - a pointer to a function which frees item
Out:
    NONE
*/
void ListFree(LIST* list, void (*itemFree)(void *itemToBeFreed))
{
    list->curr = list->first;
    while (list->curr != NULL){
        list->curr->next_free_node = curr_free_node;
        curr_free_node = list->curr;

        list->curr = list->curr->next;
        itemFree(curr_free_node->data);

        curr_free_node->data = NULL;
        curr_free_node->next = NULL;
        curr_free_node->prev = NULL;
    }
    list->next_free_list = curr_free_list;
    curr_free_list = list;

    curr_free_list->curr = NULL;
    curr_free_list->first = NULL;
    curr_free_list->last = NULL;
    curr_free_list->size = 0;
}

/*
Purpose:
    Return last item and take it out of list. The current pointer shall be the new last item in the list.
In:
    list - a pointer to a list structure
Out:
    a pointer to an item
    NULL - if the list is empty
*/
void *ListTrim(LIST* list)
{
    NODE* nodeReturn;
    if (list->size == 0){
        return NULL;
    }
    else if (list->size == 1){
        nodeReturn = list->last;
        list->last = NULL;
        list->first = NULL;
        list->curr = NULL;
    }
    else{
        nodeReturn = list->last;
        list->last = list->last->prev;
        list->last->next = NULL;
        list->curr = list->last;
    }
    list->size --;

    // free the node to be deleted
    nodeReturn->next_free_node = curr_free_node;
    curr_free_node = nodeReturn;

    void* dataReturn = nodeReturn->data;

    curr_free_node->data = NULL;
    curr_free_node->next = NULL;
    curr_free_node->prev = NULL;

    return dataReturn;
}

/*
Purpose:
    searches list starting at the current item until the end is reached or a match is found. 
    In this context, a match is determined by the comparator parameter. 
    If a match is found, the current pointer is left at the matched item and 
    the pointer to that item is returned. If no match is found, the current pointer is left at the end of 
    the list and a NULL pointer is returned.
In:
    list - a pointer to a list structure
    comparator - a pointer to a function which compares two items
    comparisonArg - a pointer to an item
Out:
    a pointer to an item
    NULL - if no match is found
*/
void *ListSearch(LIST* list, int (*comparator)(void* item1, void* item2), void* comparisonArg)
{
    while (list->curr != NULL){
        int result = comparator(list->curr->data, comparisonArg);
        if (result == 1){
            return list->curr->data;
        }
        list->curr = list->curr->next;
    }
    
    list->curr = list->last;

    return NULL;
}
