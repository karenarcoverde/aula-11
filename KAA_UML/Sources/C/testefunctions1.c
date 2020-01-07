

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


	resultado = KaaUmlCheckStringField ("karen.arcoverde", "karen.covd",0 , 25);
	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 1)); 





	return 0;

}
