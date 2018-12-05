#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

int main(){

  key_t key;
  int shmid;
  char * data;

  key = ftok("file",'R');
  shmid = shmget(key, 200, 0644 | IPC_CREAT);
  data = shmat(shmid, (void *)0, 0);
  if(data == (char *)(-1)) perror("shmat");

  if(*data){
    printf("current contents: %s\n", data);
  }else printf("nothing in data; newly created");

  char buf[200];
  printf("Do you want to modify the shared memory? (say y or n)\n");
  fgets(buf, 200, stdin);
  strcpy(data, buf);
  
  return 0;
}
