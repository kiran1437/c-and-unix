#include <stdio.h>
#define pvi(V)     printf("%-15s=%-12d\n",#V,V);
 
int main(int argc, char * argv[])
 {
 int i = 10, j = 20, k= 40;


pvi(sizeof i       );
pvi(sizeof "hello" );
pvi(sizeof 'a'     );
pvi(sizeof 30.56   );
pvi(sizeof 30ll    );


/* for type name paranthesis is required 
   for expressions  it is optional
   good to use for readability 
*/ 

pvi(sizeof (int)    );



pvi(sizeof (i++)); 
pvi(i);

pvi(sizeof (++i)); 
pvi(i);

pvi(sizeof (i=100)); 
pvi(i);                         
/*                                 i + 3 
                                   ------
                                       13

                                   i = 100 
                                   ---------
                                       100     
*/
pvi(sizeof (i+=100)); 
pvi(i);                         


 return 0;
 } 
