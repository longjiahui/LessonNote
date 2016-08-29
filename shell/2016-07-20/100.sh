
#!/bin/sh

SUM=0

for i in  `seq 1 10000`
do

	#SUM=`expr $SUM + $i`   #速度最慢
	#SUM=$(($SUM+$i))
	#let  "SUM+=i"          #let双引号内C语法

	#echo $i
done

echo '$Sum':"$SUM"


