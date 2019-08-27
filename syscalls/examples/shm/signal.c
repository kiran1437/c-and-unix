#define _BSD_SOURCE
#include<stdio.h>
#include<sys/types.h>
#include<signal.h>

void
handler (int signo)
{
  printf ("Received signal %d\n", signo);
  sleep (30);
  printf ("After sleeping %d\n", signo);
}

int
main ()
{
  int i;

  i = 10;

  signal (i, handler);
  scanf ("%d", &i);

  return 0;
}
