#include<sys/types.h>
#include<sys/socket.h>
#include <sys/un.h>

#include<errno.h>


#include<netinet/in.h>		/* for INADDR_ANY */
extern int errno;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
  int ret;

  int sd;
  sd = socket (AF_UNIX, SOCK_STREAM, 0);

  printf ("sd = %d\n", sd);
  if (sd == -1)
    {
      printf ("sd = %d, errno = %d\n", errno);
      exit (1);
    }


  struct sockaddr_un serv_addr;

  memset (&serv_addr, 0, sizeof (serv_addr));

  serv_addr.sun_family = PF_UNIX;
  strncpy(serv_addr.sun_path, "/home/srini/UnixDomainSocket", 
		  sizeof(serv_addr.sun_path)-1);



/* Refer to linux/ip.h for the format of the address. */


  ret = bind (sd, (struct sockaddr *) &serv_addr, sizeof (serv_addr));

  printf ("bind returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", ret, errno);
      exit (1);
    }



  ret = listen (sd, 10);
  printf ("listen returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", ret, errno);
      exit (1);
    }

  struct sockaddr_in from_addr;
  char buf[4096];
  int fromsize = sizeof (struct sockaddr_in);
  int connected_sd;

  while( 1) 
  {
  connected_sd = accept (sd, (struct sockaddr *) &from_addr, &fromsize);
  printf ("accept returned = %d\n", connected_sd);
  if (connected_sd == -1)
    {
      printf ("ret = %d, errno = %d\n", connected_sd, errno);
      exit (1);
    }


  ret = read (connected_sd, buf, 4096);
  printf ("listen returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", ret, errno);
      exit (1);
    }

  printf ("-%s-\n", buf);
  } 
}
