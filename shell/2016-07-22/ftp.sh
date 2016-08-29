#!bin/sh
ping 192.168.4.254 -c 1 -i 0.01 &> /dev/null
if test $? -eq 0
then
# lftp 192.168.4.254
 # lcd ~/桌面/笔记/1
  #mirror /pub/20160711/
 lftp 192.168.4.254 << EOF
 
 lcd ~/桌面/笔记/1
  mirror /pub/20160711/
EOF
 \cp ~/桌面/笔记/1/20160711 ~/桌面/笔记/20160711 -r 
fi 
