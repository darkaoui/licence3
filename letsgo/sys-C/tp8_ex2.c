#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

const int  DIRECTORY_LENGTH = 1024;


void pendir(char *dir){
  DIR *d = opendir(dir);
  if(d == NULL){
    perror("Echec d'ouverture de dossier");
  }else
    closedir(d);
}

void readdirectoryfile(const char *link, const char *like){
  DIR* dir = opendir(link);
  
  if(dir == NULL){
    perror("Echec ouverture de dossier\n");
  }

  struct dirent* d;
  while( (d = readdir(dir)) != NULL ){

    if(strcmp(d->d_name,".") == 0 || strcmp(d->d_name, "..") == 0)
      continue;

    if(d->d_type == DT_DIR){
      char ln[1024];
      sprintf(ln,"%s/%s",link,d->d_name);
      readdirectoryfile(ln,like);
    }

    if(strstr(d->d_name,like) != NULL && d->d_type == DT_REG ){
      printf("%s/%s\n",link,d->d_name);
    }


    // voir si on a pas un lien symbolik
    
    //if(strcmp(d->d_name,".") != 0 && strcmp(d->d_name, "..") != 0){
      char ln[1024];
      char buf[1024];
      sprintf(ln,"%s/%s",link,d->d_name);
    
      struct stat sb;
      if(stat(ln,&sb) == 0 && S_ISDIR(sb.st_mode)){
	printf("rep symbolic link: %s\n",ln);
      }

      int size;
      if( (size = readlink(ln,buf,1023)) != -1 ){
	buf[size] = '\0';
	printf("link: %s-> %s\n",ln,buf);
      }

      //}
      
  }
}

int main(int argc, char *argv[]){

  if(argc<2){
    fprintf(stderr,"les parametres pose problemes\n");
    return -1;
  }
  
  char *str = argv[1];
  char *rep;
  char ch[DIRECTORY_LENGTH];

  if(argc == 3)
    rep = argv[2];
  else{
    getcwd(ch,DIRECTORY_LENGTH);
    rep = ch;
  }

  readdirectoryfile(rep,str);

  //printf("\nlien\n");

  //readdirectorylink(rep,str);
  
}
