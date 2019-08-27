#include<sys/types.h>
#include<dirent.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/kdev_t.h>
#include<errno.h>
extern int errno;


main (int argc, char ** argv)
{
  DIR *D = opendir ("dir1");
  struct dirent *ent;
  struct stat stat_buf;

  if (D == 0)
    {
      printf ("NULL on open dir \n");
      exit (1);
    }


/* Only portable field in dirent structure is d_name. 
   Next imp field is long d_ino.  Refer to man page of getdents(2) 
   for other fields of dirent. 
*/
  char filename[40];
  
  mode_t ft;

  while (ent = readdir (D))
  {
    sprintf(filename,"dir1/%s",ent->d_name);
    printf ("Name =%-20s", 
          ent->d_name);

    /* If stat() is used next, it will not work for sym links.*/ 
    memset(&stat_buf, 0, sizeof( stat_buf)); 
    if( lstat(filename, &stat_buf) < 0)
       printf("Error stat, errno = %d\n", errno);
     else 
       printf("in=%-15d mode=%-15o \n size=%-15d", 
                stat_buf.st_ino, stat_buf.st_mode,stat_buf. 
                 st_size);
     
              

     ft = stat_buf.st_mode & S_IFMT;
     if( ft == S_IFLNK) printf( "%-10s","Link");
     if( ft == S_IFREG) printf("%-10s","Regulur");
     if( ft == S_IFBLK) printf("%-10s","Block ");
     if( ft == S_IFDIR) printf("%-10s","Dir");
     if( ft == S_IFCHR) printf("%-10s","Char");

     if( ft == S_IFCHR || ft == S_IFBLK) 
       printf("device=%#016x\n", stat_buf.st_rdev);
     else
       printf("device=%#016x\n", stat_buf.st_dev);
       
   }

}
