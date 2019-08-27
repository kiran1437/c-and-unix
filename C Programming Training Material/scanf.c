#include <stdio.h>

int main(int argc, char * argv[])
 {
 int i=10,j=20,k=30;
 char c1,c2,c3;
 int ret_value; char buf[20]; 

 ret_value = scanf ( "%d%d%d", &i,&j,&k); 

//__fpurge(stdin);

 c1 = getchar();

// gets(buf); 

 printf("--%d--    %d   %d  %d\n", ret_value,i,j,k); 

 printf("char is --%c--\n", c1); 
 return 0;
 } 
