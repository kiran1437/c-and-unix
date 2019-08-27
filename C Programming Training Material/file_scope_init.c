#include <stdio.h>
 
int a = 3 + 4 * 7 ;
int b = a * 6;          //ERROR
int c = sizeof(a)  * (int)6.8;          // Allowed
                                       //  HOW and WHY???
                  // constant expressions :C standard section 6.6  

int A[]={10,20,30,40};

int * ip1 = NULL;
int * ip2 = ip1;       // ERROR
int * ip3 = &a;        // Allowed

int d=A[2]+3;           // ERROR
int e=sizeof(A) + 3;     // Allowed
int * ip4 = A +  2 ;     // Allowed 
                        //  HOW and WHY???
                  // constant expressions :C standard section 6.6  

int main(int argc, char * argv[])
 {
int a = 3 + 4 * 7 ; 
int b = a * 6;    
int c = sizeof(b)  * (int)6.8;     

int A[]={10,20,30,40};

int * ip1 = NULL; 
int * ip2 = ip1;      
int * ip3 = &a;      

int d=A[2]+3;       
int e=sizeof(A) + 3; 
int * ip4 = A +  2 ; 


 return 0;
 }

/*   
 *
 *   f()
 *    {
 *
 *     int a;
 *     static int b = a; 
 *     int c = b;
       }
 */


















