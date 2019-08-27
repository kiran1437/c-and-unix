#include<time.h>

main ()
{
  time_t t;

  time (&t);

  printf ("-%s-\n", ctime (&t));

}
