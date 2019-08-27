#include <stdio.h>
#define pvi(V)     printf("%-15s=%-12d\n",#V,V);
 
int main(int argc, char * argv[])
 {

int A[10]; 

//void v; 
// The following require -pedantic flag to get a warning
// Ideally should not be supported
//
void *vp = A;

vp++;

vp+=3;

*vp;

pvi( sizeof(void));  
pvi ( sizeof(*vp)); 
 return 0;
 } 
