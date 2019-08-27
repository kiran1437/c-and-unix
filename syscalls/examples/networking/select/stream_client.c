#include<sys/types.h>
#include<sys/socket.h>

#include<errno.h>
#include <stdio.h>
 

#include<netinet/in.h>		/* for INADDRA_ANY */
extern int errno;


main ()
{
  int ret;

  int sd;
  sd = socket (PF_INET, SOCK_STREAM, 0);

  printf ("sd = %d\n", sd);
  if (sd == -1)
    {
      printf ("sd = %d, errno = %d\n", errno);
      exit (1);
    }


  struct sockaddr_in serv_addr;

  memset (&serv_addr, 0, sizeof (serv_addr));


  serv_addr.sin_family = PF_INET;
  if (inet_pton (AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr) <= 0)
    {
      printf ("inet_pton ERROR. errno is %d\n", errno);
      exit (1);
    }


  serv_addr.sin_port = htons (1500);


/* Refer to linux/ip.h for the format of the address. */


  ret = connect (sd, (struct sockaddr *) &serv_addr, sizeof (serv_addr));

  printf ("connect  returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }

  ret = write (sd, "Hello WOrld", 12);
  printf ("write  returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }


}
