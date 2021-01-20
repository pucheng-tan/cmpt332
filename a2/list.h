/* 
#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct NODE
{
    void* data;
    struct NODE* next;
    struct NODE* prev;
    struct NODE* next_free_node;
} NODE;

typedef struct LIST
{
    int size;
    NODE* first;
    NODE* curr;
    NODE* last;
    struct LIST* next_free_list;
} LIST;

LIST *ListCreate();
int ListCount(LIST*);
void *ListFirst(LIST*);
void *ListLast(LIST*);
void *ListNext(LIST*);
void *ListPrev(LIST*);
void *ListCurr(LIST*);
int ListAdd(LIST*, void*);
int ListInsert(LIST*, void*);
int ListAppend(LIST*, void*);
int ListPrepend(LIST*, void*);
void *ListRemove(LIST*);
void ListConcat(LIST*, LIST*);
void ListFree(LIST*, void(*)(void*));
void *ListTrim(LIST*);
void *ListSearch(LIST*, int (*)(void*, void*), void*);

#endif /* LIST_H_ */

