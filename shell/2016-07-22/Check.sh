

#!/bin/sh

ARRAY=( 0 1 2 3 4 5 6 7 8 9 a b c d e f )
NU=( 0 1 2 3 4 5 6 7 8 9 )

for i in `seq 0 25`
do

NUM=`expr $i + 97`
NUM1=`expr $NUM / 16`
NUM2=`expr $NUM % 16`

NUM3=`expr $i + 65`
NUM4=`expr $NUM3 / 16`
NUM5=`expr $NUM3 % 16`


#echo ${NUM1}${NUM2}

VALUE=${ARRAY[$NUM1]}${ARRAY[$NUM2]}
VALUE1=${ARRAY[$NUM4]}${ARRAY[$NUM5]}

#echo  ${ARRAY[$NUM1]}${ARRAY[$NUM2]}

BB=`echo -e "\x$VALUE"`
CC=`echo -e "\x$VALUE1"`

AA+="$BB  "
DD+="$CC  "

done

ALLNUM=( ${NU[@]} ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  ${NU[@]}  $AA $DD  $AA $DD  $AA $DD  $AA $DD  $AA $DD )



while :
do

#390

RAN1=`expr $RANDOM % 390`
RAN2=`expr $RANDOM % 390`
RAN3=`expr $RANDOM % 390`
RAN4=`expr $RANDOM % 390`


COLOR1=`expr $RANDOM % 8`
COLOR2=`expr $RANDOM % 8`
COLOR3=`expr $RANDOM % 8`
COLOR4=`expr $RANDOM % 8`

COLOR1=`expr $COLOR1 + 30`
COLOR2=`expr $COLOR2 + 30`
COLOR3=`expr $COLOR3 + 30`
COLOR4=`expr $COLOR4 + 30`


echo  -e "\033[${COLOR1}m${ALLNUM[$RAN1]}\033[${COLOR2}m${ALLNUM[$RAN2]}\033[${COLOR3}m${ALLNUM[$RAN3]}\033[${COLOR4}m${ALLNUM[$RAN4]}\033[0m"

CHECK=${ALLNUM[$RAN1]}${ALLNUM[$RAN2]}${ALLNUM[$RAN3]}${ALLNUM[$RAN4]}

read -t 5 -n 4 -p "Pls input An Key: "  KEY

if test $? -ne 0
then
	echo  "TimeOut Pls input Again"
	echo  "Click Any Key to Continue!"
	read -n 1 -s TMP   #阻塞
	continue
fi

#判断Key值是否正确

if test "$CHECK" == "$KEY"
then
	echo
	echo "Login Success...!"
	break
else
	
	echo "Login Error ... !"
	echo  "Pls input Again"
	echo  "Click Any Key to Continue!"
	read -n 1 -s TMP   #阻塞

fi

done









