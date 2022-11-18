// Program which accepts file name from user and one string from the user. Write the string at the end of file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char Fname[20];
	char Data[100];
	int fd=0;
	int iRet=0;
	
	printf("Enter name of the file \n");
	scanf("%s",&Fname);
	
	fd=open(Fname,O_RDWR | O_APPEND);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	printf("Enter the data that you want to append: \n");
	scanf(" %[^\n]s",Data);
	
	iRet=write(fd,Data,strlen(Data));
	
	printf("%d bytes gets succesfully written in the file\n",iRet);
	
	close(fd);
	
	return 0;
}