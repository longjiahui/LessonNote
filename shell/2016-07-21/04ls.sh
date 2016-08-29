
#!/bin/sh

DIRECTORY=/var/ftp/pub
COLOR=`echo $LS_COLORS`

for i in `ls $DIRECTORY`
do
	#echo $i
	
	#判断普通文件或者是目录
	if test -d  $DIRECTORY/$i
	then
		FLAG="di"
	fi	
	
	#写其它文件型式
	#case


	#17条
	if test -f $DIRECTORY/$i
	then
	#尾辍处理
		FLAG="XX"
		
		for j in `seq 19 110`
		do
		
		STR=`echo $COLOR | cut -d : -f $j`
		
		LEFT=`echo $STR | cut -d = -f 1`
		RIGHT=`echo $STR | cut -d = -f 2`

		echo "$i" | grep .${LEFT}$   &>  /dev/null

		if test $? -eq 0
		then
			echo -e "\033[${RIGHT}m$i\033[0m"
			break
		fi
		#echo -e "Left:$LEFT\tright:$RIGHT"
		
		done
		
		if test $j -eq 110
		then
		echo $i
		fi
	fi

	#前17条
	
	if test "$FLAG" != "XX"
	then
		for j in `seq 2 18`
		do
		
		STR=`echo $COLOR | cut -d : -f $j`
		
		LEFT=`echo $STR | cut -d = -f 1`
		RIGHT=`echo $STR | cut -d = -f 2`
		
		if test "$FLAG" == "$LEFT"
		then
			echo -e "\033[${RIGHT}m$i\033[0m"
			break
		fi
		#echo -e "Left:$LEFT\tright:$RIGHT"
		
		done
	fi
done

