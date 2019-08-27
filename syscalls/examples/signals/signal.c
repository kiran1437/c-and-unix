#define _BSD_SOURCE
#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

void handler (int signo)
{
  printf ("Received signal %d\n", signo);
  sleep(5); 
  printf ("Completing the resource release\n"); 
}
 
int
main ()
{
  int i;

  i = 10;

  signal (2, handler);
  scanf ("%d", &i);
  printf("i=%d\n", i); 

  return 0;
}
