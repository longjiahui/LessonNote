
#!/bin/sh

#函数的实现
DO_FUNCTION()  {

#函数的传参
echo  $1
echo  $2
echo  $3
echo  $4
echo  $5
echo  $*
echo  $#
echo  $@
echo  "hello world"

	return  11

}

#函数的调用

DO_FUNCTION   A  B  C  D  E 

echo $?


