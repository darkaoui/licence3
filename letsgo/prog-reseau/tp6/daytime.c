#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>


int main(){
  
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(13);
  inet_aton("129.6.15.28", &address_sock.sin_addr);

  int desc = socket(AF_INET,SOCK_STREAM,0);
  int c = connect(desc,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));

  if(c != -1){
    char buff[1024];
    int size_rec = recv(desc, buff, 1023*(sizeof(char)),0);
    buff[size_rec] = '\0';
    printf("Result %d : %s\n",size_rec,buff);
  }

  return 0;
}
