#include<sys/types.h>
#include<sys/socket.h>

#include<errno.h>


#include<netinet/in.h>		/* for INADDRA_ANY */
extern int errno;


main ()
{
  int ret;

  int sd;
  sd = socket (PF_INET, SOCK_DGRAM, 0);

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

  struct sockaddr_in from_addr;
  char buf[4096];
  int fromsize = sizeof (struct sockaddr_in);

  memset (buf, 0, sizeof (buf));
  strcpy (buf, "hello world");

  ret = sendto (sd, buf, 12, 0, (struct sockaddr *) &serv_addr, fromsize);

  printf ("sendto returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }


ret =
  recvfrom (sd, buf, 4096, 0, (struct sockaddr *) &serv_addr, &fromsize);

printf ("recv returned = %d\n remote port is %d\n", ret,
		  serv_addr.sin_port);



printf ("recv returned = %d\n", ret);
if (ret == -1)
  {
    printf ("ret = %d, errno = %d\n", ret, errno);
    exit (1);
  }

  printf ("-%s-\n", buf);




}
