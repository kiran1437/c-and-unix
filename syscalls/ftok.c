#include<sys/types.h>
#include<sys/ipc.h>

int
main ()
{
  printf ("File = %s, Prj id = %d, key = %x\n", 
                   "prjfile1",32, ftok ("prjfile1", 32));

  printf ("File = %s, Prj id = %d, key = %x\n", 
                   "prjfile2",80, ftok ("prjfile2", 80));

  printf ("File = %s, Prj id = %d, key = %x\n", 
                   "prjfile3",16, ftok ("prjfile3", 16));

  printf ("File = %s, Prj id = %d, key = %x\n", 
                   "prjfile4",48, ftok ("prjfile4", 48));
/*
The four bytes in the generated key are : 
First byte:  Second arg to ftok which shold have one byte value.
Second byte: The minor number of the device  on which the file resides.
Third and fourth bytes: The two least siignificant bytes of the 
inode number of the file. 
*/

}
