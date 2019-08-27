#include<stdio.h>
#include<linux/stddef.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

main(){

struct X { 
char b;
int a;
char c[21];
short d;
float e;
double f;
}  x ;






/*Alignment restrictions: 
double  4,8,12,16,....
float   4,8,12,.....
int 4,8,12,16,.........
short   2,4,6,8,10,....
char    1,2,3,4,5,
*/

printf("Address of x is %p\n", &x ); 
printf("offsetof(X, a)=%d Address is %p \n", 
			offsetof(struct X ,a), &x.a);
printf("offsetof(X, b)=%d Address is %p \n", 
			offsetof(struct X ,b), &x.b);
printf("offsetof(X, c)=%d Address is %p \n", 
			offsetof(struct X ,c), &x.c);
printf("offsetof(X, d)=%d Address is %p \n", 
			offsetof(struct X ,d), &x.d);
printf("offsetof(X, e)=%d Address is %p \n", 
			offsetof(struct X ,e), &x.e);
printf("offsetof(X, f)=%d Address is %p \n", 
			offsetof(struct X ,f), &x.f);

printf("sizeof(struct X)=%d\n",sizeof(struct X ));








}

