/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/12/20 21:21:29 $
 * $Log: kaaUmlErrors.h,v $
 * Revision 1.9  2018/12/20 21:21:29  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.8  2018/12/16 00:31:17  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.7  2018/11/16 04:51:56  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.6  2018/11/14 02:42:05  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.5  2018/11/14 00:05:43  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.4  2018/11/05 15:41:23  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/03 21:00:55  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/03 20:51:38  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/03 03:43:25  karen.arcoverde
 * Initial revision
 *
 */

#ifndef KAA_UML_ERRORS
#define KAA_UML_ERRORS "@(#)kaaUmlErrors.h $Revision: 1.9 $"

#include "kaaUmlTypes.h"


typedef enum 
{
	kaaUmlOk, 
	kaaUmlFileError, 
	kaaUmlErrorGettingMessage, 
	kaaUmlErrorGettingInterfaceMessage, 
	kaaUmlInvalidPathDirectory,
	kaaUmlInvalidFileName,
	kaaUmlInvalidAbsolutePathFile,
	kaaUmlInvalidAbsolutePathDirectorySize,
	kaaUmlInvalidFileNameSize,
	kaaUmlInvalidString,
	kaaUmlInvalidCharacterSet,
	kaaUmlInvalidMinimumSize,
	kaaUmlMinimumSizeBiggerMaximum,
	kaaUmlInvalidStringSize,
	kaaUmlInvalidStringComparison,
	kaaUmlInvalidNicknameDotPosition,
	kaaUmlNoDotInNickname,
	kaaUmlDotMoreThanOneOccurrence,
	kaaUmlInvalidEmailAtPosition,
	kaaUmlNoAtInEmail,
	kaaUmlAtMoreThanOneOccurrence,
	kaaUmlInvalidStringCreate,
	kaaUmlInvalidFullName,
	kaaUmlInvalidFirstNickname,
	kaaUmlInvalidSecondNickname,
	kaaUmlInvalidNicknameSize,
	kaaUmlInvalidEncodedPassword,
	kaaUmlInvalidCryptAlgorithmType,
	kaaUmlInvalidSymbolAmount,
	kaaUmlInvalidSymbolPosition,
	kaaUmlInvalidFlatPassword,
	kaaUmlInvalidCompleteSalt,
	kaaUmlCheckPasswordNotMatch,
	kaaUmlErrorsAmount

} kaaUmlErrorType;



/*
 * char *
 * KaaUmlGetCliErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);
 *
 * Arguments:
 * kaaUmlErrorType - code about the error that occurred (I)
 * kaaUmlLanguageType - say in what language do we see the message error output (I)
 *
 * Returned code:
 * char * - Is the message error converted 
 *
 * Description:
 * This function converts the error from a code to the wanted language - works only for Comand Line arguments
 */

char *
KaaUmlGetCliErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);

/*
 * char *
 * KaaUmlGetCliErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);
 *
 * Arguments:
 * kaaUmlErrorType - code about the error that occurred (I)
 * kaaUmlLanguageType - say in what language do we see the message error output (I)
 *
 * Returned code:
 * char * - Is the message error converted 
 *
 * Description:
 * This function converts the error from a code to the wanted language - works only for Ncurses 
 */

char *
KaaUmlGetNcursesErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);


/*
 * char *
 * KaaUmlGetCliErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);
 *
 * Arguments:
 * kaaUmlErrorType - code about the error that occurred (I)
 * kaaUmlLanguageType - say in what language do we see the message error output (I)
 *
 * Returned code:
 * char * - Is the message error converted 
 *
 * Description:
 * This function converts the error from a code to the wanted language - works only for Web Interface 
 */

char *
KaaUmlGetWebErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);


#endif
/* $RCSfile: kaaUmlErrors.h,v $ */
