// Program which accepts file name and number from user and display first input number of characters 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void DisplayN(char Fname[],int iSize)
{
	int fd=0,iRet=0,iSum=0, i=0;
	char Data[iSize];

	fd=open(Fname,O_RDWR);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return;
	}
	
	iRet=read(fd,Data,sizeof(Data));
	
	write(1,Data,iRet);
	
	
	/*
	while((iRet=read(fd,Data,sizeof(Data)))!=0)
	{
		for(i=0;i<iRet;i++)
		{
			if(Data[i]==' ')
			{
				iSum++;
			}
		}
	}
	*/
	close(fd);

}

int main()
{
	char Fname[20];
	int iValue=0;
	
	printf("Enter the file name to open\n");
	scanf("%s",Fname);
	
	printf("Enter the number of characters \n");
	scanf(" %d",&iValue);
	
	DisplayN(Fname,iValue);
	
	return 0;
}