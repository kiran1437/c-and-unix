#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


main ()
{
  short sa[16];
  int i;
  for (i = 0; i < 16; i++)
    sa[i] = 0XFF00 + i;

  int fd = open ("bin_short_data", O_RDWR | O_CREAT);

  if (fd < 0)
    {
      perror ("OPEN faied\n");
      exit (1);
    }

  if (write (fd, sa, sizeof (short) * 16) != sizeof (short) * 16)
    perror (" Some thing wrong with write\n");


  close (fd);
}
