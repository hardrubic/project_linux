#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  char *some_memory;
  int exit_code = EXIT_FAILURE;

  some_memory = (char*)malloc(1024*1024);
  if(some_memory != NULL){
    sprintf(some_memory,"hello world\n");
    printf("%s",some_memory);
    exit_code = EXIT_SUCCESS;
  }
  exit(exit_code);
}
