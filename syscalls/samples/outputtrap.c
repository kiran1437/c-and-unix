
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <sys/wait.h>
       #include <errno.h>
extern int errno;
#include<unistd.h>

main( int argc, char ** argv){
int status, readbytes;
int i;
char buff[256];
pid_t pid;
int p[2];

if ( pipe(p) < 0)
  { 
    printf("pipe failed: errno = %d\n", errno);
    exit(2);
  } 

if ( (pid = fork()) < 0)
     { 
      printf("errno = %d. FOrk failed \n", errno);
      exit(1);
     }

  

if ( pid == 0) 
   { 
    close(1);
    dup(p[1]);
    execlp("grep", "grep", argv[1], argv[2], NULL);
    // printf("Exec failed errno = %d\n", errno);
   } 
   else
   {
    close(p[1]);
    while( ( readbytes = read(p[0], buff, sizeof(buff))) > 0)
    {
        for ( i=0;i< readbytes;i++) buff[i] = toupper(buff[i]);
        write(1, buff, readbytes);
    }
    
    waitpid(pid, &status,0);
    if(WIFEXITED(status))
          printf( "exit status = %d\n", WEXITSTATUS(status));     

    } 
}

