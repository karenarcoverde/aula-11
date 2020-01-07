



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


	resultado = KaaUmlCheckEmail ("karenarcoverdepoli.ufrj.br", KAA_UML_CHARACTER_CHECK_EMAIL_SET, KAA_UML_MINIMUM_CHECK_EMAIL_SIZE, KAA_UML_MAXIMUM_CHECK_EMAIL_SIZE);
	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 1)); 





	return 0;

}
