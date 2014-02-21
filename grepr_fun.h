//Guandi97

#include <unistd.h>
#include <fcntl.h>

#define grepr_fun
#include "grepr_lib.h"

int parse_flags(int,char**);				//return # of index
int process_regex(); 								//return regex #
int parse_regex();								//return index of last reg
int readin();									//return line size
void uexit(char*);
void fubar(char*);

int parse_flags(int argc,char **argv)
{
	char i,j;
	int c;

	//loop the arguments (start at 1, 0 is ./grepr), if start with -, if arg has parameter, program will infrement automaticly, if no parameter found, error
	for(i=1;i<argc;i++)						
	{
		j=0;

		//make sure starts with -, otherwise check if last arg, if not, error
		if(argv[i][0]!=0x2d) 
		{
			#define USAGE1 "lolz\n"
			if((i+1)!=argc) uexit(USAGE1);
			return i;
		}

		//check if it is argument requiring flag
		switch(argv[i][1])				
		{
			case 'f': 	flags.f=1; 
					i++;
					//sterlen+1 because need to also copy the null
					if(memcp(argv[i],flags.file,(sterlen(argv[i])+1))==-1) fubar("failure: parse_flags: memcp()\n");
					c=open(flags.file,O_RDONLY);
					if(c==-1) fubar("failure: parse_flags: open()\n");
					strm.in->fd=c;
					goto FLAGFORLOOPEND;
		}

		//check all other flags
		while(argv[i][++j]!=0x0)
		{
			switch(argv[i][j])
			{
				case 'A':	flags.A=1;
						break;
				case 'B':	flags.B=1;	
						break;
				case 'b':	flags.b=1;
						break;
				case 'c':	flags.c=1;
						break;
				case 'H':	flags.H=1;
						break;
				case 'h':	flags.h=1;
						break;
				case 'i':	flags.i=1;
						break;
				case 'm':	flags.o=1;
						break;
				case 'n':	flags.n=1;
						break;
				case 'o':	flags.o=1;
						break;
				case 'q':	flags.q=1;
						break;
				case 'v':	flags.v=1;
						break;
				default:	
						#define USAGE2 "undefined flag\n"
						write(1,USAGE2,sizeof(USAGE2));
						uexit(USAGE1);
			}
		}
	FLAGFORLOOPEND:;	
	}

	//if hits this, error
	return -1;
}
int process_regex()
{
	//"registers"
	int ax,cx,si,di,dx,l=sterlen(gegex.expr);
	ax=cx=si=di=dx=0;

	while(cx!=l)
	{
		
	}
	
	return ax;
}
int parse_regex()
{
	return 0;
}
int readin()
{
	strm.lNum++;
	return readline(strm.in->fd,strm.line);
}
void uexit(char *msg)
{
	write(1,msg,sterlen(msg));
	_exit(1);
}
void fubar(char *err)
{
	write(2,err,sterlen(err));
	_exit(2);
}
