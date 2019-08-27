#include <stdio.h>

int main(int argc, char * argv[])
 {
/*
struct X { int b; };

struct X  NewName;

typedef struct X  NewName;

NewName x1, x2; 

*/
typedef int x; 

/*
  struct X { int b; } NewName;


*/ 

typedef   struct X { int b; } NewName;
typedef   struct Y { } NewNameY;

typedef   struct Z  NewNameZ;

NewName a, b ; 

NewName const * sp; 

sp = &a;

//*sp = b;

printf("a.b is %d \n", a.b); 
 return 0;
 } 
