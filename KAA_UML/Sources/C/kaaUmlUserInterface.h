/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/11/14 00:07:34 $
 * $Log: kaaUmlUserInterface.h,v $
 * Revision 1.4  2018/11/14 00:07:34  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/03 20:57:40  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/03 20:53:47  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/03 18:44:18  karen.arcoverde
 * Initial revision
 *
 *
 */

#ifndef KAA_UML_USER_INTERFACE
#define KAA_UML_USER_INTERFACE "@(#)kaaUmlUserInterface.h $Revision: 1.4 $"

#include "kaaUmlTypes.h"
#include "kaaUmlErrors.h"


typedef enum {kaaUmlMessageNumberEnter, kaaUmlMessageNumberHelp, kaaUmlUserInterfaceStringAmount} kaaUmlUserInterfaceMessageNumberType;



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
KaaUmlGetCliUserInterfaceMessage (kaaUmlUserInterfaceMessageNumberType, kaaUmlLanguageType); 



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
KaaUmlGetNcursesUserInterfaceMessage (kaaUmlUserInterfaceMessageNumberType, kaaUmlLanguageType);



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
KaaUmlGetWebUserInterfaceMessage (kaaUmlUserInterfaceMessageNumberType, kaaUmlLanguageType);


#endif
/* $RCSfile: kaaUmlUserInterface.h,v $ */
