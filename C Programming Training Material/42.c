#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h> 

#define pvi(V) printf("%-15s=%-12d\n",#V,V);
#define pvs(V) printf("%-15s=%s\n",#V,V); 

int
saveformated (char * filename, int num_emp_pairs, ...)
{
  assert(filename != NULL);
  pvs(filename);  
  pvi (num_emp_pairs);

  FILE* fp; 
  assert(fp=fopen(filename,"w")); 

  va_list ap;
  va_start (ap, num_emp_pairs);
  while (num_emp_pairs--> 0)
    {
     int id; 
     char name[50];
     id = va_arg(ap,int);
     strcpy(name, va_arg(ap,char *));
     assert( fprintf(fp,"%10d  %s\n",id,name));
    }
  va_end(ap);
}

int
main (int argc, char *argv[])
{
 
  saveformated("xy", 2, 
                        10,"hello   ", 
                        30, "world");
  saveformated("abc", 4, 
			230,"hello   ", 
			280, "world",
			800, "Cprograms",
			1000, "Last rec" );

  return 0;


}
