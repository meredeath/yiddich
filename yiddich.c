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
  }else printf("nothing in data; newly created\n");

  char buf[200];
  printf("Do you want to modify the shared memory? (say y or n)\n");
  fgets(buf, 200, stdin);
  if(!strcmp(buf,"y\n")){
    fflush(stdin);
    char newstuff[200];
    printf("what do you want in the memory?\n");
    fgets(newstuff, 200, stdin);
    strcpy(data, newstuff);
    printf("mem successfully modified\n");
  }else if(!strcmp(buf,"n\n")){
    printf("mem not modified\n");
  }else{
    printf("y or n was not entered\n");
  }

  char deletes[5];
  printf("Do you want to delete the segment? (y or n)\n");
  fflush(stdin);
  fgets(deletes, 200, stdin);
  if(!strcmp(deletes,"y\n")){
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    printf("mem successfully deleted\n");
  }else if(!strcmp(deletes,"n\n")){
    printf("mem not deleted\n");
  }else{
    printf("y or n was not entered\n");
  }
  
  return 0;
}
