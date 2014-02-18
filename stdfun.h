/*
 *Guandi97
 *stdlib.h recreation
 */

#include <unistd.h>

struct struct_file;

int sterlen(char*);						//loops until 0x0 is found
int ati(char*);
int memcp(char*,char*,size_t);
int readline(int,char*);
int buffwrite(file*);
int fsflush(file*);

struct struct_file
{
	int fd;
	size_t index;
	char buff[1024];
}file;

int sterlen(char *str)
{
	i=0;
	while(*(char+i)!=0x0) i++;

	return i;
}
int ati(char *str)
{
	
}
int memcp(char *data,char *target,size_t size)
{
	for(int i=size;i!=0;i--)
	{
		*(target+i)=*(data+i);
	}
	return size;
}
int readline(int fd,char *buff)
{
}
int buffwrite(char *source,file *strmout,short size)
{
	if((strmout.index-size)<0) 
	{
		fsflush(*strmout);
	}
	return memcp(*source,&strmout.buff[strmout.index],size);
}
int fsflush(file *strmout)
{
	int i=write(strmout.fd,&strmout.buff,strmout.index);
	strmout.index=0;
	return i;
}

