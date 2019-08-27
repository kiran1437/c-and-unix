#include <stdio.h>

#define pvi(V)     printf("%-15s=%-12d\n",#V,V)


struct X { 
	int a;
	struct Y { int b;};
	char c;
	};

int main(int argc, char * argv[])
{

struct Y y; 

pvi(sizeof(struct X));
pvi(sizeof(struct Y));
pvi(sizeof(y));

 return 0;
} 
