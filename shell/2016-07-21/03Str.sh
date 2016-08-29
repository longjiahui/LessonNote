
#!/bin/sh

STR="Hella"
STR1="Hello"

#判断字符串是否相等  =  ==>  ==
if test "$STR" = "$STR1"
then
	echo "YES"
else
	echo "NO"
fi



##-n  判断字符串是否为空，不为空为真
#if test -n "$STR"
#then
#	echo "YES"
#else
#	echo "NO"
#fi
#
##-z  判断字符串是否为空，为空为真
#if test -z "$STR"
#then
#	echo "YES"
#else
#	echo "NO"
#fi


# !  取反  一般情况下在test前面加 必须要有空格
#if ! test -n "$STR"
#then
#	echo "YES"
#else
#	echo "NO"
#fi


