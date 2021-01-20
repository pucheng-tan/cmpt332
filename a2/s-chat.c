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
#include <semaphore.h>

#include <standards.h>
#include <os.h>

#include "list.h"

LIST* sendList;
LIST* printList;
sem_t sendMutex;
sem_t printMutex;

int checkNumber(char argv[])
{
   int i;

   for (i = 0; argv[i] ; i++) {
	   if (!isdigit(argv[i])){
		   return 0;
	   }		   
   }
   return 1;
}

void *readKeyboard(void *threadid){
    char input[1024];
    while(1){
        
        fgets(input, sizeof(input),stdin);
        
        printf("Hi! %s\n",input);
        sleep(2);
        
    }
    printf("readKeyboard needs to be completed\n");
    
}

void *receiveUDP(void *threadid){
    printf("receiveUDP needs to be completed\n");
    
}

void *printScreen(void *threadid){
    printf("printScreen needs to be completed\n");
    pthread_exit(NULL);
}

void *sendUDP(void *threadid){
    printf("sendUDP needs to be completed\n");
    pthread_exit(NULL);
}

int main (int argc, char *argv[]){
    pthread_t threads[4];
    if (argc != 4) 
    {
        printf("Usage: ./s-chat port# machine port# \n");
        exit(1);
    }
    if (checkNumber(argv[1]) && checkNumber(argv[3])){
        printf("s-chat program not completed yet.\n");
        sem_init(&sendMutex, 0, 1); 
        sem_init(&printMutex, 0, 1); 

        pthread_create(&threads[0], NULL, readKeyboard, (void *)0);
        /*
        pthread_create(&threads[1], NULL, receiveUDP, (void *)0);
        
        pthread_create(&threads[2], NULL, printScreen, (void *)0);
        pthread_create(&threads[3], NULL, sendUDP, (void *)0);
        */
        sleep(10);


    }else{
        printf("Usage: ./s-chat port# machine port# \n");
        exit(1);
    }
    return 0;
}