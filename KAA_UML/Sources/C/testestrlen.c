#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char * argv [])
{
	char teste[20];
	strcpy(teste, "Karen");
	printf("strlen:%u\n", strlen (teste));

	return 0;

}
