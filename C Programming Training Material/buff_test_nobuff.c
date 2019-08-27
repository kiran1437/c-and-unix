#include<stdio.h>
main()
{
int i;
 for( i=0X30;i<0X35;i++)
   {putchar(i); sleep(1);}

//setbuf(stdout, NULL);

sleep(3); 
 for( i=0X35;i<0X3A;i++)
   {putchar(i); sleep(1);}

printf("hello\nworld");
sleep(10);
printf("abc\n123");
sleep(10);
printf("Last output "); 

} 


