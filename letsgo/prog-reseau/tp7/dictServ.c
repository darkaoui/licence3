#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

int main(){
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port   = htons(2222);
  inet_aton("127.0.0.1",&address_sock.sin_addr);

  int sock = socket(AF_INET,SOCK_STREAM,0);
  int r = bind(sock,(struct sockaddr *)&address_sock, sizeof(struct sockaddr_in));

  if(r == -1){
    printf("erreur de binding");
    exit(errno);
  }

  listen(sock,0);
  struct sockaddr_in caller;
  socklen_t size = sizeof(caller);
  int sock2 = accept(sock,(struct sockaddr *)&caller,&size);

  do{
    char buff[1024];
    r = read(sock2,buff,1022*sizeof(char));
    buff[r]   = '\r';
    buff[r+1] = '\n';
    
  }while(1);
  
}
