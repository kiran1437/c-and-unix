#include<sys/types.h>
#include<sys/socket.h>

#include<errno.h>
#include <stdio.h>
 

#include<netinet/in.h>		/* for INADDR_ANY */
extern int errno;


main ()
{
  int ret;

  int stream_sd;
  stream_sd = socket (AF_INET, SOCK_STREAM, 0);

  printf ("stream_sd = %d\n", stream_sd);
  if (stream_sd == -1)
    {
      printf ("stream_sd = %d, errno = %d\n", errno);
      exit (1);
    }


  struct sockaddr_in stream_serv_addr;

  memset (&stream_serv_addr, 0, sizeof (stream_serv_addr));

  stream_serv_addr.sin_family = PF_INET;
  stream_serv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
  stream_serv_addr.sin_port = htons (1500);



/* Refer to linux/ip.h for the format of the address. */


  ret =
    bind (stream_sd, (struct sockaddr *) &stream_serv_addr,
	  sizeof (stream_serv_addr));

  printf ("bind returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }



  ret = listen (stream_sd, 10);
  printf ("listen returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", ret, errno);
      exit (1);
    }

/* Stream socket is now in a position to wait for connection requests.

   Now, create a datagram socket and set it up */


  int dgram_sd;
  dgram_sd = socket (AF_INET, SOCK_DGRAM, 0);

  printf ("dgram_sd = %d\n", dgram_sd);
  if (dgram_sd == -1)
    {
      printf ("dgram_sd = %d, errno = %d\n", errno);
      exit (1);
    }


  struct sockaddr_in dgram_serv_addr;

  memset (&dgram_serv_addr, 0, sizeof (dgram_serv_addr));

  dgram_serv_addr.sin_family = PF_INET;
  dgram_serv_addr.sin_addr.s_addr = htonl (INADDR_ANY);
  dgram_serv_addr.sin_port = htons (1500);


/* Refer to linux/ip.h for the format of the address. */


  ret =
    bind (dgram_sd, (struct sockaddr *) &dgram_serv_addr,
	  sizeof (dgram_serv_addr));

  printf ("bind returned = %d\n", ret);
  if (ret == -1)
    {
      printf ("ret = %d, errno = %d\n", errno);
      exit (1);
    }

/* Datagram socket also ready to receive requests.

   Now, just wait in a select call. */

  fd_set read_fdset;
  struct timeval timeout;
  int select_ret;

  while(1) 
  {

  FD_ZERO (&read_fdset);
  FD_SET (stream_sd, &read_fdset);
  FD_SET (dgram_sd, &read_fdset);

  /* Well let the server run only for half an hour. 

     Ideal choice would be to pass NULL as the fifth argument to 
     select. This will make the select call wait indefinitely 
   */

  timeout.tv_sec = 1800;
  timeout.tv_usec = 0;

  select_ret = select (dgram_sd + 1, &read_fdset, NULL, NULL, &timeout);


  printf ("select returned = %d\n", select_ret);
  if (select_ret == -1)
    {
      printf ("ret = %d, errno = %d\n", select_ret, errno);
      exit (1);
    }


  if (!select_ret)
    {
      printf ("Server Completed\n");
      exit (0);
    }

  if (select_ret > 0)

    {


      if (FD_ISSET (stream_sd, &read_fdset))
	{
/* Stream connection establisment */
	  struct sockaddr_in stream_from_addr;
	  char buf[4096];
	  int stream_fromsize = sizeof (struct sockaddr_in);
	  int connected_stream_sd;

	  connected_stream_sd =
	    accept (stream_sd, (struct sockaddr *) &stream_from_addr,
		    &stream_fromsize);
	  printf ("accept returned = %d\n", connected_stream_sd);
	  if (connected_stream_sd == -1)
	    {
	      printf ("ret = %d, errno = %d\n", connected_stream_sd, errno);
	      exit (1);
	    }


	  ret = read (connected_stream_sd, buf, 4096);
	  printf ("listen returned = %d\n", ret);
	  if (ret == -1)
	    {
	      printf ("ret = %d, errno = %d\n", ret, errno);
	      exit (1);
	    }

	  printf ("-STREAM: %s-\n", buf);


	}

      if (FD_ISSET (dgram_sd, &read_fdset))
	{

	  struct sockaddr_in dgram_from_addr;
	  char buf[4096];
	  int dgram_fromsize = sizeof (struct sockaddr_in);
	  ret =
	    recvfrom (dgram_sd, buf, 4096, 0,
		      (struct sockaddr *) &dgram_from_addr, &dgram_fromsize);

	  printf ("recv returned = %d\n", ret);
	  if (ret == -1)
	    {
	      printf ("ret = %d, errno = %d\n", ret, errno);
	      exit (1);
	    }

	  printf ("DGRAM -%s-\n", buf);

	}
    }

  } 
}
