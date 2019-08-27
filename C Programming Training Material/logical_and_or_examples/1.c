#include <stdio.h>
#define pvi(V)     printf("%-35s=%-12d\n",#V,V);

#define pvf(V)     printf("%-15s=%-12f\n",#V,V);

#define pvs(V)     printf("%-15s=%-12hd\n",#V,V);

#define PV 	pvi(i);pvi(j);pvi(k);

#define SETBASEVALUES       i=4,j=5,k=6

#define SETBASEVALUESZERO   i=0,j=0,k=0

#define SEP        printf(\
"---------------------------------------------------------------\n"); 


int main(int argc, char * argv[])
{

int i,j,k;

SETBASEVALUES;
PV;printf("\n"); 
pvi( k = i++ && j++);
printf("\n"); PV; SEP;

SETBASEVALUES;
i=0;
PV;printf("\n"); 
pvi( k = i++ && j++);
printf("\n"); PV; SEP;

/*   i++  && j++
     ++ has higher precedence than &&

     (i++)  && (j++)

     But c standard explicitly states if left operand of 
     && is zero right operand is not evaluated.

      i++  +  j++ 
      ++ has higher precedence than + 
      (i++)  +   (j++)
	i and j both will be incremented.


*/

SETBASEVALUES;
i=0;
PV;printf("\n"); 
pvi( k = i++ + j++);
printf("\n"); PV; SEP;


SETBASEVALUES;
PV;printf("\n"); 
pvi( i++ && j++ || k++ );
printf("\n"); PV; SEP;

/*  (i++)  && ( j++)  || (k++) 

    ( (i++)  && ( j++) ) || (k++) 
*/
SETBASEVALUES;
i=0;
PV;printf("\n"); 
pvi( i++ && j++ || k++ );
printf("\n"); PV; SEP;


SETBASEVALUES;
PV;printf("\n"); 
pvi( i++ || j++ && k++ );
printf("\n"); PV; SEP;

/*  (i++)  || ( j++)  && (k++) 

     (i++)  || ( ( j++)  && (k++) ) 
*/
SETBASEVALUES;
i=0;
PV;printf("\n"); 
pvi( i++ || j++ && k++ );
printf("\n"); PV; SEP;

SETBASEVALUES;
i=0;j=0;
PV;printf("\n"); 
pvi( i++ || j++ && k++ );
printf("\n"); PV; SEP;

SETBASEVALUES;
PV;printf("\n"); 
pvi( i++ && j++ && k++ );
printf("\n"); PV; SEP;

/*  (i++) &&  ( j++)  && (k++) 

     ( (i++) && ( j++)  )  && (k++)  
*/
SETBASEVALUES;
i=0;
PV;printf("\n"); 
pvi( i++ && j++ && k++ );
printf("\n"); PV; SEP;

SETBASEVALUES;
PV;printf("\n"); 
pvi( i++ || j++ || k++ );
printf("\n"); PV; SEP;

/*  (i++) ||  ( j++)  || (k++) 

     (  (i++) || ( j++)   ) ||  (k++)  
*/
SETBASEVALUES;
i=0;
PV;printf("\n"); 
pvi( i++ || j++ || k++ );
printf("\n"); PV; SEP;

SETBASEVALUES;
i=0;j=0;
PV;printf("\n"); 
pvi( i++ || j++ || k++ );
printf("\n"); PV; SEP;


return 0;
}


