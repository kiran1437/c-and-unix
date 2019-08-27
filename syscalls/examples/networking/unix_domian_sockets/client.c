#include<sys/types.h>
#include<sys/socket.h>
#include <sys/un.h>

#include<errno.h>


#include<netinet/in.h>		/* for INADDRA_ANY */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
extern int errno;


main ()
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
  strncpy(serv_addr.sun_path,"/home/srini/UnixDomainSocket" , 
		  sizeof(serv_addr.sun_path)-1);



/* Refer to linux/ip.h for the format of the address. */


  ret = connect (sd, (struct sockaddr *) &serv_addr, sizeof (serv_addr));

  printf ("connect  returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }

  ret = write (sd, "Hello Sasken World", 21);
  printf ("write  returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }


  sleep(1200); 
}
