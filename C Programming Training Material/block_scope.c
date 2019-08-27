//#include <stdio.h>


       int printf(const char *format, ...);

int
main (int argc, char *argv[])
{
  int i = 10;
  printf ("First i=%d\n", i);
  {
    printf ("second i=%d\n", i);

    int i = 30;
    printf ("third i=%d\n", i);
    if (i > 20)
      {
	printf ("fourth i=%d\n", i);
	int i = 50;
	printf ("sixth  i=%d\n", i);
	i = 60;
      }
    printf ("seventh  i=%d\n", i);
    i = 70;
  }
  printf ("eighth  i=%d\n", i);
  return 0;
}
