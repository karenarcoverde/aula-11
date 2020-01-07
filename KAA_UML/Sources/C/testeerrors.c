

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "kaaUmlTypes.h"
#include "kaaUmlErrors.h"

int
main (int argc, char * argv [])
{
       

	printf ("%s\n", KaaUmlGetCliErrorMessage (1,0));
	printf ("%s\n", KaaUmlGetCliErrorMessage (1,1));

	return 0;

}
