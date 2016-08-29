
#!/bin/sh

if test $# -ne 1
then
	echo "Argument Fail"
fi


##{
   
##default  :  printf("this is Unknown \n");   break;
##}

case $1  in     ##switch(a)
	[[:upper:]])   #大写
	echo "uppper"
	;;
	[[:lower:]])   #小写
	echo "lower"
	;;
	a|b|C|B|D)      #case 'a' :
	echo "this is A"  ##  printf("this is a \n");
	;;      #break;
	b)
	echo "this is B"
	;;
	[[:digit:]])   #数字
	echo "this is number"
	;;
	*)      #default
	echo "this is Unknown"
	;;
esac


