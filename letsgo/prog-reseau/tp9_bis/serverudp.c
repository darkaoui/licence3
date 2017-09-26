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
  address_sock.sin_addr.s_addr = htonl(INADDR_ANY);

  int sock = socket(AF_INET,SOCK_DGRAM,0);
  bind(sock,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));

  struct sockaddr_in senders[120]; //we limit in 120 client
  int size_senders =0;
  
  socklen_t a = sizeof(struct sockaddr_in);

  printf("server start...\n");
    
  while(1){
    
    char temp[1024];
    struct sockaddr_in sender;
    int r= recvfrom(sock,temp,1023,0,(struct sockaddr*)&sender,&a);
    temp[r] = '\0';
    printf("%s:%d %s\n",inet_ntoa(sender.sin_addr),ntohs(sender.sin_port),temp);
    
    int find =0;

    for(int i=0; i<size_senders; i++){
      if(ntohs(sender.sin_port) == ntohs(senders[i].sin_port) &&
	       strcmp(inet_ntoa(sender.sin_addr), inet_ntoa(senders[i].sin_addr)) == 0 ){
	find =1;
	break;
      }
    }

    if(find == 0){
      
      if(size_senders == 0){
	size_senders++;
	senders[size_senders-1] = sender;
      }else{
	size_senders++;
	senders[size_senders-1] = sender;
      }
      
    }

    for(int i=0; i<size_senders;i++){
      struct sockaddr_in send = senders[i];
      sendto(sock,temp,strlen(temp),0,(struct sockaddr*)&send,a);
    }
    
  }
  
}
