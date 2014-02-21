GrepR
=====

grep recreation as an exercise

-regex should be in perl style

include order:
unistd->grepr_lib(stdfun->regex_lib->grepr_glob->grepr_fun)->grepr

_main:
-initialization
	-initilize strm
	-set strm.in->fd=1
	-set file *out
	-initialize gegex
-proccess flags
	-check if ==argc-1
	-if -f flag
		-change strm.in->fd
-process regex
	-check syntax
	-set gegex.num
-setup for fist Alliteration of loop
-do loop
	-parse regex
		-if gegex.index==gegex.num
			-print
	-readin
-while readin!=EOF (signed int -1)

_parse_regex()

