//Guandi97

#define regex_lib

unsigned int regex_index;
char regex_list[64][8]={
			"^","\\A","\\Z","\\b","\\B","\\<","\\>",				//00:Anchors
			"\\c","\\s","\\S","\\d","\\D","\\w","\\W","\\xhh","\\Oxxx",		//07:Character Classes
			"\\","\\n","\\r","\\t","\\v","\\f","\\a",/*backspace*/"\\e","\\N",	//16:Special Characters
			".","()","(?:)","[]","[^]","\\n",					//26:Ranges
			"*","*?","+","+?","?","??","{}","{,}","{?}",				//32:Quantifiers
			};
			
#include "regex_Anchors.h"
#include "regex_Assertions.h"
#include "regex_Backtreferences.h"
#include "regex_Characters.h"
#include "regex_Classes.h"
#include "regex_Quantifiers.h"
#include "regex_Ranges.h"
