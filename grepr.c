/*
 GREP recreation
 grep takes command line regular expression and proccesses stdin
 */
#include <unistd.h>

//include either one
//include "asmfun.h" 
#include "stdfun.h"

#define usage "grepr - a recreation of grep"

struct struct_regex;
struct struct_input;
struct struct_flags;

void fubar(char);
int process_flags(int,char**,struct struct_flags*);
int process_regex();
int match_regex();
int readin();

struct struct_regex
{
	int mode, num;
	size_t index;
	char *expr,*line;
}regex={0};
struct struct_strm
{
	int fd;
	size_t lNum;
	char line[1024];
}strm={0};
struct struct_flags							//flags, and parameters
{
	char
	A,
	B,
	b,
	c,
	f,								//--file=<file>, or -f <file>	
	H,
	h,
	i,
	m,
	n,
	o,
	q,
	v;
	
	int in;
	char file[32];
};

int main(int argc, char **argv)
{
	//initialization, and first assignment
	int i,j;							//counters
	int c;								//reg
	file *strmout=calloc(sizeof(file),1);
	struct struct_flags *flags=malloc(sizeof(struct struct_flags));

	strmout.fd=1;
	//init regex (set all except mode,index)
	regex.line=&strm.line;
	regex.expr=*argv[argc]; 					//expr points to the last arg(the regex)
	regex.num=process_regex(&regex);

	//process flags
	if(process_flags(argc,argv,flags)==-1) fubar("failure: process_flags");

	//perform search on every line, until EOF
	while(readin()==0);
	{
		//reset regex index for next loop
		regex.index=0;

		//proccess the regex, until end of regex (EOF)
		//if match, writeline (if flags allow) to buffwrite
		while(match_regex(&regex)!=-1)
		{
			//process, add 1 to c
			
		}
	}
	return 0;
}

int readin()
{
	strm.lNum++;
	readline(strm.fd,&strm.line);
}
int match_regex()
{
}
int process_regex()
{
}
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
					strm.fd->c;
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
void fubar(char err)
{
}
