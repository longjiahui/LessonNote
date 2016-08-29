
#!/bin/sh

#  $1  ==>   MOUNTDIR     挂载目录
#  $2  ==>   TARGETDIR    目标目录

for i  in `ls  $2`
do

	if test -d $2/$i
	then
	#目录
	
		if test -d  $1/$i
		then
		#目录存在 递归
			./DoDelete.sh  $1/$i  $2/$i  &
		else
		#目录不存在
		rm -rf  $2/$i
		fi

	else
	#文件

		if ! test -f $1/$i
		then
		rm -rf  $2/$i
		fi
	fi



done


