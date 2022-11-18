// Program which accepts file name and character from user and counts the frequency of character

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int countWhite(char Fname[],char Ch)
{
	int fd=0,iRet=0,iSum=0, i=0;
	char Data[10];

	fd=open(Fname,O_RDWR);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((iRet=read(fd,Data,sizeof(Data)))!=0)
	{
		for(i=0;i<iRet;i++)
		{
			if(Data[i]==Ch)
			{
				iSum++;
			}
		}
	}
	
	close(fd);
	return iSum;
}

int main()
{
	char Fname[20];
	char cValue='\0';
	int iRet=0;
	
	printf("Enter the file name to open\n");
	scanf("%s",Fname);
	
	printf("Enter the character\n");
	scanf(" %c",&cValue);
	
	iRet=countWhite(Fname,cValue);
	printf("Frequency is %d",iRet);
	
	return 0;
}