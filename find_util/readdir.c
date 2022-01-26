/*
 * This program shows how to list all the files in a directory.
 * You can follow the routine, but the code may not work prefectly.
 *
 * Input: ./reddir testdir
 * Output: print all the files
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
char * full_path;


void read_sub(char* sub_dir)
{
  DIR *sub_dp=opendir(sub_dir);
  struct dirent * sub_dirp;

  if(sub_dp!=NULL)
    {
       while((sub_dirp=readdir(sub_dp))!=NULL)
        {
         printf("%s\n",sub_dirp->d_name);
         //if(stat(sub_dirp->d_name,&buf)==0)
         //printf("%d ", (int)buf.st_size);
	 char * temp =sub_dirp->d_name;
         char temp1[]=".";
	 char temp2[]="..";

        if(strcmp(temp,temp1)!=0&&strcmp(temp,temp2)!=0)//recurcively loop into the sub-directory
        {
	char temp3[]="/";
	char *temp_sub=temp3;
	temp_sub=strcat(temp_sub,temp);
	char * temp_full_path=malloc(sizeof(char)*2000);
	temp_full_path=strcpy(temp_full_path,sub_dir);
	strcat(temp_full_path,temp_sub);
 	DIR * subsubdp=opendir(temp_full_path);
	if(subsubdp!=NULL){
	closedir(subsubdp);
        read_sub(temp_full_path);
        }
        }
        }
       closedir(sub_dp);
    }
    else
    {
        printf("cannot open directory\n");
        exit(2);
    }

}

int main(int argc, char **argv)
{
    char * dir;
    if(argc <2)
    {
	dir=".";
    }
    else
    {
	dir=argv[1];	
    }
    read_sub(dir);

    exit(0);
}


