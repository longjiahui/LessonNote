
#!/bin/sh

read -p "Pls input A Year :"   YEAR

#方法一
# test expression  -o  expression
# [ expression  -o  expression  ]
# -o   orr    
# -a   and

#方法二
#||  && 
# test expression || test expression
# [ expression ] && [ expression ]

if test $YEAR -lt 0 || test $YEAR -gt 3000
then
	echo "Argument Error !"
	exit
fi

#if test $YEAR -lt 0  -o  $YEAR -gt 3000
#then
#	echo "Argument Error~"
#	exit
#fi

#判断是否为闰年

if test `expr $YEAR % 4` -eq 0 -a `expr $YEAR % 100` -ne 0 -o `expr $YEAR % 400` -eq 0
then
	echo "闰年"
else
	echo "平年"
fi


