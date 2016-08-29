
#!/bin/sh

#ascii
#八进制
echo  -e  "\0101"
#十六进制
echo  -e  "\x61"   #a

ARRAY=( 0 1 2 3 4 5 6 7 8 9 a b c d e f )


for i in `seq 0 25`
do

NUM=`expr $i + 97`
NUM1=`expr $NUM / 16`
NUM2=`expr $NUM % 16`

NUM3=`expr $i + 65`
NUM4=`expr $NUM / 16`
NUM5=`expr $NUM % 16`


#echo ${NUM1}${NUM2}

VALUE=${ARRAY[$NUM1]}${ARRAY[$NUM2]}
VALUE1=${ARRAY[$NUM4]}${ARRAY[$NUM5]}

#echo  ${ARRAY[$NUM1]}${ARRAY[$NUM2]}

BB=`echo -e "\x$VALUE"`
CC=`echo -e "\x$VALUE1"`

AA+="$BB  "
DD+="$CC  "


done

#echo $AA

#for i in $AA
#do
#	echo $i
#done

ARRAY1=( $AA $DD )

for i in `seq 0 25`
do

echo  ${ARRAY1[$i]}

done










