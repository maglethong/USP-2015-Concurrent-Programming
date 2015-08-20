#include "config.h"
#include "jacobi.h"

#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[])
{
	Jacobi jacobi;
	int error;

	// Init
	if( Jacobi_Init(&jacobi) )
	{
		printf("Allocation error!");
		Jacobi_Destroy(&jacobi);
		return 0;
	}

	// Debug
	Jacobi_Debug(&jacobi);

	// Preprocess
	if( error = Jacobi_Preprocess(&jacobi) )
	{
		printf("Error #%dp!", error);
		Jacobi_Destroy(&jacobi);
		return 0;
	}

	// Init x1
	Jacobi_InitUnknowns(&jacobi);

	// Debug
	Jacobi_Debug(&jacobi);

	// Jacobi Iterations
	Jacobi_Run(&jacobi, PRECISION);

	// End
	Jacobi_Destroy(&jacobi);
	return 0;
}