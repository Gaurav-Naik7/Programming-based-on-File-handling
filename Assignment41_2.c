// Program which accepts file name from user and count number of small characters from that file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int countSmall(char Fname[])
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
			if((Data[i]>='a')&&(Data[i]<='z'))
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
	int iRet=0;
	
	printf("Enter the file name to open\n");
	scanf("%s",Fname);
	
	iRet=countSmall(Fname);
	printf("Number of small letters are: %d",iRet);
	
	return 0;
}