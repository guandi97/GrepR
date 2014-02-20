#define grepr_glob

#include "grepr_lib.h"

struct struct_gegex gegx;
struct struct_strm strm;
struct struct_flags flags;

struct struct_gegex
{
        int mode;                                                       //  
        int num;                                                        //# of reg 
        unsigned int index;                                             //loc of current reg 
        char *expr;                                                     //the regex
        char *line;                                                     //current line
}gegex={0};
struct struct_strm                                                      //input filestream
{
        unsigned int lNum;
        char *line;                                                //store current file, maybe inefficient
        file *in;
	file *out;
}strm={0};
struct struct_flags                                                     //flags, and parameters
{
        char
        A,  
        B,  
        b,  
        c,  
        f,                                                              //--file=<file>, or -f <file>   
        H,  
        h,  
        i,  
        m,  
        n,  
        o,  
        q,  
        v;  
    
        int in; 
        char file[64];
}flags={0};
