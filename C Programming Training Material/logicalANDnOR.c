#include <stdio.h>
#define pvi(V)     printf("%-15s=%-12d\n",#V,V);
 
int main(int argc, char * argv[])
 {
  int i = 10, j = 20; 

 
  j = 0 ||   i++; 

 pvi(j);
 pvi(i);
   
 return 0;
 } 
