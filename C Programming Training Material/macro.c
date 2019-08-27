#include<stdio.h>
#define MAC1 "hello"
#define MAC2 "world"

#define MAC3 MAC1 MAC4
 # define    MAC4 "WORLD"


// #define MAC5 MAC5 MAC4



main()
{
printf("ONE"  "TWO" "THREE" "\n");
printf( MAC1  "\n");
printf(  MAC2 "\n");
printf( "MAC1" "\n");

/* #undef MAC3
*/
printf( MAC3 "\n");

printf("__DATE__ = %s\n",  __DATE__ );
printf("__FILE__ = %s\n",  __FILE__ );
printf("__LINE__ = %d\n", __LINE__);
printf("__LINE__ = %d\n", __LINE__);
printf("__STDC__ = %d\n",  __STDC__); 
printf("__STDC__ = %d\n",  __STDC_VERSION__); 
printf("__TIME__ = %s\n",  __TIME__ );
printf("__DATE__ = %s\n",  __DATE__ );

#define sqr1(  x   )  x * x
printf("sqr1(20) = %d\n", sqr1(20));
printf("sqr1(2 + 3) = %d\n", sqr1(2+3));


#define sqr2(  x   )  (x) * (x)
printf("sqr2(2 + 3) = %d\n", sqr2(2+3));
 
int i = 5, j=10,k=30;
printf("sqr2(i++) = %d\n", sqr2(i++));
i = 5;
printf("sqr2(++i) = %d\n", sqr2(++i));

#define pv(x,y)    printf("The value of " #x " is %d\n", y)


pv(i,i);
pv(j,j);
pv(k,k);


#define HOUSERENT "10000"
#define CARRENT   "2000"

#define HOUSENAME  "My Home"
#define CARNAME    "Ford"

#define r(x,y)      x ## y
printf("r(HOUSE,NAME) is %s\n", r(HOUSE,NAME) );
printf("r(HOUSE,RENT) is %s\n", r(HOUSE,RENT) );
printf("r(CAR,NAME) is %s\n", r(CAR,NAME) );
printf("r(CAR,RENT) is %s\n", r(CAR,RENT) );
	

#define max(a, b) ((a) > (b) ? (a) : (b))


i=10,j=20;

k= max(i++,j++);


   /*

int p,q;
i=10,j=20;

#define max(a, b)   ( p=a,   q=b,  ((p) > (q) ? (p) : (q))  )

#define max(a, b)   { p=a;   q=b;  ((p) > (q) ? (p) : (q))  }  

k= max(i++,j++);
k=  p=i++,  q=j++,   (............) 

*/


}

#define pvi(V)     printf("%-15s=%-12d\n",#V,V);
 
 

int tmp_a;
#define sqr3(x) ( tmp_a = x, tmp_a * tmp_a ) 

sqr3(++i) 











































































