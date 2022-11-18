// Program which accepts file name from user and open that file in read mode

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	char Fname[20];
	int fd=0;
	
	printf("Enter name of the file \n");
	scanf("%s",&Fname);
	
	fd=open(Fname,O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file");
		return -1;
	}
	
	printf("File sucessfully open file with FD : %d",fd);
	
	close(fd);
	
	return 0;
}