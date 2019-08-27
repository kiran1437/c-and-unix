#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void f(void) 

{ 
printf("last \n"); 
}

int main(int argc, char * argv[]) 
{

atexit(f);

sleep(5);

}

