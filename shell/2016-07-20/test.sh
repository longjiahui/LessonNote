
#!/bin/sh

#! 代表shell默认执行程序,执行者是/bin/sh

#  代表注释


#执行shell脚本   

#内部变量     AAA=123
#外部变量(全局变量)    export  AAA=123


#方法一   //默认执行
#chmod a+x  test.sh    
#./test.sh   ==>  /bin/sh

#方法二  //外部命令执行   不可以直接访问内部变量
#sh   test.sh
#bash test.sh

#方法三  //内部命令执行   可以直接访问内部变量
#  .    test.sh
#  source  test.sh 

#ABC="this is a dog"

BBB=123

#打印时一般情况下用 {} 来区分变量名及其它字符
echo "hello world"  #echo默认情况下都会换行   echo ==> 换行
echo "BBB:${BBB}hello dog"

echo "\$BBB:$BBB"     #转义$

echo '$BBB'":$BBB"     # ''   表示字符，里面的$不会有作用

echo  -n  "hello pig"   #-n 取消echo的换行

echo  -n -e "hello kitty\n"  #-e 加特殊字符

echo  -n -e "\thello\t\tworld\rABC\n\a"

#echo $ABC
#查看ascii表    man  ascii




