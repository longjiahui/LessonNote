
#!/bin/sh

while :
do

RANROW=`expr $RANDOM % 26`
RANCOL=`expr $RANDOM % 91`
COLORRAN=`expr $RANDOM % 8`
COLORRAN=`expr $COLORRAN + 40`

echo -e  "\033[${RANROW};${RANCOL}H\033[${COLORRAN}m \033[0m"

done
