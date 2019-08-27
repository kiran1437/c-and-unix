#include <stdio.h>
#include <stdint.h> 
#include <limits.h> 

void display32bits( uint32_t num)
{
	unsigned int i,mask=0x80000000; 

	printf("%#010x--% -11d--", num,num); 
	for ( i =0;i<32;i++)
	{
/* > has higher precendence than & so () is required ...  */
		printf("%d", (mask&num)>0);  
		mask >>=1;
		if  ( (i+1)  % 4 == 0 )  printf(" ");   
	}
	printf("\n"); 
} 

void displayu32bits( uint32_t num)
{
	unsigned int i,mask=0x80000000U; 

	printf("%#010x--% -11d--", num,num); 
	for ( i =0;i<32;i++)
	{
/* > has higher precendence than & so () is required ...  */
		printf("%u", (mask&num)>0);  
		mask >>=1;
		if  ( (i+1)  % 4 == 0 )  printf(" ");   
	}
	printf("\n"); 
} 

int main(int argc, char * argv[])
{

	display32bits(0);
	display32bits(23);
	display32bits(INT_MAX );
	display32bits(INT_MIN );
	display32bits(-1); 
	display32bits(-2); 
	display32bits(-3); 
 
	unsigned int ui;  
/*  Positive zero    */
	ui = 0; 
	displayu32bits(ui);
	ui = 23;
	displayu32bits(ui); 
	displayu32bits(UINT_MAX );
}

