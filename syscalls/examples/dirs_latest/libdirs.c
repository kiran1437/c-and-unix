#include<sys/types.h>
#include<dirent.h>


main ()
{
  DIR *D = opendir ("/home/srini");
  struct dirent *ent;

/*struct dirent
	         {
	         long d_ino;                   inode number 
	         off_t d_off;                  offset to next dirent 
	         unsigned short d_reclen;     length of this dirent 
	         char d_name [NAME_MAX+1];    file name (null-terminated) 
	         }
   Only portable field in dirent structure is d_name. 
   Next imp field is long d_ino.  Refer to man page of getdents(2) 
   for other fields of dirent.
*/

  if (D == 0)
    {
      printf ("NULL on open dir \n");
      exit (1);
    }

  while (ent = readdir (D))
    printf ("Name=%s, Inode num = %d\n", ent->d_name, ent->d_ino);
  closedir(D);

}
