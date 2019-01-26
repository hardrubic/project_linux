#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//空指针
int main(){
  char *some_memory = (char*)0;

  printf("Read from null %s\n",some_memory );
  sprintf(some_memory,"write to null\n");
  exit(EXIT_SUCCESS);
}
