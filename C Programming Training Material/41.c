#include <stdio.h>
#include <stdarg.h>

#define pvi(V) printf("%-15s=%-12d\n",#V,V);

int
sum (int num_int_args, ...)
{
  pvi (num_int_args);

  int num = 0, sum = 0, arg;

  va_list ap;
  va_start (ap, num_int_args);
  while (num_int_args-- > 0)
    {
      arg = va_arg (ap, int);
      pvi (arg);
      sum += arg;
    }
  pvi (sum);
  printf ("\n");
  va_end(ap);
  return sum;
}

int
main (int argc, char *argv[])
{


  sum (3, 1, 2, 3);
  sum (5, 10, 20, 30, 40, 50);
  sum (1, 1);
  sum (0 );
  sum (6, 100, 200, 300, 400, 500, 600);


  return 0;


}
