/*
 *Guandi97
 *stdlib.h recreation
 */

#include <unistd.h>
//debug
#include <stdio.h>

#define stdfun

typedef struct struct_file file;
int sterlen(char*);						//loops until 0x0 is found
int ati(char*);
int memcp(char*,char*,size_t);
int readline(int,char*);
int buffwrite(char*,file*,size_t);
int fsflush(file*);


struct struct_file
{
	int fd;
	size_t index;
	char buff[1024];
};

int sterlen(char *str)
{
	int i=0;
	while(*(str+i)!=0x0) i++;

	return i;
}
int ati(char *str)
{
	int i;
	return i;
}
int memcp(char *source,char *destin,size_t size)
{
	int i;
	for(i=0;i<(size);i++)
	{
		*(destin+i)=*(source+i);
	}
	return i;
}
int readline(int fd,char *destin)
{
	int i,j,c=0;
	char buff[32];

	while(1)
	{
		i=read(fd,buff,32);
		if(i!=32) goto READLINEEND;

		i=0;
		while(buff[i]!=0xa && i!=32) i++;
		if(i>=32)
		{
			memcp(buff,&(*(destin+c)),32);
			c+=32;
		}
	}

	READLINEEND:;
	j=0;
	while(buff[j]!=0xa && j<i) 
	{
		printf("%d %c\n",j,buff[j]);
		j++;
	}
	memcp(buff,&(*(destin+c)),j);
	c+=i;

	return c;
}
int buffwrite(char *source,file *strmout,size_t size)
{
	int i=0,j;

	if((1024-strmout->index)<size) 
	{
		fsflush(strmout);
	}

	if(size>1024)
	{
		j=size;
		while(i<size)
		{
			
			while(j>1024)
			{
				i+=memcp(source,&strmout->buff[strmout->index],1024);
				fsflush(strmout);
				j-=1024;
			}
			if(j==0) return i;
			else i+=memcp(source,&strmout->buff[strmout->index],j);
		}
	}
	else i=memcp(source,&strmout->buff[strmout->index],size);
	return i;
}
int fsflush(file *strmout)
{
	int i=write(strmout->fd,&strmout->buff,strmout->index);
	strmout->index=0;
	return i;
}

