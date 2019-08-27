
#include <stdio.h>
#define pvi(V)     printf("%-15s=%-12d\n",#V,V)
 
int main(int argc, char * argv[])
{
int A[10];

pvi( sizeof ( A));

pvi( sizeof( *&A));
pvi( sizeof( &*A));
 return 0;
} 
