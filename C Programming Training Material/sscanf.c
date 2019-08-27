#include <stdio.h>
 
int main(int argc, char * argv[])
 {
 int i=-200; float f=30.456; char name[20]= "hello";

 char *cp = "4567    56.381   CPROGRAM  " ; 

 printf("i = %d f = %f  nam e= %s \n", i, f, name ); 

  
 sscanf(cp, "%d%f%s", &i, &f, name ); 

 printf("i = %d f = %f  nam e= %s \n", i, f, name ); 

 return 0;
 } 
