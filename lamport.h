#ifndef __LAMPORT__
#define __LAMPORT__

#define N 3

void lamport_mutex_init();
void lamport_mutex_lock(int thread_id);
void lamport_mutex_unlock(int thread_id);
#endif