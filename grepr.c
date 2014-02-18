/*
 GREP recreation
 grep takes command line regular expression and proccesses stdin

 regex should be in perl style
 -process_flags()
 	-process flags
 -preprocess_regex()
 	-checks syntax for errors
 	-sets # of regex constant
 -infinit while loop
 -readin
	-store 1 line, check EOF
 -if readin=EOF, break
 -process_regex()
 	-proccess each expression independently while checking line with match_regex()
 	-match_regex()
		-increment counter
 -if counter = regex constant, print line
 
 */
#include <unistd.h>

/*include either one*/
//include "asmfun.h" 
#include "stdfun.h"

#define usage "grepr - a recreation of grep"

struct struct_regex;
struct struct_input;
struct struct_flags;

struct struct_gegex
{
	int mode;							//
	int num;							//# of reg
	size_t index;							//loc of current reg
	char *expr;							//the regex
	char *line;							//current line
}gegex={0};
struct struct_strm							//input filestream
{
	file *in;
	size_t lNum;
	char line[1024];						//store current file, maybe inefficient
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
	*strm.in=calloc(sizeof(file),1);
	struct struct_flags *flags=malloc(sizeof(struct struct_flags));

	strm.fd=1;

	//process flags
	c=process_flags(argc,argv,flags);
	if(c==-1) fubar("failure: process_flags");

	//init regex (set all except mode,index)
	gegex.expr=*(argv+(c+1));
	gegex.num=check_regex();
	gegex.line=&strm.line;

	//check regex
	const short reg=process_regex();
	if(reg==-1) fubar("failure: check_regex");

	//perform search on every line, until EOF
	c=0;
	while(readin()==0);
	{
		MAIN_WHILE97:;
		//reset regex index for next loop
		gegex.index=0;
		c=readin();

		//proccess the regex, until end of regex (EOF)
		//if match, writeline (if flags allow) to buffwrite(strm.fd)
		for(i=0;i<reg;i++);
		{
			//check proccess_regex
			if(match_regex()==-1) goto MAIN_WHILE97;
		}
		buffwrite(*regex.line,&strm,c);
	}
	return 0;
}

#include "greprlib.h"
