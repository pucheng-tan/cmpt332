/* 
#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#include <pthread.h>

#include <standards.h>
#include <os.h>

#include "Square.h"

struct threadStat{
    int threadId;
    bool completed;
    double timeElapsed;
};

int numThreads, deadline, numSquares, incompleted;
int *countCall;

struct threadStat **threadStats;

pthread_t *threads;



int checkNumber(char argv[])
{
   int i;
   if (argv[0] == 48){
       return 0;
   }
   for (i = 0; argv[i] ; i++) {
	   if (!isdigit(argv[i])){
		   return 0;
	   }		   
   }
   return 1;
}

int GetID(){
    int i;
    for(i = 0; i < numThreads; i++ ){
        if(threadStats[i] -> threadId == pthread_self()){
            return i;
        }
    }
    return 0;
}

void *childThread(void *threadid){
    int idx;
    int i, result, completedSquare;
    idx = (int)threadid; 
    clock_t beginTime, endTime;
    double timeElapsed;
    completedSquare = numSquares * numSquares;
    beginTime = clock();
    
    threadStats[idx] -> threadId = pthread_self();
    
    for (i = 1; i < numSquares + 1; i++) {  
        result = Square(i);
        if (result == completedSquare ){
            incompleted --;
            threadStats[idx] -> completed = true;            
        }
        endTime = clock();
        timeElapsed = (double) (endTime - beginTime) / CLOCKS_PER_SEC;
        threadStats[idx] -> timeElapsed = timeElapsed; 
    }  
    
    pthread_exit(NULL);
}

void *parentThread(void *threadid)
 {
    int i;
    pthread_attr_t attr;
    pthread_attr_init(&attr); 
    pthread_attr_setstacksize(&attr, 90000000);
    for (i = 0; i < numThreads; i++) {
        if(!(threadStats[i] = (struct threadStat *)malloc(sizeof(struct threadStat)))){
        perror("malloc");
        }
        threadStats[i] -> threadId = i;
        threadStats[i] -> timeElapsed = 0;
        pthread_create(&threads[i+1], &attr, childThread, (void *)i);
    }
    sleep(deadline);
    for (i = 1; i < numThreads+1; i++) {
        pthread_cancel(threads[i]);
        if (threadStats[i-1] -> completed == false){
            printf("Child failed to complete computation, made %d recursive calls using %fs.\n", countCall[i-1], threadStats[i-1] -> timeElapsed);
        } 
    }
    printf("%d of child threads were incompleted.\n", incompleted);   
    
    pthread_exit(NULL);
 }
 int main (int argc, char *argv[])
{
    
    int parent;
    int i;
    pthread_attr_t attr;
    if (argc != 4) 
    {
        printf("Usage: ./partA2 numThreads deadline numSquares\n");
        exit(1);
    }
    if (checkNumber(argv[1]) && checkNumber(argv[2]) &&checkNumber(argv[3]))
    {
        
        numThreads = atoi(argv[1]);
        deadline = atoi(argv[2]);
        numSquares = atoi(argv[3]);
        incompleted = numThreads;

        threads = (pthread_t*)malloc(sizeof(pthread_t) * (numThreads+1));
        pthread_attr_init(&attr); 
        pthread_attr_setstacksize(&attr, 90000000);
        
        countCall = (int*)malloc(sizeof(int) * (numThreads+1));
        for(i = 0; i< numThreads; i++)
        {
            countCall[i] = 0;
        }
        threadStats = (struct threadStat**)malloc(sizeof(struct threadStat*) * numThreads);
        
        parent = pthread_create(&threads[0], &attr, parentThread, (void *)0);
        if (parent){
            printf("ERROR; return code from pthread_create() is %d\n", parent);
            exit(-1);

        }
    }
    else
    {
        printf("The arguments must be positive integers, please enter valid inputs.\n");
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}