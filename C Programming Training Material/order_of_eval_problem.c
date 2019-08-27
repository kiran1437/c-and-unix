#include <stdio.h>
#define pvi(V)     printf("%-15s=%-12d\n",#V,V);

int main(int argc, char * argv[]) { 
int A[10]={30,40,50,60};
int a = 5,b=0,c=10;

	pvi( (c+1 && a * b) );
	pvi( (c+1 && a * b) [A + (b=a&1)] );

} 



