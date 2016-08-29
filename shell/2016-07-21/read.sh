#!/bin/sh
while(1):
read -s -t 10  -n 6 -p "Pls input numbers: " A 
echo
if  test -z "$A"
then
	echo "请输入密码"
	exit
fi

if test $A -eq 123456
then
	echo  "登录成功"
else 
	echo  "登录失败"
fi

