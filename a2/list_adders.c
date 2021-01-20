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

#define TOTAL_LISTS 10
#define TOTAL_NODES 100

LIST* Lists;
LIST* curr_free_list;

NODE* Nodes;
NODE* curr_free_node;

/*
Purpose:
    makes a new, empty list, and returns its reference on success. initialize memory blocks if it is
    the first execution
In:
    NONE
Out:
    a pointer to a structure of type LIST - if success
    NULL - if failure
*/
LIST *ListCreate()
{
    LIST* newList;
    int i;

    static int TRIGGER = 0;
    if (TRIGGER == 0){
        Lists = malloc(sizeof(LIST) * TOTAL_LISTS);
        for (i=0; i<TOTAL_LISTS-1; i++){
            Lists[i].next_free_list = &Lists[i+1];
        }
        Lists[TOTAL_LISTS-1].next_free_list = NULL;
        curr_free_list = &Lists[0];

        Nodes = malloc(sizeof(NODE) * TOTAL_NODES);
        for (i=0; i<TOTAL_NODES-1; i++){
            Nodes[i].next_free_node = &Nodes[i+1];
        }
        Nodes[TOTAL_NODES-1].next_free_node = NULL;
        curr_free_node = &Nodes[0];

        TRIGGER ++;
    }

    /* check if there is any free lists available */
    if (curr_free_list == NULL){
        return NULL;
    }
    newList = curr_free_list;
    curr_free_list = curr_free_list->next_free_list;
    newList->next_free_list = NULL;

    newList->curr = NULL;
    newList->first = NULL;
    newList->last = NULL;
    newList->size = 0;

    return newList;
}

/*
Purpose:   
    adds the new item to list directly after the current item, and makes item the current item. 
    If the current pointer is at the end of the list, the item is added at the end.
In:
    list - pointer to a list structure
    item - pointer to an item
Out:
    0 - if success
    -1 - if failure
*/
int ListAdd(LIST* list, void* item)
{
    NODE* newNode;

    /* check if there is any free nodes available */
    if (curr_free_node == NULL){
        return -1;
    }
    
    newNode = curr_free_node;
    curr_free_node = curr_free_node->next_free_node;
    newNode->next_free_node = NULL;
    
    newNode->data = item;

    /* add when the list is empty */
    if (list->size == 0){
        list->first = newNode;
        list->last = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    /* add to the end of the list */
    else if (list->curr == list->last){
        newNode->prev = list->curr;
        newNode->next = NULL;
        list->curr->next = newNode;
        list->last = newNode;
    }
    /* add to the middle of the list */
    else {
        newNode->prev = list->curr;
        newNode->next = list->curr->next;
        list->curr->next = newNode;
        newNode->next->prev = newNode;
    }
    list->curr = newNode;
    list->size ++;

    return 0;
}

/*
Purpose:
    adds item to list directly before the current item, and makes the new item the current one. 
    If the current pointer is at the start of the list, the item is added at the start. 
In:
    list - pointer to a list structure
    item - pointer to an item
Out:
    0 - if success
    -1 - if failure
*/
int ListInsert(LIST* list, void* item)
{
    NODE* newNode;

    /* check if there is any free nodes available */
    if (curr_free_node == NULL){
        return -1;
    }
    newNode = curr_free_node;
    curr_free_node = curr_free_node->next_free_node;
    newNode->next_free_node = NULL;
    
    newNode->data = item;

    /* add when the list is empty */
    if (list->size == 0){
        list->first = newNode;
        list->last = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    /* add to the front of the list */
    else if (list->curr == list->first){
        newNode->next = list->curr;
        newNode->prev = NULL;
        list->curr->prev = newNode;
        list->first = newNode;
    }
    /* add to the middle of the list */
    else {
        newNode->next = list->curr;
        newNode->prev = list->curr->prev;
        list->curr->prev = newNode;
        newNode->prev->next = newNode;
    }
    
    list->curr = newNode;
    list->size ++;

    return 0;
}

/*
Purpose:
    adds item to the end of list, and makes the new item the current one.
In:
    list - pointer to a list structure
    item - pointer to an item
Out:
    0 - if success
    -1 - if failure
*/
int ListAppend(LIST* list, void* item)
{
    NODE* newNode;

    /* check if there is any free nodes available */
    if (curr_free_node == NULL){
        return -1;
    }
    newNode = curr_free_node;
    curr_free_node = curr_free_node->next_free_node;
    newNode->next_free_node = NULL;
    
    newNode->data = item;

    /* add when the list is empty */
    if (list->size == 0){
        list->first = newNode;
        list->last = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    
    else{
        list->last->next = newNode;
        newNode->next = NULL;
        newNode->prev = list->last;
        list->last = newNode;
    }
    
    list->curr = newNode;
    list->size ++;

    return 0;
}

/*
Purpose:
    adds item to the front of list, and makes the new item the current one.
In:
    list - pointer to a list structure
    item - pointer to an item
Out:
    0 - if success
    -1 - if failure
*/
int ListPrepend(LIST* list, void* item)
{
    NODE* newNode;

    /* check if there is any free nodes available */
    if (curr_free_node == NULL){
        return -1;
    }
    newNode = curr_free_node;
    curr_free_node = curr_free_node->next_free_node;
    newNode->next_free_node = NULL;
    
    newNode->data = item;

    /* add when the list is empty */
    if (list->size == 0){
        list->first = newNode;
        list->last = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    /* add when the list is non-empty */
    else{
        list->first->prev = newNode;
        newNode->prev = NULL;
        newNode->next = list->first;
        list->first = newNode;
    }
    
    list->curr = newNode;
    list->size ++;

    return 0;
}
