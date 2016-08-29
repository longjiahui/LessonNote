
#!/bin/sh

ping  192.168.4.$1 -c 1 -i 0.01  &> /dev/null 

if test $? -eq 0
then
echo  192.168.4.$1  >>  ip.txt
fi
