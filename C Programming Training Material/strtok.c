#include <stdio.h>

#include <string.h>

#define pvstr(V)   printf("%-20s=%-20s\n", #V,V)
  
int main(int argc, char * argv[])
 {
  char *token=NULL; 
  char   emp[]     = "sam:finance:40000:loans"; 
  pvstr(emp);
  
  token =  strtok(emp,":");
  pvstr(token); 
  pvstr(emp);

  token =  strtok(NULL,":");
  pvstr(token); 
  pvstr(emp);

   
  token =  strtok(NULL,":");
  pvstr(token); 
  pvstr(emp);

  token =  strtok(NULL,":");
  pvstr(token); 
  pvstr(emp);

  token =  strtok(NULL,":");
  pvstr(token); 
  pvstr(emp);
 return 0;
 }  
