





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
	char kaaUmlSecondNickname [65];
	char kaaUmlFirstNickname [65];


	resultado = KaaUmlCreateNickname ("q qwer qwer qwer qw qw", kaaUmlFirstNickname, kaaUmlSecondNickname);

	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 0)); 
	printf ("%s\n", kaaUmlFirstNickname);
	printf ("%s\n", kaaUmlSecondNickname);



	return 0;

}
