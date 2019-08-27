#include <stdio.h>
#define pvstr(V)   printf("%-20s=%-20s\n", #V,V);
#define pvi(V)     printf("%-15s=%-12d\n",#V,V);

int g(int a,int b,int c){return 1;}

int main(int argc, char * argv[])
{
		  int i =10, j=20, k=30;

		  printf("Expression evaluation order with  gcc '+' operator \n"); 

		  k = printf("First\n") + printf("Second\n") + printf("Third\n") ; 

		  printf("Expression evaluation order with  gcc '*' operator \n"); 

		  k = printf("First\n") * printf("Second\n") * printf("Third\n") ; 



		  /*
			* Dont use putchar() to test order of evaluation 
			* putchar() could buffer data in library
			* printf() with an \n at the end will write the stdout buffer to 
			* terminal and can be predictable
			*
			*/

		  printf(" Argument evaluation order with printf() function call \n"); 

		  k =  printf("Format\n", 
								printf("First\n"), 
								printf("Second\n"), 
								printf("3rd\n")
						 ); 

		  printf(" Argument evaluation order with user defined  function call \n"); 

		  k = g(
								printf("First\n"), 
								printf("Second\n"), 
								printf("3rd\n")
				 ); 

			i=10; 
			printf("%d---%d\n",++i,++i); 
printf("\nCompare i values on the previous line with the following\n"); 
printf("Operator && is a sequence point\n\n"); 

			i = 10; 
		 printf("\n", ++i  &&  printf("First i:%d ", i),
                    ++i  &&  printf("Second i:%d ",i)  
             ); 


}

