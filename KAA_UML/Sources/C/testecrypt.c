#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "kaaUmlTypes.h"
#include "kaaUmlConst.h"
#include "kaaUmlErrors.h"
#include "kaaUmlFunctions.h"

int
main (int argc, char * argv [])
{
	kaaUmlErrorType resultado; 
	kaaUmlCryptAlgorithms kaaUmlCryptAlgorithmType;


	resultado = KaaUmlGetCryptAlgorithm ("$1$qer$trkvqwertyuiopasdfghjk", &kaaUmlCryptAlgorithmType);

	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 1)); 
	printf ("%d\n", kaaUmlCryptAlgorithmType); 



	return 0;

}
