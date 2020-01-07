


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


	resultado = KaaUmlCheckNickname ("karen sd-e arcoverde", KAA_UML_CHARACTER_NICKNAME_SET, KAA_UML_MINIMUM_NICKNAME_SIZE , KAA_UML_MAXIMUM_NICKNAME_SIZE);
	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 1)); 





	return 0;

}
