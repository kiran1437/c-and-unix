#include<stdio.h>
main()
{

int i;

char str [20], c;

scanf("%d", &i);


/*do{
  c = getchar();
  }while(c == ' '|| c== '\t'|| c=='\n');

 if ( c !=EOF) ungetc(c, stdin);
*/


gets(str);

printf("i=%d,str=%s\n", i, str);

}
