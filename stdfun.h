/*
 *Guandi97
 *stdlib.h recreation
 */

#include <unistd.h>
#include <math.h>
//debug
#include <stdio.h>

#define stdfun

typedef struct struct_file file;
int sterlen(char*,char);						//loops until delim is found
int ati(char*);
int ungReadi(int,char*,size_t);
int memcp(char*,char*,size_t);
int readup(int,char*,char);
int buffwrite(char*,file*,size_t);
int fsflush(file*);


struct struct_file
{
	int fd;
	size_t index;
	char buff[1024];
};

int sterlen(char *str,char delim)
{
	int i=0;
	while(*(str+i)!=delim) i++;

	return i;
}
int ati(char *str)
{
	int i,j=0;
	const int k=sterlen(str,0x0)-1;
	int l=k;
	{
		for(i=0;i<k;i++)
		{
			l--;
			switch(*(str+i))
			{
				case '1': j+=(pow(10,l)*1); break;
				case '2': j+=(pow(10,l)*2); break;
				case '3': j+=(pow(10,l)*3); break;
				case '4': j+=(pow(10,l)*4); break;
				case '5': j+=(pow(10,l)*5); break;
				case '6': j+=(pow(10,l)*6); break;
				case '7': j+=(pow(10,l)*7); break;
				case '8': j+=(pow(10,l)*8); break;
				case '9': j+=(pow(10,l)*9); break;
			}
		}
	}
	return j;
}
int ungReadi(int fd,char *buff,size_t size)
{
	#define UNGREADIBUFF 64
	char dump[UNGREADIBUFF];
	int i=read(fd,buff,size);
	if(i<size) return i;
	else 
	{
		printf("lolz\n");
		if(buff[i-1]!=0xa) while(read(fd,dump,UNGREADIBUFF)>=UNGREADIBUFF);
	}

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
int readup(int fd,char *destin,char delim)
{
	#define READUPBUFF 64
	int i,j,c=0;
	char buff[READUPBUFF];

	while(1)
	{
		i=read(fd,buff,READUPBUFF);
		if(i!=READUPBUFF) goto READLINEEND;

		i=0;
		while(buff[i]!=delim && i!=READUPBUFF) i++;
		if(i>=32)
		{
			memcp(buff,&(*(destin+c)),READUPBUFF);
			c+=READUPBUFF;
		}
	}

	READLINEEND:;
	j=0;
	while(buff[j]!=delim && j<i) 
	{
		j++;
	}
	memcp(buff,&(*(destin+c)),j);
	c+=j;

	return c;
}
int buffwrite(char *source,file *strmout,size_t size)
{
	int i;

	if((1024-strmout->index)<size) 
	{
		fsflush(strmout);
	}

	i=memcp(source,&strmout->buff[strmout->index],size);
	size+=i;
	return i;
}
int fsflush(file *strmout)
{
	int i=write(strmout->fd,&strmout->buff,strmout->index);
	strmout->index=0;
	return i;
}

