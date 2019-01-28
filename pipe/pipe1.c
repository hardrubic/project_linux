#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  int data_processed;
  int file_pipes[2];
  const char some_data[] = "123";
  char buffer[BUFSIZ+1];

  memset(buffer,'\0',sizeof(buffer));

  if(pipe(file_pipes) == 0){
    //向文件描述符[1]写入数据
    data_processed=write(file_pipes[1],some_data,strlen(some_data));
    printf("wrote %d bytes\n",data_processed);

    //在文件描述符[0]读回来数据
    data_processed=read(file_pipes[0],buffer,BUFSIZ);
    printf("read %d bytes\n",data_processed);

    exit(EXIT_SUCCESS);
  }
  exit(EXIT_FAILURE);
}
