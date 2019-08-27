#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void f(void) 

{ 
printf("last \n"); 
}


/* have to call exit(3) in the signal handler to get the 
   exit handelrs to be called.
*/
void f1(int a) { exit(1); } 

int main(int argc, char * argv[]) 
{

atexit(f);

signal(SIGTERM,f1);

sleep(50);

}

