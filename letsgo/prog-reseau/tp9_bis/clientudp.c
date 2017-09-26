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

  int idfork = fork();

  if(idfork == 0){

    while(1){
      char tmp[1024];
      int r= recvfrom(sock,tmp,1023,0,NULL,NULL);
      tmp[r] = '\0';
      printf("recu: %s\n",tmp);
    }
    
  }else{

    char temp[1024];
    printf("envoyer des messages a tout moment:\n");
    while(1){
      //scanf("%s\n",temp);
      fgets(temp,1024,stdin);
      temp[strlen(temp)-1] = '\0'; //pour eliminer \n 
      sendto(sock,temp,strlen(temp),0,(struct sockaddr*)&address_sock,sizeof(address_sock));
    }
    
  }
  
  //struct sockaddr_in sender;
  //socklen_t a = sizeof(sender);
}
