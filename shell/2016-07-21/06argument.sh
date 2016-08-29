
#!/bin/sh

#外部传参

echo '$1'=$1
echo '$2'=$2
echo '$3'=$3
echo '$4'=$4
echo '$5'=$5
echo '$6'=$6
echo '$7'=$7
echo '$8'=$8
echo '$9'=$9

#参数个数
echo '$#'=$# 

#参数集合体
echo '$@'=$@
echo '$*'=$*

#可以遍历
for i in $@
do
echo $i
done

