
#include<stdio.h>
#include<linux/stddef.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

main(){

struct X { 
int a;
char b[];
} ;

//struct X SA[10];

printf("offsetof(X, a)=%d\n", offsetof(struct X ,a));
printf("offsetof(X, b)=%d\n", offsetof(struct X ,b));

printf("sizeof(struct X)=%d\n",sizeof(struct X ));
//printf("sizeof(SA)=%d\n",sizeof(SA));


}

