// Program which accepts file name from user and display size of the file 

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	char Fname[20];
	char Data[100];
	int iSum=0;
	int fd=0;
	int iRet=0;
	
	printf("Enter name of the file \n");
	scanf("%s",&Fname);
	
	fd=open(Fname,O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	printf("File sucessfully created file with FD : %d\n",fd);
	
	while((iRet=read(fd,Data,sizeof(Data)))!=0)
	{
		iSum=iSum+iRet;
	}
	
	printf("The size of file is %d\n",iSum);
	
	close(fd);
	
	return 0;
}