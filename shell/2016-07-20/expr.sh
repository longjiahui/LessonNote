
#!/bin/sh

##算术
##加法
#expr  1 + 1  
#
##减法
#expr  2 - 3
#
##乘法
#expr  2 \* 3
#
#expr  6 / 2
#
##如果前面的操作数非0 则前面结果  要不后面为结果
#expr  7 \| 8
#expr  0 \| 9
#
#expr  1 \< 0
#
#expr  2 \<\= 3

#****************************************
#字符串

#计算字符串的长度   strlen
STR="hello world"
expr length "hello dog"
echo $STR
expr length "$STR"    #如果想代表一个变量为字符串必须加""


#计算字符在字符串下的坐标  从头开始找
expr  index  "hello world"   l  #返回第一个字符为1 从1开始


#获取一个字符串的子串
expr  substr  "hello world"  3  3
#            字符串      从哪个坐标开始   拿多少个   从1开始

#相同匹配个数为多少个字符
expr  match   "hello"  "hello"


