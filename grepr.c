/*
 GREP recreation
 grep takes command line regular expression and proccesses stdin

 Guandi97
 */


#include <unistd.h>
#include <stdlib.h>

/*include either one by defining the one not in use*/
#define asmfun

#define grepr
#include "grepr_lib.h"

int main(int argc, char **argv)
{
	//initialization, and first assignment
	int i,j;							//counter,accumulator
	int c;								//reg
	file *out=malloc(sizeof(file));
	strm.in=malloc(sizeof(file));
	strm.line=malloc(1024);

	strm.in->fd=0;
	out->fd=1;

	//process flags
	c=parse_flags(argc,argv);
	if(c==-1) fubar("failure: parse_flags\n");

	//init regex (set all except mode,index)
	gegex.expr=*(argv+(argc));
	gegex.index=0;
	gegex.line=strm.line;

	//check regex
	gegex.num=process_regex();
	if(gegex.num==-1) fubar("failure: process_regex\n");

	//perform search on every line, until EOF
	gegex.index=0;
	c=readin();
	do 
	{
		//proccess the regex, until end of regex (EOF)
		//if match, writeline (if flags allow) to buffwrite(strm.fd)
		for(i=0;i<gegex.num;i++)
		{
			//check parse_regex
			if(parse_regex()==-1) goto MAIN_DO50;
		}
		buffwrite(gegex.line,out,c);

		MAIN_DO50:;
		//reset regex index for next loop
		gegex.index=0;
		c=readin();
	}while(c!=-1);
	return 0;
}
