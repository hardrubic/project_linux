#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//滥用内存
int main(){
  char *some_memory;
  char *scan_ptr;

  some_memory = (char*)malloc(1024*1024);
  scan_ptr = some_memory;

  while(1){
    *scan_ptr='\0';
    scan_ptr++;
  }
  exit(EXIT_SUCCESS);
}
