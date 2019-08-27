#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#define pvi(V)     printf("%-15s=%-12d\n",#V,V)
#define pvstr(V)   printf("%-15s=%-12s\n", #V,V)
  



struct emp { int id; char name[];};

struct emp e1 = { 10};

int main(int argc, char * argv[])
{


struct emp * ep1 = malloc( sizeof(struct emp) + 20);


struct emp * ep2 = malloc( sizeof(struct emp) + 10);


ep1-> id = 20;
strcpy( ep1->name, "First emp name"); 

ep2-> id = 30;
strcpy( ep2->name, "only nine"); 


pvi(ep1->id);
pvstr(ep1->name);

pvi(ep2->id);
pvstr(ep2->name);











 return 0;
} 
