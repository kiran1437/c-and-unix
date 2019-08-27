#include <stdio.h>
#define pvi(V)     printf("%-35s=%-12d\n",#V,V);

#define pvf(V)     printf("%-15s=%-12f\n",#V,V);

#define pvs(V)     printf("%-15s=%-12hd\n",#V,V);

#define PV 	pvi(i);pvi(j);pvi(k);

#define SETBASEVALUES       i=4,j=5,k=7

#define SETBASEVALUESZERO   i=0,j=0,k=0

#define SEP        printf(\
"---------------------------------------------------------------\n"); 


int main(int argc, char * argv[])
{

int i,j,k;

SETBASEVALUES;
PV;printf("\n"); 
pvi( i && j == 5 & k ); 

/* 
	i && j == 5 & k 
	i && ( j == 5) & k 
	i && (  ( j == 5) & k ) 
*/

pvi( i && j == 4 & k ); 
SEP;

PV;printf("\n"); 
pvi( i && j == 5 > k ); 

/* 
	i && j == 5 > k 
	i && j == (5 > k) 
	i && (j == (5 > k) ) 
*/

k=4;
j=1;
PV;printf("\n"); 
pvi( i && j == 5 > k ); 
SEP;


















/* 
     pvi( i && j = 4 & k ); 

	i && j = 5 & k 
        ( i && j) = 5 & k
        ( i && j) = ( 5 & k) 
        Compilation error
*/

return 0;
}


