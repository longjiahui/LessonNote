
#!/bin/sh

if test $# -eq 0
then
	for i in `ls`
	do
		if test -d $i
		then
		
		./07directory.sh  $i	

		fi

		echo  $i
	done
else

	for j in $@
	do

		for i in `ls $j`
		do

			if test -d $j/$i
			then
			./07directory.sh  $j/$i
			fi
			echo $j/$i
		done
	done
fi

