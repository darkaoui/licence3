#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(){
  
  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port = htons(2222);
  address_sock.sin_addr.s_addr = htonl(INADDR_ANY);
  //inet_aton("127.0.0.1", &address_sock.sin_addr);

  int sock = socket(AF_INET,SOCK_STREAM,0);
  int r = bind(sock,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));

  if(r == -1){
    printf("Erreur de binding");
    exit(errno);
  }

  listen(sock,0);
  struct sockaddr_in caller;
  socklen_t size = sizeof(caller);
  int sock2 = accept(sock,(struct sockaddr *)&caller,&size);

  char buff[1024];
  int size_rec = recv(sock2,buff,1023*(sizeof(char)),0);
  buff[size_rec] = '\0';

  printf("msg recu :%s",buff);

  usleep(5000*1000);

  close(sock2);
  close(sock);

  char address[20];
  char port[10];
  
  strcpy(address,strtok(buff," "));
  strcpy(port, strtok(NULL," "));
  
  sock = socket(AF_INET,SOCK_STREAM,0);
  
  address_sock.sin_port = htons(atoi(port));
  inet_aton(address,&address_sock.sin_addr);

  printf("connection sur: &%s&&%d&\n",address,atoi(port));

  r = connect(sock,(struct sockaddr *)&address_sock,(socklen_t)sizeof(struct sockaddr_in));

  if(r == -1){
    printf("erreur connection");
    exit(errno);
  }

  char * msg = "CONFIRM\n";
  send(sock,msg,strlen(msg),0);

  char ms[1024];
  int recu = recv(sock,ms,1023*sizeof(char),0);
  ms[recu] = '\0';

  while(strcmp("ACKCONFIRM\n",ms) != 0){
    int recu = recv(sock,ms,1023*sizeof(char),0);
    ms[recu] = '\0';
  }

  printf("message recu: %s\nA bientot",ms);

  return 0;
}
