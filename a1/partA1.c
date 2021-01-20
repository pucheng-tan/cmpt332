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
    return MyPid()-2;
}

PROCESS childThread(void *param)
{
    PID idx;
    int i, *number, result, completedSquare;
    number = (int * ) param;
    clock_t beginTime, endTime;
    double timeElapsed;
    idx = MyPid() - 2; 
    beginTime = clock();
    completedSquare = *number * *number;
    
    for (i = 1; i < *number + 1; i++) {       
        result = Square(i);
        if (result == completedSquare ){
            incompleted --;
            threadStats[idx] -> completed = true;            
        }
        endTime = clock();
        timeElapsed = (double) (endTime - beginTime) / CLOCKS_PER_SEC;
        threadStats[idx] -> timeElapsed = timeElapsed;         

    }  
}

PROCESS parentThread(void *param){

    int i;
    for (i = 0; i < numThreads; i++) {
        if(!(threadStats[i] = (struct threadStat *)Malloc(sizeof(struct threadStat)))){
        perror("Malloc");
        }
        threadStats[i] -> threadId = i;
        threadStats[i] -> timeElapsed = 0;
        Create( (void(*)()) childThread,900000000000, "child", (void *) &numSquares,
		   NORM, USR );
    } 
    
    Sleep(deadline);
    for (i = 0; i < numThreads; i++) {
        Kill(i+1);
        if (threadStats[i] -> completed == false){
            printf("Child failed to complete computation, made %d recursive calls using %fs.\n", countCall[i], threadStats[i] -> timeElapsed);
        }        
    }
    printf("%d of child threads were incompleted.\n", incompleted);    
}

void mainp(int argc, char** argv)
{ 
    int i;

    if (argc != 4) 
    {
        printf("Usage: ./partA1 numThreads deadline numSquares\n");
        exit(1);
    }
    if (checkNumber(argv[1]) && checkNumber(argv[2]) &&checkNumber(argv[3]))
    {
        numThreads = atoi(argv[1]);
        deadline = atoi(argv[2]);
        numSquares = atoi(argv[3]);
        incompleted = numThreads;

        countCall = (int*)Malloc(sizeof(int) * numThreads);
        for(i = 0; i< numThreads; i++)
        {
            countCall[i] = 0;
        }
        threadStats = (struct threadStat**)Malloc(sizeof(struct threadStat*) * numThreads);
    
        Create( (void(*)()) parentThread,900000000000, "parent", (void *) 1,
		    HIGH, USR );
    }
    else
    {
        printf("The arguments must be positive integers, please enter valid inputs.\n");
    }
}
