
#!/bin/sh

#终端码  VT码
#\033  ==> ascii   //打头
#[		   //后面加上
#30-37   前景着色
#40-47   背景着色

#\033[0m  结束着色

#for i in `seq 30 37`
#do
#	echo -e  "\033[01;${i}mHello world\033[0m"
#done
#
#for i in `seq 40 47`
#do
#	echo -e  "\033[01;${i}mHello world\033[0m"
#done


#for i in `seq 0 19`
#do
#
#FORRAN=`expr $RANDOM % 8`
#BACRAN=`expr $RANDOM % 8`
#
#FORRAN=`expr $FORRAN + 30`
#BACRAN=`expr $BACRAN + 40`
#
#echo -e "\033[01;${FORRAN}m\033[${BACRAN}mHello World\033[0m"
#
#done

#\033[2J  清屏

echo -e "\033[2J\033[3;40HHello world"                                               








