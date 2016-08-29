
#!/bin/sh

TARGETIP=192.168.4.254
NFSDIR=/var/ftp/pub/20160711
MOUNTDIR=/mnt
TARGETDIR=/homework

ping  -c  1  -i 0.1  $TARGETIP  &>  /dev/null

if test $? -ne 0
then
	echo "$TARGETIP Network unreachable"
	exit
fi
echo "Network OK"

#网络可达

showmount -e $TARGETIP  |  grep "^${NFSDIR}\>"  &> /dev/null

if test $? -ne 0
then
	echo "$TARGETIP NFS Server Not Export"
	exit
fi
echo "NFS OK"

#挂载

mount -t nfs $TARGETIP:${NFSDIR}     $MOUNTDIR    &>  /dev/null

if test $? -ne 0
then 
	echo "$TARGETIP Mount NFS Fail"
	exit
fi
echo "Mount NFS OK"


#**************************************
#主要逻辑


./DoCopy.sh   $MOUNTDIR     $TARGETDIR   &
sleep 2
./DoDelete.sh  $MOUNTDIR    $TARGETDIR   &

#阻塞  等待Copy完毕
while :
do
	sleep 1
	
	cd  $MOUNTDIR   
	tree  >   /txt
	cd  $TARGETDIR
	tree  >   /txt1
	diff  /txt  /txt1

	if test  $? -eq 0
	then
		break
	fi

done

#解挂
echo "Now is Umount **********************************************"
umount $MOUNTDIR



#我是中国人
echo "hello world"





