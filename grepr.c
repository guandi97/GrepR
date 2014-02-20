/*
 GREP recreation
 grep takes command line regular expression and proccesses stdin

 regex should be in perl style
 -process_flags()
 	-process flags
 -process_regex()
 	-checks syntax for errors
 	-sets # of regex constant
 -infinit while loop
 	-readin
		-from strm.in
		-store 1 line, check EOF
 -if readin=EOF, break
	-proccess each expression independently while checking line with match_regex()
	-match_regex()
		-if not match, break
		-increment counter
 	-if counter = regex constant, print line to stdout
-return 0;
 
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
	int i,j;							//counters
	int c;								//reg
	file *out=malloc(sizeof(file));
	strm.in=malloc(sizeof(file));
	strm.line=malloc(1024);
	struct struct_flags *flags=malloc(sizeof(struct struct_flags));

	strm.in->fd=0;
	out->fd=1;

	//process flags
	c=parse_flags(argc,argv,flags);
	if(c==-1) fubar("failure: process_flags");

	//init regex (set all except mode,index)
	gegex.expr=*(argv+(argc));
	gegex.index=0;
	gegex.line=strm.line;

	//check regex
	gegex.num=process_regex();
	if(gegex.num==-1) fubar("failure: check_regex");

	//perform search on every line, until EOF
	gegex.index=0;
	c=readin();
	do 
	{
		//proccess the regex, until end of regex (EOF)
		//if match, writeline (if flags allow) to buffwrite(strm.fd)
		for(i=0;i<gegex.num;i++)
		{
			//check proccess_regex
			if(match_regex()==-1) goto MAIN_DO97;
		}
		buffwrite(gegex.line,out,c);

		MAIN_DO97:;
		//reset regex index for next loop
		gegex.index=0;
		c=readin();
	}while(c!=-1);
	return 0;
}
