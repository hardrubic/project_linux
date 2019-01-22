#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//使用AF_INET
int main(int argc, char const *argv[]) {
  int sockfd;
  int len;
  struct sockaddr_in address;
  int result;
  char ch = 'A';

//socek函数，参数就是域名、类型、协议，返回描述符
  sockfd=socket(AF_INET,SOCK_STREAM,0);

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = 9734;
  len = sizeof(address);

  result = connect(sockfd,(struct sockaddr *)&address,len);

  if(result == -1){
    perror("error:clinet");
    exit(1);
  }

  write(sockfd,&ch,1);
  read(sockfd,&ch,1);
  printf("from server %c\n", ch);
  close(sockfd);
  exit(0);
}
