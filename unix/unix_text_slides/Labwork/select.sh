select X in copy remove list quit 
do

echo ---$X---
case $X in 
copy) echo add the copy code here..
     ;;
remove) echo add teh remove code ..
     ;;
list) echo add teh list code here..
     ;;
quit)  break    
     ;;
esac 

done 

echo AFTER SELECT!!!!!

