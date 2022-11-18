// Program which accepts file name from user and create that file 

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	char Fname[20];
	int fd=0;
	
	printf("Enter name of the file \n");
	scanf("%s",&Fname);
	
	fd=creat(Fname,0777);
	if(fd==-1)
	{
		printf("Unable to create file");
		return -1;
	}
	
	printf("File sucessfully created file with FD : %d",fd);
	
	close(fd);
	
	return 0;
}