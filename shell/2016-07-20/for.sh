
#!/bin/sh

#for是打印一个集合体内的一个成员

for i in 1 2 "hello world" 4 5.333 6 7 8 9 
do
	echo '$i':"$i"
done

for i in `seq 1 1 100`
do
	echo "$i"
done

for i in `seq 100 -1 1`
do
	echo "$i"
done



