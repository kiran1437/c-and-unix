#include<sys/types.h>
#include<sys/socket.h>

#include<errno.h>


#include<netinet/in.h>		/* for INADDR_ANY */
extern int errno;


main ()
{
  int ret;

  int sd;
  sd = socket (AF_INET, SOCK_DGRAM, 0);

  printf ("sd = %d\n", sd);
  if (sd == -1)
    {
      printf ("sd = %d, errno = %d\n", errno);
      exit (1);
    }


  struct sockaddr_in serv_addr;

  memset (&serv_addr, 0, sizeof (serv_addr));

  serv_addr.sin_family = PF_INET;
  serv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
  serv_addr.sin_port = htons (1500);


/* Refer to linux/ip.h for the format of the address. */


  ret = bind (sd, (struct sockaddr *) &serv_addr, sizeof (serv_addr));

  printf ("bind returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }

  struct sockaddr_in from_addr;
  char buf[4096];

  while(1) 
  {
  int fromsize = sizeof (struct sockaddr_in);
  ret =
    recvfrom (sd, buf, 4096, 0, (struct sockaddr *) &from_addr, &fromsize);

  printf ("recv returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", ret, errno);
      exit (1);
    }

  printf ("-%s-\n", buf);
  }
}
