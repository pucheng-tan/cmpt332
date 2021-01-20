/* 
#  Name: Ruiqi Gao
#  NSID: rug276
#  Student#: 11199909

#  Name: Pucheng Tan
#  NSID: put178
#  Student#: 11273627
*/

<<<<<<< HEAD
/* declaration:
    I copied my monitor.c file which I handed in with lab4 and tried to 
    modified it for this assignment. However, we did not manage to finish it.
*/
=======
>>>>>>> df03f6339a4a481bbae14c0f440e5454f562fb2c
#include <stdio.h>
#include <stdlib.h>
#include <standards.h>
#include <os.h>

#include "Monitor.h"
#include "list.h"

#define TOTAL_CVS 4

PID serverPid;

typedef struct message{
    int type;
    char content[BUFSIZE];
}

int monBusy;

int* msgLength;

LIST* enterQ;
LIST* urgentQ;

LIST* cvQ[TOTAL_CVS];



void MonInit(){
    int i;

    monBusy = 0;

    msgLength = sizeof(int);

    enterQ = ListCreate();
    urgentQ = ListCreate();

    for (i=0; i<TOTAL_CVS; i++){
        cvQ[i] = ListCreate();
    }

    ServerPid = Create();
}

/* called before a process going to enter the monitor */
void MonEnter(){
    PID pid;

    message msg = malloc(sizeof(message));
    message->type = 

    reply = Send(serverPid, &msg, msgLength);

    // P(mutex);

    if (monBusy){
        pid = MyPid();
        ListPrepend(enterQ, (void*) pid);
    }
    else{
        monBusy = 1;
        send();
}

/* called before a process going to leave the monitor */
void MonLeave(){
    send();

    if (ListCount(urgentQ) != 0){
        ListTrim(urgentQ);
        send();
    }
    else if(ListCount(enterQ) != 0){
        ListTrim(enterQ);
        send();
    }
    else{
        monBusy = 0;
        send();
    }
}

void MonWait(int CV){
    PID pid = MyPid();

    send();

    ListPrepend(cvQ[CV], (void*) pid);
    if (ListCount(urgentQ) != 0){
        ListTrim(urgentQ);
        send();
    }
    else if (ListCount(enterQ) != 0){
        ListTrim(enterQ);
        send();
    }
    else{
        monBusy = 0;
    }
    send();
}

void MonSignal(int CV){
    PID pid = MyPid();
    
    send(ServerPid, )

    if (ListCount(cvQ[CV]) != 0){
        ListTrim(cvQ[CV]);
        ListPrepend(urgentQ, (void*) pid);
        V(mutex);
        V(semaCv[CV]);
        P(semaUrgentQ);
    }
    else{
        V(mutex);
    }
}

void MonServer(){
    for(;;){
        msg = Receive(%senderPid, )

        if(msg->type == 1)
        {

        }
        else if(msg->type == 2)
        {
            
        }
    }
}