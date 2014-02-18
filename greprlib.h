//Guandi97

#include <unistd.h>
//include "stdfun.h"

//int process_flags(int,char**,struct struct_flags*);				//return # of index
int process_regex(); 								//return regex #
int match_regex();								//return index of last reg
int readin();									//return line size
void fubar(char*);

char **regex_list;

/*
int process_flags(int argc,char **argv,struct struct_flags *flags)
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
			if((i+1)!=argc) fubar(usage);
			return i;
		}

		//check if it is argument requiring flag
		switch(argv[i][1])				
		{
			case 'f': 	flags->f=1; 
					i++;
					if(memcp(argv[i],flags->file,sterlen(argv[i]))==-1) fubar("failure: process_flags, memcp()");
					c=open(*flags->file,O_RONLY);
					if(c==-1) fubar("failure: process_flags, open()");
					strm.fd=c;
					goto FLAGFORLOOPEND;
		}

		//check all other flags
		while(argv[i][++j]!=0x20)
		{
			switch(argv[i][j])
			{
				case 'A':	flags->A=1;
						break;
				case 'B':	flags->B=1;	
						break;
				case 'b':	flags->b=1;
						break;
				case 'c':	flags->c=1;
						break;
				case 'H':	flags->H=1;
						break;
				case 'h':	flags->h=1;
						break;
				case 'i':	flags->i=1;
						break;
				case 'm':	flags->o=1;
						break;
				case 'n':	flags->n=1;
						break;
				case 'o':	flags->o=1;
						break;
				case 'q':	flags->q=1;
						break;
				case 'v':	flags->v=1;
						break;
			}
		}
	FLAGFORLOOPEND:;	
	}

	//if hits this, error
	return -1;
}
*/
int process_regex()
{
	//"registers"
	int ax,cx,si,di,dx,l=sterlen(&gegex.expr);
	ax=cx=si=di=dx=0;

	while(cx!=l)
	{
		
	}
	
	return ax;
}
int match_regex()
{
}
int readin()
{
	strm.lNum++;
	return readline(strm.in,&strm.line);
}
void fubar(char *err)
{
	write(1,err,sterlen(err));
	sys_exit(1);
}
