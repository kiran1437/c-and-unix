#include <stdio.h>

int A[7]={4,5,6};

int
f (int a)
{
  printf ("in function f \n");
  int j = 20;
  printf ("exiting from function\n");
  return 1;
}

int g (void) 
{
  printf ("in function f \n");
 return 2 ; 
}

int
main (int argc, char *argv[])
{

  int i = 10;

  printf ("First \n");
  printf ("Second \n");
  printf ("Third  \n");
  i = 20;
  if (i > 20)
    printf ("if part\n");
  else
    printf ("else part\n");

  f (39);
i = f(10) + g() + f(20);


  for (i = 10; i < 15; i++)
    {
      printf ("hello\n");
      printf ("Value of i is %d \n", i);
      printf ("world\n");
    }

   A[2]=30; 
   printf("hello\n"); 
   A[4]=50; 

   int * ip = A + 2;
   printf("world\n"); 
   *(ip + 3)  = 100; 

  return 0;
}

