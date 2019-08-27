 #include <stdio.h>

int main(int argc, char * argv[])
 {
 printf("Hello world\n");

 fprintf(stderr, "Error message \n"); 
 fopen("/etc/passwd", "r+"); 
 perror("errmesg"); 
 
 return 0;
 } 
