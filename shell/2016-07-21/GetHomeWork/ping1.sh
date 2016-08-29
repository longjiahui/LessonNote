
#!/bin/sh

ping  192.168.4.$1 -c 1 -i 0.01  &> /dev/null 

if test $? -eq 0
then
echo  192.168.4.$1  >>  ip.txt

#ping 通

#showmount -e 192.168.4.$1  &> /dev/null
showmount -e 192.168.4.$1 | grep "^/homework\>" &> /dev/null

	if test $? -eq 0
	then
	#服务有开且有发布/homework目录
	
	rm -rf  /mnt/192.168.4.$1
	mkdir   /mnt/192.168.4.$1

	mount -t nfs  192.168.4.$1:/homework   /mnt/192.168.4.$1  &> /dev/null

	if test $? -eq 0
	then
		\cp  /mnt/192.168.4.$1/*   /work   -r   &> /dev/null
		umount  /mnt/192.168.4.$1
	fi

	rm -rf  /mnt/192.168.4.$1
	else
	#服务没开
	echo 192.168.4.$1 >> NoServer.txt
	fi
fi

