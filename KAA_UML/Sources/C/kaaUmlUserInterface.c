/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/11/05 15:41:40 $
 * $Log: kaaUmlUserInterface.c,v $
 * Revision 1.4  2018/11/05 15:41:40  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/03 20:56:35  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/03 20:55:13  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/03 18:44:42  karen.arcoverde
 * Initial revision
 *
 *
 */


#include "kaaUmlUserInterface.h"
#include "kaaUmlTypes.h"
#include "kaaUmlErrors.h"


char *kaaUmlCliUserInterfaceMessages [kaaUmlLanguageAmount] [kaaUmlUserInterfaceStringAmount] =
{
	{
		"Enter",
		"Help"
	},
	
	{
		"Entrar",
		"Ajuda"
	}
};





char *kaaUmlNcursesUserInterfaceMessages [kaaUmlLanguageAmount] [kaaUmlUserInterfaceStringAmount] =
{
	{
		"Enter",
		"Help"
	},
	
	{
		"Entrar",
		"Ajuda"
	}
};





char *kaaUmlWebUserInterfaceMessages [kaaUmlLanguageAmount] [kaaUmlUserInterfaceStringAmount] =
{
	{
		"Enter",
		"Help"
	},
	
	{
		"Entrar",
		"Ajuda"
	}
};






/*
 * char *
 * KaaUmlGetCliUserInterfaceMessage (kaaUserInterfaceMessageNumberType, kaaUmlLanguageType);
 *
 * Arguments:
 * kaaUmlUserInterfaceMessageNumberType - details what is the number of message we want to show (I)
 * kaaUmlLanguageType - say in what language do we see the message output (I)
 *
 * Returned code:
 * char * - Is the message converted 
 *
 * Description:
 * This function converts the message from a code to the wanted language - works only for Comand Line arguments
 */

char *
KaaUmlGetCliUserInterfaceMessage (kaaUmlUserInterfaceMessageNumberType kaaUmlUserInterfaceMessageNumber, kaaUmlLanguageType kaaUmlLanguageCode)
{
	if ((kaaUmlUserInterfaceMessageNumber < 0) || (kaaUmlUserInterfaceMessageNumber >= kaaUmlUserInterfaceStringAmount))
	      return KaaUmlGetCliErrorMessage (kaaUmlErrorGettingInterfaceMessage, kaaUmlLanguageCode);

	if ((kaaUmlLanguageCode < 0) || (kaaUmlLanguageCode >= kaaUmlLanguageAmount))
		kaaUmlLanguageCode = 0;	/* if is not possible to identify the language, return english */
	
	return kaaUmlCliUserInterfaceMessages [kaaUmlLanguageCode] [kaaUmlUserInterfaceMessageNumber];	
}	





/*
 * char *
 * KaaUmlGetNcursesUserInterfaceMessage (kaaUserInterfaceMessageNumberType, kaaUmlLanguageType);
 *
 * Arguments:
 * kaaUmlUserInterfaceMessageNumberType - details what is the number of message we want to show (I)
 * kaaUmlLanguageType - say in what language do we see the message output (I)
 *
 * Returned code:
 * char * - Is the message converted 
 *
 * Description:
 * This function converts the message from a code to the wanted language - works only for Ncurses Interface
 */

char *
KaaUmlGetNcursesUserInterfaceMessage (kaaUmlUserInterfaceMessageNumberType kaaUmlUserInterfaceMessageNumber, kaaUmlLanguageType kaaUmlLanguageCode)
{
	if ((kaaUmlUserInterfaceMessageNumber < 0) || (kaaUmlUserInterfaceMessageNumber >= kaaUmlUserInterfaceStringAmount))
		return KaaUmlGetNcursesErrorMessage (kaaUmlErrorGettingInterfaceMessage, kaaUmlLanguageCode);

	if ((kaaUmlLanguageCode < 0) || (kaaUmlLanguageCode >= kaaUmlLanguageAmount))
		kaaUmlLanguageCode = 0;	/* if is not possible to identify the language, return english */
	
	return kaaUmlNcursesUserInterfaceMessages [kaaUmlLanguageCode] [kaaUmlUserInterfaceMessageNumber];	
}	






/*
 * char *
 * KaaUmlGetWebUserInterfaceMessage (kaaUserInterfaceMessageNumberType, kaaUmlLanguageType);
 *
 * Arguments:
 * kaaUmlUserInterfaceMessageNumberType - details what is the number of message we want to show (I)
 * kaaUmlLanguageType - say in what language do we see the message output (I)
 *
 * Returned code:
 * char * - Is the message converted 
 *
 * Description:
 * This function converts the message from a code to the wanted language - works only for Web Interface
 */

char *
KaaUmlGetWebUserInterfaceMessage (kaaUmlUserInterfaceMessageNumberType kaaUmlUserInterfaceMessageNumber, kaaUmlLanguageType kaaUmlLanguageCode)
{
	if ((kaaUmlUserInterfaceMessageNumber < 0) || (kaaUmlUserInterfaceMessageNumber >= kaaUmlUserInterfaceStringAmount))
	      return KaaUmlGetWebErrorMessage (kaaUmlErrorGettingInterfaceMessage, kaaUmlLanguageCode);

	if ((kaaUmlLanguageCode < 0) || (kaaUmlLanguageCode >= kaaUmlLanguageAmount))
		kaaUmlLanguageCode = 0;	/* if is not possible to identify the language, return english */
	
	return kaaUmlWebUserInterfaceMessages [kaaUmlLanguageCode] [kaaUmlUserInterfaceMessageNumber];	
}	


/* $RCSfile: kaaUmlUserInterface.c,v $ */
