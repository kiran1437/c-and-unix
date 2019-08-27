#include <stdio.h>

#define HASHTABLESIZE 10
#define NUMSLOTS       2  

#define ENDOFINPUT    -1
#define OVERFLOW      -2

typedef struct emp { int id; char name [20]; } Emp;

Emp hashtable[HASHTABLESIZE][NUMSLOTS]; 
/* Assume zero for id indicates slot empty */

void displayemp( Emp emp)
{
	printf("Id:%d\t\t%s",emp.id, emp.name ); 
} 

int  addemp(void)
{

	Emp emp;
	int i;
	if ( isatty(0) ) 
		printf("Enter id (^d to end)  and name :"); 

	if ( scanf("%d",&emp.id) == EOF  ) 
		return ENDOFINPUT;

	fgets(emp.name, sizeof( emp.name), stdin);
	emp.name[sizeof(emp.name) -1] =0;
	for(i=0; emp.name[i] ; i++) 
		if ( emp.name[i]=='\n') { emp.name[i] = 0; break;}   


	int index = emp.id % HASHTABLESIZE;


	if ( hashtable[index][0].id == 0 )  
		hashtable[index][0] = emp;
	else 
		if ( hashtable[index][1].id == 0 )  
			hashtable[index][1] = emp;
		else
		{
			printf("\nOver flow for id = %d\n the following records present:\n", emp.id);
			displayemp( hashtable[index] [0]  );
			printf("\n"); 
			displayemp( hashtable[index] [1]  );
			return   OVERFLOW;
		}

	return emp.id;

} 

int buildhash (void)
{
	int ret; 

	while( (ret = addemp())  != ENDOFINPUT) ;

} 

void displayhash(void)
{

	int i;

	for ( i=0;i<HASHTABLESIZE;i++)
	{
		printf("\n"); 
		printf("HASH[%d]:\t\t" ,  i ) ; 

		if( hashtable[i][0].id  != 0) 
		{	displayemp(hashtable[i][0]);

		}
		if( hashtable[i][1].id  != 0) 
		{	
			printf("\n\t\t\t"); 
			displayemp(hashtable[i][1]);
		}
	} 
	printf("\n"); 

} 
int main(int argc, char * argv[])
{

	buildhash();
	displayhash();
	return 0;
} 
