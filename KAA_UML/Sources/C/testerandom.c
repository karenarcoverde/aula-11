




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
	char kaaUmlStringCreate [10];	


	resultado = KaaUmlCreateRandomString ("abc", 10, kaaUmlStringCreate);

	
		
	printf ("%s\n", KaaUmlGetCliErrorMessage (resultado, 0)); 
	printf ("%s\n", kaaUmlStringCreate);




	return 0;

}
