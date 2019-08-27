#include<stdio.h>
main()
{
float (*a) [5]; 
int i,j;

a = (float (*)[5] )malloc(sizeof(float[5]) * 4);
if( a== NULL) fprintf(stderr, "malloc error\n");

printf("sizeof(*a)= %d\n", sizeof(a[0]));

for(i=0;i<4;i++)
	for(j=0;j<5;j++)
		a[i][j]= i * j * 1.0;
for(i=0;i<4;i++)
	{
	for(j=0;j<5;j++)
		printf("a[%d][%d]=%.2f  ", i,j,a[i][j]);
	printf("\n");
	}
}
