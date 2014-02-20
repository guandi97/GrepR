/*
 *Guandi97
 *stdlib.h recreation
 */

#include <unistd.h>

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
	int i;
	return i;
}
int buffwrite(char *source,file *strmout,size_t size)
{
	if((1024-strmout->index)<size) 
	{
		fsflush(strmout);
	}
	return memcp(source,&strmout->buff[strmout->index],size);
}
int fsflush(file *strmout)
{
	int i=write(strmout->fd,&strmout->buff,strmout->index);
	strmout->index=0;
	return i;
}

