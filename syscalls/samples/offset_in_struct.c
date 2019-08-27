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
};

printf("offsetof(X, a)=%d\n", offsetof(struct X ,a));
printf("offsetof(X, b)=%d\n", offsetof(struct X ,b));
printf("offsetof(X, c)=%d\n", offsetof(struct X ,c));
printf("offsetof(X, d)=%d\n", offsetof(struct X ,d));
printf("offsetof(X, e)=%d\n", offsetof(struct X ,e));
printf("offsetof(X, f)=%d\n", offsetof(struct X ,f));

printf("sizeof(struct X)=%d\n",sizeof(struct X ));


}
