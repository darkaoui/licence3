#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
  
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port   = htons(2222);
  inet_aton("127.0.0.1",&address_sock.sin_addr);

  int sock = socket(AF_INET,SOCK_DGRAM,0);
  
  char temp[1024];

  printf("envoyer: ");
  scanf("%s",temp);
  sendto(sock,temp,strlen(temp),0,(struct sockaddr*)&address_sock,sizeof(address_sock));
  
  //struct sockaddr_in sender;
  //socklen_t a = sizeof(sender);
  char tmp[1024];
  int r= recvfrom(sock,tmp,1023,0,NULL,NULL);
  tmp[r] = '\0';
  printf("recu: %s\n",tmp);
  
}
