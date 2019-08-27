#include <stdio.h>
#define pvi(V)     printf("%-15s=%-12d\n",#V,V);
 
int main(int argc, char * argv[])
 {

int i=10, j ; 

j = i++ * i++ * i++; 
pvi(i); 
pvi(j); 

i=10; 
j = ++i * ++i * ++i ; 
pvi(i); 
pvi(j); 


int A[] = { 10,20,30,40,50,60};
int B[] = { 1,2,3,4,5,6};

i = 0; 
j =  A[i++]   +   B [ i++];  
pvi(j); 
pvi(i); 
printf("-------------------------------------\n"); 


i = 0; 
j =  A[i++]   +   B [ i];  
pvi(j); 
pvi(i); 
printf("-------------------------------------\n"); 
 
i = 0; 
j =  A[++i]   +   B [ ++i];  
pvi(j); 
pvi(i); 
printf("-------------------------------------\n"); 


i = 0; 
j =  A[++i]   +   B [ i];  
pvi(j); 
pvi(i); 
printf("-------------------------------------\n"); 


i = 20;

j = ( i=10) * i ; 
pvi(j); 


 return 0;
 }

