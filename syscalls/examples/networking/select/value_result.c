
void f( int * ip)
{
	printf("---%d---\n", *ip);
	// Value argument ....
}	

void g( int * ip)
{
	*ip =20;
	// Result  argument ....
}	

void h( int * ip)
{
	printf("---%d---\n", *ip);
	// Value argument ....
	*ip =30;
	// Result  argument ....
}	
//Value Result argument 

int main(int argc, char * argv[])
{


	int i=10;


	f(&i); 
	g(&i); 


	 return 0;
} 
