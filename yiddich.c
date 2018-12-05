#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.>
#include <string.h>

int main(){

  key_t key;
  int shmid;
  char * data;

  key = ftok("file",'a');
  shmid = shmget(key,200,0644|IPC_CREAT);
  data = shmat(shmid,0,0);
  
  printf("Do you want to modify the shared memory? (say y or n)\n");
  scanf(s)
  return 0;
}
