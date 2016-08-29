
#!/bin/sh

# -i 限定时间   除非是root用户才可以限定时间小于0.1s
# -s 包大小   前面8个字节为协议头
# -c ping 次数  如果不写默认一直ping
#ping   192.168.4.254 -i 0.01 -s 10000 -c 1

echo "" >  ip.txt

for i in `seq 2 254`
do
	./ping1.sh    $i   &
done


