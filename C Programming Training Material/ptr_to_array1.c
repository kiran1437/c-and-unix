#include<stdio.h>

main()
{

	int A[3][4];
	int (*ptr_to_array)[4];

    int i, j,k=0;

	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			A[i][j] = ++k;

	printf("sizeof(A)=%d\n", sizeof(A));
	printf("sizeof(A[0])=%d sizeof(A[1])=%d\n",
            sizeof(A[0]), sizeof(A[1]));
	printf("sizeof(A[0][0])=%d\n", 
		                 sizeof(A[0][0]));
	
	printf("sizeof(ptr_to_array)=%d\n",
		         sizeof(ptr_to_array));
	printf("sizeof(*ptr_to_array)=%d\n", 
		            sizeof(*ptr_to_array));

	ptr_to_array = &A[0];  /* A;  */

       /* could have been A it self!!
          &A[0]= &(A[0])  = &(* ( A +0 )  ) = 
                                    &(* (A) ) = &*A = A  */ 



	for(j=0;j<4;j++)
		printf("(*ptr_to_array)[%d]=%d\n", 
		      j,(*ptr_to_array)[j]);

	ptr_to_array ++;

	for(j=0;j<4;j++)
		printf("(*ptr_to_array)[%d]=%d\n", 
		    j,(*ptr_to_array)[j]);

	ptr_to_array ++;

	for(j=0;j<4;j++)
		printf("(*ptr_to_array)[%d]=%d\n", 
		      j,(*ptr_to_array)[j]);

	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
		printf("A[%d][%d]=%d\n", i,j,A[i][j]);
}
