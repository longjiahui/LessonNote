
#!/bin/sh

if test $# -ne 2
then
	echo  "Argument Fail"
	exit
fi

ARRAY=( 0 1 2 3 4 5 6 7 8 9 a b c d e f)

fun() {

if test $1 -eq 0
then
	return 0
fi
	
	A=`expr $1 / $2`
	fun   $A   $2

	B=`expr $1 % $2`
	echo -e -n "${ARRAY[$B]}"
}


fun   $1   $2

