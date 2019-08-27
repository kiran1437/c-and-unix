#include <stdio.h>
int main(int argc, char * argv[]) { 



int i=12, j=10;


printf("%d\n", i | 10 >>1  && j & 10 );
           /*    i |  5      && j & 5 
               i |  5      && 0 
	            4 &&      0 
		    */

return 0; } 

