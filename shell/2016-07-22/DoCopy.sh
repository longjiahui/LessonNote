
#!/bin/sh

#  $1  ==>   MOUNTDIR     挂载目录
#  $2  ==>   TARGETDIR    目标目录

for i  in `ls  $1`
do

	if test -d $1/$i
	then
	#目录
	
		if test -d  $2/$i
		then
		#目录存在 递归
			./DoCopy.sh  $1/$i  $2/$i  &
		else
		#目录不存在
		\cp  $1/$i  $2/$i  -r
		fi

	else
	#文件

		if test -f $2/$i
		then
		#文件存在
		MOUTSIZE=`ls -l $1/$i | cut -d ' ' -f 5`	
		TARGETSIZE=`ls -l $2/$i | cut -d ' ' -f 5`
		
		if test "$MOUTSIZE" != "$TARGETSIZE"
		then
		#文件大小不相等就copy
		\cp  $1/$i  $2/$i
		fi

		else
		#文件不存在
		\cp  $1/$i  $2/$i
		fi
	fi



done


