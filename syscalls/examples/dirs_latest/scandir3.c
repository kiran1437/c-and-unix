#include<sys/types.h>
#include<dirent.h>


int  select_num(const struct dirent * d)
{
int i;

for ( i=0; i< strlen(d->d_name);i++)
    if( ! isdigit(d->d_name[i]))
            return 0;
return 1;

}

int compare_num(const struct dirent ** d1, const struct dirent **d2)
{

return( -strverscmp( (*d1)->d_name, (*d2)->d_name));

}



main ()
{
          struct dirent **namelist;
           int n;
                                                                                
           n = scandir("./test", &namelist, select_num, compare_num);
           if (n < 0)
               perror("scandir");
           else {
               while(n--) {
                   printf("%s\n", namelist[n]->d_name);
                   free(namelist[n]);
               }
               free(namelist);
           }

  

}
