#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <string.h>
       #include <unistd.h>
       #include <errno.h>
extern int errno;

/* reads seem to go fine until the first write() call. 
   Write() sets the offset to the end of file and reads return 0 
   after that. So, after every write we need to set the offset 
   to some where within the file. 
*/ 

main()
{
int fd;
off_t offset;
 if((fd = open("t10", O_RDWR|O_APPEND)) < 0)
         { printf("open error, %d\n",errno); exit (1) ;}

char buf[256];
memset(buf, 0, sizeof(buf));

 offset = lseek( fd, 0, SEEK_CUR);
 if( read(fd, buf, 5)< 0)
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d sizeof(offset) = %d.\n", 
                     buf, offset, sizeof(offset));

 offset = lseek( fd, 0, SEEK_CUR);
 if( read(fd, buf, 5)< 0)
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);

 offset = lseek( fd, 0, SEEK_CUR);
 if( read(fd, buf, 5)< 0)
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);

 offset = lseek( fd, 0, SEEK_CUR);
     printf("offset= %d\n",offset); 
  
 if( write(fd, "hello ", 6)< 0)
         { printf("read error, %d\n",errno); exit (1) ;}
 offset = lseek( fd, 0, SEEK_CUR);
         { printf("offset after write=%d\n", offset);}

 offset = lseek( fd, 0, SEEK_CUR);
 int read_ret ;
 read_ret = read(fd, buf, 5);
 printf("Read returned = %d\n", read_ret);
 if(read_ret<0) 
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);

 offset = lseek( fd, 0, SEEK_CUR);
 read_ret = read(fd, buf, 5);
 printf("Read returned = %d\n", read_ret);
 if(read_ret<0) 
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);


 /* Here we set the offset with SEEK_SET. 
    After this reads go well. */ 
 offset = lseek( fd, 20, SEEK_SET);
 read_ret = read(fd, buf, 5);
 printf("Read returned = %d\n", read_ret);
 if(read_ret<0) 
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);

 offset = lseek( fd, 0, SEEK_CUR);
 read_ret = read(fd, buf, 5);
 printf("Read returned = %d\n", read_ret);
 if(read_ret<0) 
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);

 offset = lseek( fd, 0, SEEK_CUR);
 read_ret = read(fd, buf, 5);
 printf("Read returned = %d\n", read_ret);
 if(read_ret<0) 
         { printf("read error, %d\n",errno); exit (1) ;}
	else printf("Read -%s- offset = %d.\n", buf, offset);
}
