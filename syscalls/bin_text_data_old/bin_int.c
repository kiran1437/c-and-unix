#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


main ()
{
  int  ia[16];
  int i;
  for (i = 0; i < 16; i++)
    ia[i] = 0XABCDEF + i;

  int fd = open ("bin_int_data", O_RDWR | O_CREAT);

  if (fd < 0)
    {
      perror ("OPEN faied\n");
      exit (1);
    }

  if (write (fd, ia, sizeof (int) * 16) != sizeof (int) * 16)
    perror (" Some thing wrong with write\n");


  close (fd);
}
