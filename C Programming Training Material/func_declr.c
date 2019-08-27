#include <stdio.h>

typedef void Func_Type_Def(int a, int b); 

Func_Type_Def f1;
Func_Type_Def * ptr_to_f1  =  f1;;


/* Func_Type_Def f2()
{
printf("%d\n",a ); 
} 

*/

// Function f3 returns a pointer to a function that takes an int argument
// and returns a short.
// f3 itseld takes no arguments
short  (*f3( void ))   ( int ); 

// Function f4 returns a  pointer to      pointer to a function that 
// takes an int argument and returns a short.
// f4 itseld takes no arguments
short  (* *f4( void ))   ( int ); 

// Function f5 returns a   pointer to a function that 
// takes an int argument and returns a short pointer .
// f3 itseld takes no arguments
short  *   (*f5( void ))   ( int ); 


void f1(int a, int b){   return a + b;    } 
main(int argc, char * argv[])
{
 printf("--%d--\n",   *ptr_to_f1(3,4)  ); 
 return 0;
} 
