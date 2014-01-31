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
int buffwrite(file *strmout)
{
}
