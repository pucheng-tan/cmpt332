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

void itemFree(void *item)
{
    free (item);
    return;
}

int matchEqual(void* item1, void* item2){
    if (*(int*)item1 == *(int*)item2)
        return 1;
    return 0;
}

int matchGreaterThan(void* item1, void* item2){
    if (*(int*)item1 > *(int*)item2)
        return 1;
    return 0;
}

// printList is used for testing the function ListConcat()
// printList can only print integer lists
/*void printList(LIST* list){
    pirntf("Items in the list are: ");
    list->curr = list->first;
    while (list->curr != NULL){
        printf("%d ", &list->curr->data);
        list->curr = list->curr->next;
    }
    printf("\n");
}*/

int main( int argc, char *argv[]){

    printf("--------------------ListCreate() test begin--------------------\n");
    printf("ListCreate Test1: Create a list when there is at least one free list available\n");
    LIST* list1 = ListCreate();
    LIST* list2 = ListCreate();
    LIST* list3 = ListCreate();
    LIST* list4 = ListCreate();
    LIST* list5 = ListCreate();
    if (list1 != NULL && list2 != NULL && list3 != NULL && list4 != NULL && list5 != NULL){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListCreate Test2: Create a list when there is no free list available\n");
    LIST* list6;
    list6 = ListCreate();
    if (list6 == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }
    
    printf("--------------------ListAdd() test begin--------------------\n");
    int item1 = 1;
    int item2 = 2;
    int item3 = 3;
    int item4 = 4;

    int * iPtr1 = &item1;
    int * iPtr2 = &item2;
    int * iPtr3 = &item3;
    int * iPtr4 = &item4;
    int * temp_iPtr;

    printf("ListAdd Test1: add to an empty list\n");
    ListAdd(list1, iPtr1);
    // Now, item in list1 should be: 1
    if (list1->first->data == iPtr1 && list1->last->data == iPtr1 
    && list1->curr->data == iPtr1 && list1->size == 1 
    && list1->curr->prev == NULL && list1->curr->next == NULL){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListAdd Test2: add to a list with one node\n");
    ListAdd(list1, iPtr2);
    // Now, items in list1 should be: 1, 2
    if (list1->first->data == iPtr1 && list1->last->data == iPtr2 
    && list1->curr->data == iPtr2 && list1->size == 2
    && list1->curr->prev->data == iPtr1 && list1->curr->next == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("ListAdd Test3: add to the end\n");
    ListAdd(list1, iPtr4);
    // Now, items in list1 should be: 1, 2, 4
    if (list1->first->data == iPtr1 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr4 && list1->size == 3
    && list1->curr->prev->data == iPtr2 && list1->curr->next == NULL){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("ListAdd Test4: add to the middle\n");
    ListPrev(list1);
    ListAdd(list1, iPtr3);
    // Now, items in list1 should be: 1, 2, 3, 4
    if (list1->first->data == iPtr1 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr3 && list1->size == 4
    && list1->curr->prev->data == iPtr2 && list1->curr->next->data == iPtr4){
        printf("test4 passed\n");
    }
    else{
        printf("test4 error\n");
    }

    printf("--------------------ListCount() test begin--------------------\n");
    int item5 = 5;
    int * iPtr5 = &item5;

    printf("ListCount Test1: count nodes in an empty list\n");
    if (list2->size == 0){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListCount Test2: count nodes in a non-empty list\n");
    ListAdd(list2, iPtr5);
    // Now, item in list2 should be: 5
    if (list2->size == 1){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("--------------------ListFirst() test begin--------------------\n");
    printf("ListFirst Test1: operate ListFirst() on a non-empty list\n");
    temp_iPtr = ListFirst(list1);
    if (temp_iPtr == iPtr1 && list1->curr->data == iPtr1){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListFirst Test2: operate ListFirst() on an empty list\n");
    temp_iPtr = ListFirst(list3);
    if (temp_iPtr == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("--------------------ListLast() test begin--------------------\n");
    printf("ListLast Test1: operate ListLast() on a non-empty list\n");
    temp_iPtr = ListLast(list1);
    if (temp_iPtr == iPtr4 && list1->curr->data == iPtr4){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListLast Test2: operate ListLast() on an empty list\n");
    temp_iPtr = ListLast(list3);
    if (temp_iPtr == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("--------------------ListNext() test begin--------------------\n");
    printf("ListNext Test1: advance the current item without beyond the end of the list\n");
    ListFirst(list1);
    temp_iPtr = ListNext(list1);
    if (temp_iPtr == iPtr2 && list1->curr->data == iPtr2){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListNext Test2: advance the current item beyond the end of the list\n");
    temp_iPtr = ListNext(list2);
    if (temp_iPtr == NULL && list2->curr->data == iPtr5){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("ListNext Test3: operate ListNext() on an empty list\n");
    temp_iPtr = ListNext(list3);
    if (temp_iPtr == NULL){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("--------------------ListPrev() test begin--------------------\n");
    printf("ListPrev Test1: back up the current item without beyond the start of the list\n");
    temp_iPtr = ListPrev(list1);
    if (temp_iPtr == iPtr1 && list1->curr->data == iPtr1){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListPrev Test2: back up the current item beyond the start of the list\n");
    temp_iPtr = ListPrev(list1);
    if (temp_iPtr == NULL && list1->curr->data == iPtr1){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("ListPrev Test3: operate ListPrev() on an empty list\n");
    temp_iPtr = ListPrev(list3);
    if (temp_iPtr == NULL){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("--------------------ListCurr() test begin--------------------\n");
    printf("ListCurr Test1: operate ListCurr() when the pointer is at the first node of the list\n");
    temp_iPtr = ListCurr(list1);
    if (temp_iPtr == iPtr1 && list1->curr->data == iPtr1){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListCurr Test2: operate ListCurr() when the pointer is at the last node of the list\n");
    ListLast(list1);
    temp_iPtr = ListCurr(list1);
    if (temp_iPtr == iPtr4 && list1->curr->data == iPtr4){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("ListCurr Test3: operate ListCurr() when the pointer is at the middle of the list\n");
    ListPrev(list1);
    temp_iPtr = ListCurr(list1);
    if (temp_iPtr == iPtr3 && list1->curr->data == iPtr3){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("ListCurr Test4: operate ListCurr() on an empty list\n");
    temp_iPtr = ListCurr(list3);
    if (temp_iPtr == NULL){
        printf("test4 passed\n");
    }
    else{
        printf("test4 error\n");
    }

    printf("--------------------ListInsert() test begin--------------------\n");
    printf("ListInsert Test1: insert item in the middle of the list\n");
    int item6 = 6;
    int * iPtr6 = &item6;
    ListInsert(list1, iPtr6);
    // Now, items in list1 should be: 1, 2, 6, 3, 4
    if (list1->first->data == iPtr1 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr6 && list1->size == 5
    && list1->curr->prev->data == iPtr2 && list1->curr->next->data == iPtr3){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListInsert Test2: insert item at the start of the list\n");
    ListFirst(list1);
    int item7 = 7;
    int * iPtr7 = &item7;
    ListInsert(list1, iPtr7);
    // Now, items in list1 should be: 7, 1, 2, 6, 3, 4
    if (list1->first->data == iPtr7 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr7 && list1->size == 6
    && list1->curr->prev == NULL && list1->curr->next->data == iPtr1){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }
    
    printf("ListInsert Test3: insert item to an empty list\n");
    int item8 = 8;
    int * iPtr8 = &item8;
    ListInsert(list3, iPtr8);
    // Now, item in list3 should be: 8
    if (list3->first->data == iPtr8 && list3->last->data == iPtr8 
    && list3->curr->data == iPtr8 && list3->size == 1
    && list3->curr->prev == NULL && list3->curr->next == NULL){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("--------------------ListAppend() test begin--------------------\n");
    printf("ListAppend Test1: append item to a non-empty list\n");
    int item9 = 9;
    int * iPtr9 = &item9;
    ListAppend(list1, iPtr9);
    // Now, items in list1 should be: 7, 1, 2, 6, 3, 4, 9
    if (list1->first->data == iPtr7 && list1->last->data == iPtr9 
    && list1->curr->data == iPtr9 && list1->size == 7
    && list1->curr->prev->data == iPtr4 && list1->curr->next == NULL){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListAppend Test2: append item to an empty list\n");
    int item10 = 10;
    int * iPtr10 = &item10;
    ListAppend(list4, iPtr10);
    // Now, item in list4 should be: 10
    if (list4->first->data == iPtr10 && list4->last->data == iPtr10 
    && list4->curr->data == iPtr10 && list4->size == 1
    && list4->curr->prev == NULL && list4->curr->next == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("--------------------ListPrepend() test begin--------------------\n");
    printf("ListPrepend Test1: preppend item to a non-empty list\n");
    int item11 = 11;
    int * iPtr11 = &item11;
    ListPrepend(list1, iPtr11);
    // Now, items in list1 should be: 11, 7, 1, 2, 6, 3, 4, 9
    if (list1->first->data == iPtr11 && list1->last->data == iPtr9 
    && list1->curr->data == iPtr11 && list1->size == 8
    && list1->curr->prev == NULL && list1->curr->next->data == iPtr7){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }
    
    printf("ListPrepend Test2: preppend item to an empty list\n");
    int item12 = 12;
    int * iPtr12 = &item12;
    ListAppend(list5, iPtr12);
    // Now, item in list5 should be: 12
    if (list5->first->data == iPtr12 && list5->last->data == iPtr12 
    && list5->curr->data == iPtr12 && list5->size == 1
    && list5->curr->prev == NULL && list5->curr->next == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }
    
    printf("--------------------ListRemove() test begin--------------------\n");
    printf("ListRemove Test1: delete when there is only one node in the list\n");
    temp_iPtr = ListRemove(list5);
    // list5 should now be empty
    if (list5->first == NULL && list5->last == NULL 
    && list5->curr == NULL && list5->size == 0 && temp_iPtr == iPtr12){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListRemove Test2: delete from an empty list\n");
    temp_iPtr = ListRemove(list5);
    if (temp_iPtr == NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("ListRemove Test3: delete the last node in the list\n");
    ListLast(list1);
    temp_iPtr = ListRemove(list1);
    // Now, items in list1 should be: 11, 7, 1, 2, 6, 3, 4
    if (list1->first->data == iPtr11 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr4 && list1->size == 7
    && list1->curr->prev->data == iPtr3 && list1->curr->next == NULL
    && temp_iPtr == iPtr9){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("ListRemove Test4: delete the first node in the list\n");
    ListFirst(list1);
    temp_iPtr = ListRemove(list1);
    // Now, items in list1 should be: 7, 1, 2, 6, 3, 4
    if (list1->first->data == iPtr7 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr7 && list1->size == 6
    && list1->curr->prev == NULL && list1->curr->next->data == iPtr1
    && temp_iPtr == iPtr11){
        printf("test4 passed\n");
    }
    else{
        printf("test4 error\n");
    }

    printf("ListRemove Test5: delete node in the middle of the list\n");
    ListNext(list1);
    temp_iPtr = ListRemove(list1);
    // Now, items in list1 should be: 7, 2, 6, 3, 4
    if (list1->first->data == iPtr7 && list1->last->data == iPtr4 
    && list1->curr->data == iPtr2 && list1->size == 5
    && list1->curr->prev->data == iPtr7 && list1->curr->next->data == iPtr6
    && temp_iPtr == iPtr1){
        printf("test5 passed\n");
    }
    else{
        printf("test5 error\n");
    }

    printf("--------------------ListConcat() test begin--------------------\n");
    // right now, items in list1 are: 7, 2, 6, 3, 4
    // item in list2 is 5
    // item in list3 is 8
    // item in list4 is 10
    // list5 is empty

    printf("ListContat Test1: both lists are not empty\n");
    ListConcat(list3, list4);
    // Now, items in list3 should be: 8, 10
    // list4 does not exist anymore. Since we allocated memory for a total of five lists, 
    // a new list should be able to create, call it list6
    list6 = ListCreate();
    if (list3->first->data == iPtr8 && list3->last->data == iPtr10 
    && list3->curr->data == iPtr8 && list3->size == 2 && list6 != NULL){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListContat Test2: list1 is empty but list2 is not empty\n");
    // right now, items in list1 are: 7, 2, 6, 3, 4
    // item in list2 is 5
    // items in list3 are 8, 10
    // list4 does not exist
    // list5 is empty
    // list6 is empty
    ListConcat(list6, list3);
    // Now, items in list6 should be: 8, 10
    // list3 does not exist anymore. Since we allocated memory for a total of five lists, 
    // a new list should be able to create, call it list7
    LIST* list7;
    list7 = ListCreate();
    if (list6->first->data == iPtr8 && list6->last->data == iPtr10 
    && list6->curr->data == iPtr8 && list6->size == 2 && list7 != NULL){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }
    // right now, items in list1 are: 7, 2, 6, 3, 4
    // item in list2 is 5
    // list3 does not exist
    // list4 does not exist
    // list5 is empty
    // items in list6 are 8. 10
    // list7 is empty

    printf("ListContat Test3: list1 is not empty but list2 is empty\n");
    ListConcat(list1, list5);
    // list5 does not exist anymore. Since we allocated memory for a total of five lists, 
    // a new list should be able to create, call it list8
    LIST* list8 = ListCreate();
    if (list1->first->data == iPtr7 && list1->last->data == iPtr4
    && list1->curr->data == iPtr2 && list1->size == 5 && list8 != NULL){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("--------------------ListFree() test begin--------------------\n");
    printf("ListFree Test1: free a list\n");
    // right now, all five lists memory being occupied
    int* itemToBeFree1 = (int*)malloc(sizeof(int));
    int* itemToBeFree2 = (int*)malloc(sizeof(int));

    *itemToBeFree1 = 1;
    *itemToBeFree2 = 2;
    
    ListAdd(list7, itemToBeFree1);
    ListAdd(list7, itemToBeFree2);

    ListFree(list7, itemFree);
    // list7 has been freed, we should be able to create a new list
    // we test if we can create a new list to check if list7 was freed successfully
    LIST* list9 = ListCreate();
    // all five lists memory has been occupied, no new list should be allowed to create
    LIST* list10 = ListCreate();
    if (list7->first == NULL && list7->last == NULL && list7->curr == NULL 
    && list7->size == 0 && list9 != NULL && list10 == NULL){
        printf("test1 passed\n");
    }
    else{
        printf("test1 failed\n");
    }

    printf("--------------------ListTrim() test begin--------------------\n");
    printf("ListTrim Test1: operate ListTrim when there are more than one node in the list\n");
    // items in list1 are: 7, 2, 6, 3, 4
    temp_iPtr = ListTrim(list1);
    // Now, items in list1 should be: 7, 2, 6, 3
    if (list1->first->data == iPtr7 && list1->last->data == iPtr3 
    && list1->curr->data == iPtr3 && list1->size == 4
    && list1->curr->prev->data == iPtr6 && list1->curr->next == NULL
    && temp_iPtr == iPtr4){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListTrim Test2: operate ListTrim when there is only one node in the list\n");
    temp_iPtr = ListTrim(list2);
    if (list2->first == NULL && list2->last == NULL 
    && list2->curr == NULL && list2->size == 0 && temp_iPtr == iPtr5){
        printf("test2 passed\n");
    }
    else{
        printf("test2 error\n");
    }

    printf("ListTrim Test3: operate ListTrim on an empty list\n");
    temp_iPtr = ListTrim(list2);
    if (temp_iPtr == NULL){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }
    // right now, items in list1 are: 7, 2, 6, 3
    // list2 is empty
    // list3 does not exist
    // list4 does not exist
    // list5 does not exist
    // items in list6 are: 8, 10
    // list7 does not exist
    // list8 is empty
    // list9 is empty
    // list10 does not exist

    printf("--------------------ListSearch() test begin--------------------\n");
    printf("ListSearch Test1: Use the comparator matchEqual to find an item\n" 
    "which is equal to comparisonArg. In this case, traver from the first node\n" 
    "and a matching item should be found\n");
    int comparg1 = 6;
    int * compargPtr1 = &comparg1;
    ListFirst(list1);
    temp_iPtr = ListSearch(list1, matchEqual, compargPtr1);
    if (temp_iPtr == iPtr6 && list1->curr->data == iPtr6){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListSearch Test2: Use the comparator matchEqual to find an item\n"
    "which is equal to comparisonArg. In this case, traverse from the first node\n"
    "and there is no matching item in the list\n");
    int comparg2 = 5;
    int * compargPtr2 = &comparg2;
    ListFirst(list1);
    temp_iPtr = ListSearch(list1, matchEqual, compargPtr2);
    if (temp_iPtr == NULL && list1->curr->data == iPtr3){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("ListSearch Test3: Use the comparator matchGreaterThan to find an item\n"
    "which is greater than comparisonArg. In this case, traver from the first node\n"
    "and a matching item should be found\n");
    ListFirst(list1);
    temp_iPtr = ListSearch(list1, matchGreaterThan, compargPtr1);
    if (temp_iPtr == iPtr7 && list1->curr->data == iPtr7){
        printf("test3 passed\n");
    }
    else{
        printf("test3 error\n");
    }

    printf("ListSearch Test4: Use the comparator matchGreaterThan to find an item\n"
    "which is greater than comparisonArg. In this case, traver from the middle of \n"
    "the list and a matching item should not be found\n");
    ListNext(list1);
    temp_iPtr = ListSearch(list1, matchGreaterThan, compargPtr1);
    if (temp_iPtr == NULL && list1->curr->data == iPtr3){
        printf("test4 passed\n");
    }
    else{
        printf("test4 error\n");
    }

    printf("--------------------extra test begin--------------------\n");
    printf("Extra Test1: create a node when there is no free node available\n");
    // right now, items in list1 are: 7, 2, 6, 3
    // list2 is empty
    // list3 does not exist
    // list4 does not exist
    // list5 does not exist
    // items in list6 are: 8, 10
    // list7 does not exist
    // list8 is empty
    // list9 is empty
    // list10 does not exist

    // There are 6 nodes exist. Because we set the maximum number of nodes to be 15, 
    // We should be able to create 9 more nodes.

    int item13 = 13;
    int item14 = 14;
    int item15 = 15;
    int item16 = 16;
    int item17 = 17;
    int item18 = 18;
    int item19 = 19;
    int item20 = 20;
    int item21 = 21;
    int item22 = 22;
    int item23 = 23;
    int item24 = 24;
    int item25 = 25;

    int * iPtr13 = &item13;
    int * iPtr14 = &item14;
    int * iPtr15 = &item15;
    int * iPtr16 = &item16;
    int * iPtr17 = &item17;
    int * iPtr18 = &item18;
    int * iPtr19 = &item19;
    int * iPtr20 = &item20;
    int * iPtr21 = &item21;
    int * iPtr22 = &item22;
    int * iPtr23 = &item23;
    int * iPtr24 = &item24;
    int * iPtr25 = &item25;

    int result1 = ListAdd(list2, iPtr13);
    int result2 = ListAdd(list2, iPtr14);
    int result3 = ListAdd(list2, iPtr15);
    int result4 = ListAdd(list2, iPtr16);
    int result5 = ListAdd(list2, iPtr17);
    int result6 = ListAdd(list2, iPtr18);
    int result7 = ListAdd(list2, iPtr19);
    int result8 = ListAdd(list2, iPtr20);
    int result9 = ListAdd(list2, iPtr21);
    // all nodes memory are full now, the following operations should all return -1 as failure
    int result10 = ListAdd(list2, iPtr22);
    int result11 = ListInsert(list2, iPtr23);
    int result12 = ListAppend(list2, iPtr24);
    int result13 = ListPrepend(list2, iPtr25);

    if(result1 == 0 && result2 == 0 && result3 == 0 && result4 == 0
    && result5 == 0 && result6 == 0 && result7 == 0 && result8 == 0
    && result9 == 0 && result10 == -1 && result11 == -1 && result12 == -1
    && result13 == -1){
        printf("test1 passed\n");
    }
    else{
        printf("test1 error\n");
    }

    printf("All test finished.\n");

    return 0;
}

