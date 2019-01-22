#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

//使用AF_UNIX
int main(int argc, char const *argv[]) {
  int sockfd;
  int len;
  //域的格式，定义在un.h
  //对于AF_INET域，使用in.h/sockaddr_in
  struct sockaddr_un address;
  int result;
  char ch = 'A';

//socek函数，参数就是域名、类型、协议，返回描述符
  sockfd=socket(AF_UNIX,SOCK_STREAM,0);

  address.sun_family = AF_UNIX;
  strcpy(address.sun_path,"server_socket");
  len = sizeof(address);

  result = connect(sockfd,(struct sockaddr *)&address,len);

  if(result == -1){
    perror("error:clinet1");
    exit(1);
  }

  write(sockfd,&ch,1);
  read(sockfd,&ch,1);
  printf("from server %c\n", ch);
  close(sockfd);
  exit(0);
}
