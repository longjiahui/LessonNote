
#!/bin/sh

ARRAY=( 1 2 3 4 5 56 6 7 8 89 )

echo  ${ARRAY[@]}
echo  ${ARRAY[*]}

for i in  ${ARRAY[@]}
do

echo  $i

done

for i in `seq 0 9`
do

echo  '${ARRAY'[$i]}:"${ARRAY[$i]}"

done
