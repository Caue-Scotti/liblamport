#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#include "lamport.h"

/* Variaveis compartilhadas */

int choosing [N];
int ticket [N];

int max_ticket() {
  int i, max = ticket[0];
  for (i = 1; i < N; i++)
    max = ticket[i] > max ? ticket[i] : max;
}

void lamport_mutex_init(){
    for(int i = 0; i<N; i++){
      choosing[i] = 0;
      ticket[i] = 0;
    }
}


void lamport_mutex_lock(int thread_num){
    choosing[thread_num] = 1;
    ticket[thread_num] = max_ticket () + 1;
    choosing[thread_num] = 0;
    
    for (int j = 0; j < N; j++) {
        while (choosing[j]) /* nao fazer nada */;
	    while (ticket[j] != 0 && (
			(ticket[j] < ticket[thread_num]) || (ticket[j] == ticket[thread_num] && j < thread_num)
		)) /* nao fazer nada */;    
    }
}

void lamport_mutex_unlock(int thread_num){
    ticket[thread_num] = 0;
}