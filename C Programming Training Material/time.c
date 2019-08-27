#include <stdio.h>
#include <time.h>

int
main (int argc, char *argv[])
{
  time_t t;
  time (&t);

  printf ("tiem in secs --%d--\n", t);

  printf ("--%s--\n", ctime (&t));

  return 0;
}
