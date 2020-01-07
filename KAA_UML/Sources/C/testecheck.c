


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
	/*kaaUmlCryptAlgorithms kaaUmlDes;*/
	char  kaaUmlEncodedPassword [200];

	resultado = KaaUmlCheckPassword ("qwqewq", "qwertyuiopasd");

	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 0));
	printf ("%s\n", kaaUmlEncodedPassword); 



	return 0;

}
