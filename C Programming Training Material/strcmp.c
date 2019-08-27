#include <stdio.h>

#include <string.h> 

#define pvi(V)     printf("%-15s=%-12d\n",#V,V)
 

int main(int argc, char * argv[])
 {

 char A[10] = "xy", 
      B[10] = "abcd", 
      C[10] = "pqrstuvw";
 
char ACAPS1 [10] = "Xy", 
            BCAPS1[10] = "aBCD", 
            CCAPS1[10]   = "pQRSTUVW";

char ACAPS [10] = "XY", 
            BCAPS[10] = "ABCD", 
            CCAPS[10]   = "PQRSTUVW";
int x=10,y=20,z=30;

pvi(x);
pvi(y);
pvi(x+y);
pvi(x*y);
pvi(x + y * 4 + 3 * 2 );
pvi(sizeof(x));


pvi(     strcmp (A, B )    ) ;
pvi(     strcmp (B,A )    ) ;
pvi(     strcmp (C, A )    ) ;
pvi(     strcmp (C, B )    ) ;

pvi(     strcmp (ACAPS1, A )    ) ;
pvi(     strcmp (B,BCAPS1 )    ) ;

pvi(     strcmp (ACAPS, B )    ) ;
pvi(     strcmp (B,BCAPS )    ) ;
 return 0;
 } 
