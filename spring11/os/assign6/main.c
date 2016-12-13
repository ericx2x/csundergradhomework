/***********************************************/
/* Eric Lima                                   */
/*                                             */
/* Assignment 6                                */
/*                                             */
/* Monday, May 09, 2011                        */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include <dirent.h>

void print_details(struct stat);

int main(int argc, char *argv[]){

  struct stat stat_buf;
  int i, j;
  DIR *dirptr;
  struct dirent *entptr;

  if(argc > 1){
    for(i = 1; i < argc; i++){
      if(lstat(argv[i], &stat_buf) == -1){
	printf("Bad file name to lstat\n");
	exit(1);
      }
      printf("FILENAME: \t\t\t%s\n", argv[i]);
      print_details(stat_buf);
    }
  }else{
    if((dirptr = opendir(".")) == NULL){
      printf("opendir() failed\n");
      exit(1);
    }
    while((entptr = readdir(dirptr)) != NULL){
      if(lstat(entptr->d_name, &stat_buf) == -1){
	printf("lstat failed\n");
	exit(1);
      }
      printf("FILENAME: \t\t\t%s\n", entptr->d_name);
      print_details(stat_buf);
    }
  }
}

void print_details(struct stat stat_buf){

  char prot_buf[10];
  struct passwd *pwptr;
  struct group *grptr;
  int j;

  prot_buf[9] = '\0';
  if(S_ISDIR(stat_buf.st_mode)) printf("FILE_TYPE: directory\n");
  if(S_ISREG(stat_buf.st_mode)) printf("FILE_TYPE: ordinary\n");
  if(S_ISCHR(stat_buf.st_mode)) printf("FILE_TYPE: char\n");
  if(S_ISBLK(stat_buf.st_mode)) printf("FILE_TYPE: block\n");
  if(S_ISFIFO(stat_buf.st_mode)) printf("FILE_TYPE: pipe\n");
  if(S_ISSOCK(stat_buf.st_mode)) printf("FILE_TYPE: socket\n");
  if(S_ISLNK(stat_buf.st_mode)) printf("FILE_TYPE: link\n");
  for(j = 0; j < 9; j++) prot_buf[j] = '-';
  if(stat_buf.st_mode & S_IRUSR) prot_buf[0] = 'r';
  if(stat_buf.st_mode & S_IWUSR) prot_buf[1] = 'w';
  if(stat_buf.st_mode & S_IXUSR) prot_buf[2] = 'x';
  if(stat_buf.st_mode & S_IRGRP) prot_buf[3] = 'r';
  if(stat_buf.st_mode & S_IWGRP) prot_buf[4] = 'w';
  if(stat_buf.st_mode & S_IXGRP) prot_buf[5] = 'x';
  if(stat_buf.st_mode & S_IWOTH) prot_buf[6] = 'r';
  if(stat_buf.st_mode & S_IROTH) prot_buf[7] = 'w';
  if(stat_buf.st_mode & S_IXOTH) prot_buf[8] = 'x';
  printf("PERMISSIONS: %s\n", prot_buf);
  if((pwptr = getpwuid(stat_buf.st_uid)) == NULL){
    printf("OWNER NAME %d\n", stat_buf.st_uid);
  }else{
    printf("OWNER NAME %s\n", pwptr->pw_name);
  }
  if((grptr = getgrgid(stat_buf.st_gid)) == NULL){
    printf("GROUP_NAME %d\n", stat_buf.st_gid);
  }else{
    printf("GROUP_NAME %s\n", grptr->gr_name);
  }
  printf("DATE_OF_LAST MOD: %s", ctime(&(stat_buf.st_mtime)));
  printf("LINK_COUNT: %d\n", stat_buf.st_nlink);
  if((S_ISCHR(stat_buf.st_mode)) || S_ISBLK(stat_buf.st_mode)){
    printf("MAJOR, MINOR: %d, %d\n", major(stat_buf.st_rdev), minor(stat_buf.st_rdev));
  }else{
    printf("FILE SIZE: %d\n", stat_buf.st_size);
    printf("INODE_NUMBER: %d\n\n", stat_buf.st_ino);
  }
  return;
}
	 
