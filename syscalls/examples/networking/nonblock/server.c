#include<sys/types.h>
#include<sys/socket.h>
#include <stdio.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/stat.h>
#include<netinet/in.h>		/* for INADDR_ANY */
extern int errno;

void
sigio_handler (int sig)
{
	fprintf(stderr, "Handler\n"); 
//	fflush(stdout); 
	exit(20);

}

main ()
{
  int ret;

  signal (SIGINT, sigio_handler);
  int stream_sd;
  stream_sd = socket (AF_INET, SOCK_STREAM, 0);

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

  if (ret == -1)
    {
      fprintf (stderr, "Stream socket bind returned  = %d, errno = %d\n", errno);
      exit (1);
    }



  ret = listen (stream_sd, 10);
  if (ret == -1)
    {
      printf ("listen returned = %d, errno = %d\n", ret, errno);
      exit (1);
    }

/* Stream socket is now in a position to wait for connection requests.

   Now, create a datagram socket and set it up */


  int dgram_sd;
  dgram_sd = socket (AF_INET, SOCK_DGRAM, 0);

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

  if (ret == -1)
    {
      fprintf (stderr, "Dgram socket bind returned  = %d, errno = %d\n", errno);
      exit (1);
    }

/* Datagram socket also ready to receive requests. */
  int socket_flags = fcntl (stream_sd, F_GETFL, 0);
  if (socket_flags == -1)
    {
      printf ("socket_flags = %d, errno = %d\n", socket_flags, errno);
      exit (1);
    }


  socket_flags = fcntl (stream_sd, F_SETFL, socket_flags | O_NONBLOCK);
  if (socket_flags == -1)
    {
      printf ("socket_flags = %d, errno = %d\n", socket_flags, errno);
      exit (1);
    }


  socket_flags = fcntl (dgram_sd, F_GETFL, 0);
  if (socket_flags == -1)
    {
      printf ("socket_flags = %d, errno = %d\n", socket_flags, errno);
      exit (1);
    }


  socket_flags = fcntl (dgram_sd, F_SETFL, socket_flags | O_NONBLOCK);
  if (socket_flags == -1)
    {
      printf ("socket_flags = %d, errno = %d\n", socket_flags, errno);
      exit (1);
    }

  for (;;)
    {
      {
/* Stream connection establisment */
	struct sockaddr_in stream_from_addr;
	char buf[4096];
	int stream_fromsize = sizeof (struct sockaddr_in);
	int connected_stream_sd;

	connected_stream_sd =
	  accept (stream_sd, (struct sockaddr *) &stream_from_addr,
		  &stream_fromsize);

/* Since we set the NONBLOCK flag on stream_sd, it ok we get error 
   and errno == EGAIN.  Indicates no connection 
   request is waiting and we can test for this again later */

	if (connected_stream_sd == -1 && errno != EAGAIN)
	  {
	    printf ("accept ret = %d, errno = %d\n", connected_stream_sd,
		    errno);
	    exit (1);
	  }


	if (connected_stream_sd >= 0)
	  {

	    ret = read (connected_stream_sd, buf, 4096);
	    if (ret == -1)
	      {
		printf (" read ret = %d, errno = %d\n", ret, errno);
		exit (1);
	      }

	    printf ("-STREAM: %s-\n", buf);

	  }
      }

      {

	struct sockaddr_in dgram_from_addr;
	char buf[4096];
	int dgram_fromsize = sizeof (struct sockaddr_in);
	ret =
	  recvfrom (dgram_sd, buf, 4096, 0,
		    (struct sockaddr *) &dgram_from_addr, &dgram_fromsize);

	if (ret == -1)
	  {
	    if (errno == EAGAIN)
	      continue;
	    printf (" recv from ret = %d, errno = %d\n", ret, errno);
	    exit (1);
	  }

	printf ("DGRAM -%s-\n", buf);

      }
    }

}
