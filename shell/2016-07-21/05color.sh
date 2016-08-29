
#!/bin/sh

#cut -d : -f 1    

COLOR=`echo $LS_COLORS`

#echo $COLOR

for i in `seq 2 110`
do

STR=`echo $COLOR | cut -d : -f $i`

#echo $STR

LEFT=`echo $STR | cut -d = -f 1`
RIGHT=`echo $STR | cut -d = -f 2`

echo -e "Left:$LEFT\tright:$RIGHT"

done
