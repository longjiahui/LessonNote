
#!/bin/sh

i=6

if test $i -eq 0
then
	echo "is zero"
else 
	if test $i -gt 0
	then
		echo "greater zero"
	else
		echo "less than zero"
	fi
fi

if test $i -eq 0
then
	echo "is zero"
else if test $i -gt 0
then
	echo "greater zero"
else
	echo "less than zero"
     fi
fi

#如果elif不用加fi
if test $i -eq 0
then
	echo "is zero"
elif test $i -gt 0
then
	echo "greater zero"
else
	echo "less than zero"
fi




