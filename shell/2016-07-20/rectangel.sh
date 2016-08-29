
#!/bin/sh

#左下
for  row  in `seq 0 9`
do
	for col in `seq 0 $row`
	do

	echo -n "* "

	done
	echo
done

#左上

for  row  in `seq 0 9`
do
	for col in `seq 9 -1 $row`
	do

	echo -n "* "

	done
	echo
done

#右上
for  row  in `seq 0 9`
do
	#打空格
	for col in `seq 1 $row`
	do

	echo -n "  "

	done

	for col in `seq 9 -1 $row`
	do

	echo -n "* "

	done
	echo
done


#右下
for  row  in `seq 0 9`
do

	#打空格
	for col in `seq 8 -1 $row`
	do

	echo -n "  "

	done


	for col in `seq 0 $row`
	do

	echo -n "* "

	done
	echo
done
