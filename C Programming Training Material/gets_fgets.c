#include <stdio.h>

int main(int argc, char * argv[])
 {
char b[10],c[10];
/*
gets(b);
printf("--%s--\n",b); 
fgets(c,   sizeof(c), stdin);
printf("--%s--\n",c); 
*/

scanf("%3s",b);  
printf("--%s--\n",b); 
scanf("%s",c);  
printf("--%s--\n",c); 
return 0;
 } 
