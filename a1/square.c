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

#include "Square.h"

extern int* countCall;

int Square(int N){	
	int threadID = GetID();
	countCall[threadID]++;
	if(N == 0){
		return 0;
	}
	else{
		return Square(N-1) + N + N - 1;
	}
}

