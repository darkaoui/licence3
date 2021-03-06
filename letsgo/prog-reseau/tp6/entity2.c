#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

int main(){

  char * address = "127.0.0.1";
  char * port    = "2221";

  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port   = htons(2222);
  inet_aton("127.0.0.1",&address_sock.sin_addr);
  
  int sock = socket(AF_INET,SOCK_STREAM,0);
  int r = connect(sock,(struct sockaddr *)&address_sock,(socklen_t)sizeof(struct sockaddr_in));

  if(r == -1){
    printf("Erreur de connection 1");
    exit(errno);
  }

  //je devrais utiliser les variables address et port
  char buff[1024] = "127.0.0.1 2221\n";
  send(sock,buff,strlen(buff),0);
  printf("message envoyer: %s",buff);

  struct sockaddr_in address_sock2;
  address_sock2.sin_family = AF_INET;
  address_sock2.sin_port   = htons(2221);
  address_sock2.sin_addr.s_addr = htonl(INADDR_ANY);
  //inet_aton(address,&address_sock2.sin_addr);

  int sock2 = socket(AF_INET,SOCK_STREAM,0);
  r = bind(sock2,(struct sockaddr *)&address_sock2,sizeof(struct sockaddr_in));

  printf("Attachement\n");

  //close(sock);

  if(r == -1){
    printf("Erreur de binding\n");
    exit(errno);
  }
  
  listen(sock2,0);
  printf("Ecoute\n");
  struct sockaddr_in caller;
  socklen_t size = sizeof(caller);
  int sock3 = accept(sock2,(struct sockaddr*)&caller,&size);

  int size_r = recv(sock3,buff,1023*sizeof(char),0);
  buff[size_r] = '\0';

  while(strcmp("CONFIRM\n",buff) != 0){
    size_r = recv(sock3,buff,1023*sizeof(char),0);
    buff[size_r] = '\0';
  }

  char buff_s[100] = "ACKCONFIRM\n";
  send(sock3,buff_s,strlen(buff_s),0);
  printf("message envoyer: %sA bientot",buff_s);
  
  return 0;
}
