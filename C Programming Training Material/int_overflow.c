

#include <stdio.h>

//   INT_MAX       2147483647

#define pvi(V)     printf("%-15s=%-12d\n",#V,V);
#define pvix(V)    printf("%-15s=%#010x\n",#V,V);
#define pvll(V)    printf("%-20s=%-20lld\n", #V,V);
#define pvllx(V)   printf("%-20s=%-20llx\n", #V,V);
    
int main(int argc, char * argv[])
 {
 int i = 21474899999;
 long long ll= 21474899999LL;
pvi(i); 
pvix(i); 

pvll(ll);
pvllx(ll);

 unsigned int ui = 21474899999;
 return 0;
 } 
