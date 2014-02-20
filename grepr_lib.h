#ifndef grepr_lib
	#define grepr_lib

	#ifndef asmfun
		#ifdef stdfun
			#define asmfun
			#include "asmfun.h"
		#else
		#endif
	#endif
	#ifndef stdfun
		#define stdfun
		#include "stdfun.h"
	#endif
	#ifndef grepr_glob
		#define grepr_glob
		#include "grepr_glob.h"
	#endif
	#ifndef regex_lib
		#define regex_lib
		#include "grepr_regex/regex_lib.h"
	#endif
	#ifndef grepr_fun
		#define grepr_fun
		#include "grepr_fun.h"
	#endif
#endif

