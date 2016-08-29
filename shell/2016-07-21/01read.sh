
#!/bin/sh

#输入  输入的信息存储在AA下  AA不可以是$AA
#read  AA
#echo $AA

#-p       提示
#Shell下变量一般情况下为大写

#-n 限定输入的长度 如果输入长度达到规定长度，那么会自动Enter
#-t 限定时间  如果该段时间内没有输入，则会返回失败  如果输入正确 返回成功
#-s 加密输入  输入字符不可见
read -s -t 5 -n 6 -p "Pls input a Name: "  NAME

if test $? -eq 0
then
	echo "YES"
else
	echo "NO"
fi

	
echo $NAME

