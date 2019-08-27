#include<sys/types.h>
#include<sys/ipc.h>

int
main ()
{
  printf ("The key = %x\n", ftok ("project", 48));
/*
The key is : Second arg char, 
             lsB of the dev number on which the file resides, minor num
             two lsB of inode number.
*/

}
