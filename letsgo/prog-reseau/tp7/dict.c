#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  char *ch ;

  if(argc == 2)
    ch = argv[1];
  else{
    printf("Argument non valide\n");
    exit(errno);
  }

  //regler la resolution
  struct hostent *host = gethostbyname("www.dict.org");
  struct in_addr ** in_address = (struct in_addr**)host->h_addr_list;
  char* address =  inet_ntoa(**in_address);

  if(address == NULL){
    printf("Address non valide\n");
    exit(errno);
  }

  struct sockaddr_in address_sock;
  address_sock.sin_family = AF_INET;
  address_sock.sin_port   = htons(2628);
  inet_aton(address,&address_sock.sin_addr);

  printf("Address p1 %s\n",address);

  int sock = socket(AF_INET,SOCK_STREAM,0);
  int r = connect(sock,(struct sockaddr *)&address_sock,sizeof(struct sockaddr_in));

  if(r == -1){
    printf("Echec de connection\n");
    exit(errno);
  }

  printf("J'envoi klk chose\n");
  char buf[10] = "hello";
  buf[5] = '\r';
  buf[6] = '\n';
  buf[7] = '\0';
  send(sock,buf,7*sizeof(char),0);
  printf("J'ai envoyer qlq");
  
  char buff[1024];
  r = read(sock,buff,1023*sizeof(char));
  buff[r] = '\0';
  printf("%s",buff);

  if(buff[r-2] == '\r' && buff[r-1] == '\n')
    printf("Bien jouer");

  write(sock,"D * hello\r\n", strlen("D * hello\r\n"));

  r = read(sock,buff,1023*sizeof(char));
  buff[r] = '\0';
  printf("%s",buff);

  printf("ADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n");

  do{
    r = read(sock,buff,1023*sizeof(char));
    buff[r] = '\0';
    printf("%s",buff);
    if(buff[r-2] == '\r' && buff[r-1] == '\n')
      printf("ADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
  }while( buff[r-2] != '\r' || buff[r-1] != '\n' );

  do{
    r = read(sock,buff,1023*sizeof(char));
    buff[r] = '\0';
    printf("%s",buff);
    if(buff[r-2] == '\r' && buff[r-1] == '\n')
      printf("ADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
  }while( buff[r-2] != '\r' || buff[r-1] != '\n' );

  
  printf("A bientot\n");
  return 0;
}
