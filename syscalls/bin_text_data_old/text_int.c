#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


main ()
{
  int sa[16];
  int i;
  for (i = 0; i < 16; i++)
    sa[i] =  i * 0xffffff  + 1 ;

  int fd = open ("text_int_data", O_RDWR | O_CREAT);

  if (fd < 0)
    {
      perror ("OPEN faied\n");
      exit (1);
    }

  char buf[100];
  for( i=0;i<16;i++)
  {
  sprintf(buf, "%d\n", sa[i]);
  if( write(fd, buf, strlen(buf)) != strlen(buf))
       perror("Error writing\n");
  }
  close (fd);
}
