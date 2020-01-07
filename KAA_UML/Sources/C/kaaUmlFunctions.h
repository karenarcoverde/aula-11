/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/12/20 21:22:17 $
 * $Log: kaaUmlFunctions.h,v $
 * Revision 1.9  2018/12/20 21:22:17  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.8  2018/12/16 00:30:48  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.7  2018/11/16 04:51:29  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.6  2018/11/14 13:27:19  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.5  2018/11/14 02:41:42  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.4  2018/11/14 00:04:06  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/05 12:38:24  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/03 20:43:29  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/03 20:36:46  karen.arcoverde
 * Initial revision
 *
 *
 */

#ifndef KAA_UML_FUNCTIONS
#define KAA_UML_FUNCTIONS "@(#)kaaUmlFunctions.h $Revision: 1.9 $"


#include "kaaUmlConst.h"
#include "kaaUmlTypes.h"
#include "kaaUmlErrors.h"



/*
 * kaaUmlLanguageType
 * KaaUmlGetLanguageIndex (char *);
 *
 * Arguments:
 * char * - string indicating the language choosed which can be "kaaUmlEnglish" or "kaaUmlPortuguese" (I)
 *
 * Returned code:
 * an enum of type kaaLanguageType corresponding to the number of language choosed, 0 for english and 1 for portuguese.
 * In error returns:
 * kaaUmlEnglish - if the language couldnt be identified
 *
 * Description:
 * This function only picks the language
 */

kaaUmlLanguageType
KaaUmlGetLanguageIndex (char *);





/*
 * kaaUmlErrorType
 * KaaUmlGetAbsoluteFileName (char *, char *, char *);
 *
 * Arguments:
 * char * -  absolute path to directory (I)
 * char * - file name (I)
 * char * - absolute path to file (O)
 *
 * Returned code:
 * If the function has no error it will give back in the third argument the string resulting from the concatenation of the first two arguments
 * kaaUmlOk - if successful, return ok. 
 * In error returns:
 * kaaUmlInvalidPathDirectory - if the pointer is null (size zero) 
 * kaaUmlInvalidFileName - the same (size zero)
 * kaaUmlInvalidAbsolutePathFile - the same (size zero)
 * kaaUmlInvalidAbsolutePathDirectorySize - if the path length is longer than allowed
 * kaaUmlInvalidFileNameSize- if the file name is longer than allowed 
 *
 * Description: 
 * This function gives the absolute path to file.
 */

kaaUmlErrorType
KaaUmlGetAbsoluteFileName (char *, char *, char *);





/*
 * kaaUmlErrorType
 * KaaUmlCheckStringField (char *, char *, size_t, size_t);
 *
 * Arguments:
 * char * - string that will be validated or not (I)
 * char * - set of valid characters for this strings composition (I)
 * size_t - minimum length of string (I) 
 * size_t - maximum length of string (I)
 *
 * Returned code:
 * kaaUmlOk - if successful, return ok.
 * In error returns:
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size
 * kaaUmlInvalidStringComparison - if the string is not present in the character set
 *
 * Description:
 * This function checks if a string contains valid characters and if the length is within the allowed range.
 */

kaaUmlErrorType
KaaUmlCheckStringField (char *, char *,  size_t, size_t);





/*
 * kaaUmlErrorType                                                                  
 * KaaUmlCheckNickname (char *, char *, size_t, size_t);                         
 * 
 * Arguments:
 * char * - string that will be validated or not (I)                                 
 * char * - set of valid characters for this strings composition (I)                
 * size_t - minimum length of string (I)                                            
 * size_t - maximum length of string (I)                                            
 *  
 * Returned code:
 * kaaUmlOk - if successful, return ok.
 * In error returns:
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero                
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size 
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size 
 * kaaUmlInvalidStringComparison - if the string is not present in the character set                   
 * kaaUmlInvalidNicknameDotPosition - if the dot character is in the first element or the last element of the string 
 * kaaUmlNoDotInNickname - if do not have the dot character in the string 
 * kaaUmlDotMoreThanOneOccurrence - if you have more than one occurrence of the dot
 * 
 * Description:
 * This function checks if a string contains valid characters and if the length is within the allowed range and if it only has one occurrence of the dot character.
 */

kaaUmlErrorType
KaaUmlCheckNickname (char *, char *, size_t, size_t);





/*
 * kaaUmlErrorType                                                                  
 * KaaUmlCheckEmail (char *, char *, size_t, size_t);                         
 * 
 * Arguments:
 * char * - string that will be validated or not (I)                                 
 * char * - set of valid characters for this strings composition (I)                
 * size_t - minimum length of string (I)                                            
 * size_t - maximum length of string (I)                                            
 *  
 * Returned code:
 * kaaUmlOk - if successful, return ok.
 * In error returns:
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero                
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size 
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size 
 * kaaUmlInvalidStringComparison - if the string is not present in the character set                   
 * kaaUmlInvalidEmailAtPosition - if the at character is in the first element or the last element of the string 
 * kaaUmlNoAtInEmail - if do not have the at character in the string 
 * kaaUmlAtMoreThanOneOccurrence - if you have more than one occurrence of the at
 * 
 * Description:
 * This function checks if a string contains valid characters and if the length is within the allowed range and if it only has one occurrence of "@" character.
 */

kaaUmlErrorType
KaaUmlCheckEmail (char *, char *, size_t, size_t);






/*
 * kaaUmlErrorType                                                                  
 * KaaUmlCreateRandomString (char *, size_t, char *);                         
 * 
 * Arguments:
 * char * - set of valid characters for this strings composition (I)
 * size_t - desired length for string (I)                                                                            
 * char * - string created (O)  
 *
 * Returned code:
 * if it does not detect any errors the function should gives back the string created in the third argument
 * kaaUmlOk - if successful, return ok.
 * In error returns:
 * kaaUmlInvalidCharacterSet - if the pointer is null (size zero)
 * kaaUmlInvalidStringCreate - the same (size zero)
 *
 * Description:
 * This function generates a random string from a set of valid characters and the desired length for string. 
 */

kaaUmlErrorType
KaaUmlCreateRandomString (char *, size_t, char *);





/*
 * kaaUmlErrorType                                                                  
 * KaaUmlCreateNickname (char *, char *, char *);                         
 * 
 * Arguments:
 * char * - full name (I)
 * char * - first name followed by dot and by last last name. if the full name contains only two words, the nickname must be a empty string (O)                         
 * char * - first name followed by dot and by the penultimate surname (O)  
 *
 * Returned code:
 * if it has no error the function it will give back two possibilities for the nickname (second argument and third argument)
 * kaaUmlOk - if successful, return ok.
 * In error returns:
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size
 * kaaUmlInvalidStringComparison - if the string is not present in the character set
 * kaaUmlInvalidFullName - if the pointer is null (size zero) or only a given name
 * kaaUmlInvalidFirstNickname - the same (size zero)
 * kaaUmlInvalidSecondNickname - the same (size zero)
 * kaaUmlInvalidNicknameSize - if the nickname is less than 5 characters or longer than 65 characters
 *
 * Description:
 * This function creates a nickname consisting of the first name and the last name or penultimate name. 
 */

kaaUmlErrorType
KaaUmlCreateNickname (char *, char *, char *);






/*
 * kaaUmlErrorType                                                                  
 * KaaUmlGetCryptAlgorithm (char *, kaaUmlCryptAlgorithms *);                         
 * 
 * Arguments:
 * char * - encoded password (I)
 * kaaUmlCryptAlgorithms * - algorithm used for encoding (O)  
 *
 * Returned code:
 * kaaUmlOk - if successful, return ok
 * kaaUmlDes - if it has no error it will give back in the second argument the type of algorithm is Des
 * kaaUmlMd5 - if it has no error it will give back in the second argument the type of algorithm is Md5
 * kaaUmlSha256 - if it has no error it will give back in the second argument the type of algorithm is Sha256
 * kaaUmlSha512 - if it has no error it will give back in the second argument the type of algorithm is Sha512 
 * In error returns:
 * kaaUmlInvalidEncodedPassword - if the pointer is null (size zero) or does not satisfy the conditions of the type of each algorithm
 * kaaUmlInvalidCryptAlgorithmType - the same (size zero)
 * kaaUmlInvalidSymbolAmount - if the dollar sign amount is wrong (2,3 or above 3) 
 * kaaUmlInvalidSymbolPosition - if the dollar sign is in the wrong position according to the type of each algorithm
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero                
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size 
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size 
 * kaaUmlInvalidStringComparison - if the string is not present in the character set
 *
 *
 * Description:
 * This function gives it back the crypt algorithm used for encoding for the enum type variable.
 */

kaaUmlErrorType                                                                  
KaaUmlGetCryptAlgorithm (char *, kaaUmlCryptAlgorithms *);
   




/*
 *
 * kaaUmlErrorType
 * KaaUmlEncodePasswordWithSpecificAlgorithm (char *, kaaUmlCryptAlgorithms, char *);
 *
 * Arguments:
 * char * - flat password (I)
 * kaaUmlCryptAlgorithms * - algorithm used for encoding (I)  
 * char * - encoded password (O)
 *
 * Returned code:
 * kaaUmlOk - if successful, return ok
 * if it has no error it will give back the encoded password
 * In error returns:
 * kaaUmlInvalidEncodedPassword - if the pointer is null (size zero) or does not satisfy the conditions of the type of each algorithm
 * kaaUmlInvalidCryptAlgorithmType - if the type of crypt algorithm choosed doesn't exist
 * kaaUmlInvalidSymbolAmount - if the dollar sign amount is wrong (2,3 or above 3) 
 * kaaUmlInvalidSymbolPosition - if the dollar sign is in the wrong position according to the type of each algorithm
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero                
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size 
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size 
 * kaaUmlInvalidStringComparison - if the string is not present in the character set
 * kaaUmlInvalidFlatPassword - if the pointer is null or size zero
 *
 * Description:
 * This functions generates an encoded password from a plane password and the identifier of an encoding algorithm 
 */

kaaUmlErrorType
KaaUmlEncodePasswordWithSpecificAlgorithm (char *, kaaUmlCryptAlgorithms, char *);







/*
 *
 * kaaUmlErrorType
 * KaaUmlEncodePasswordWithSpecificSalt (char *, char *, char *);
 *
 * Arguments:
 * char * - flat password (I)
 * char * - complete salt (id and random salt) (I)  
 * char * - encoded password (O)
 *
 * Returned code:
 * kaaUmlOk - if successful, return ok
 * if it has no error it will give back the encoded password
 * In error returns:
 * kaaUmlInvalidEncodedPassword - if the pointer is null (size zero) or does not satisfy the conditions of the type of each algorithm
 * kaaUmlInvalidCryptAlgorithmType - if the type of crypt algorithm choosed doesn't exist
 * kaaUmlInvalidSymbolAmount - if the dollar sign amount is wrong (2,3 or above 3) 
 * kaaUmlInvalidSymbolPosition - if the dollar sign is in the wrong position according to the type of each algorithm
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero                
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size 
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size 
 * kaaUmlInvalidStringComparison - if the string is not present in the character set
 * kaaUmlInvalidFlatPassword - if the pointer is null or size zero
 * kaaUmlInvalidCompleteSalt - if the pointer is null or size zero
 *
 * Description:
 * This functions generates an encoded password from a plane password and the complete salt (identification and random salt). 
 */

kaaUmlErrorType
KaaUmlEncodePasswordWithSpecificSalt (char *, char *, char *);






/*
 *
 * kaaUmlErrorType
 * KaaUmlCheckPassword (char *, char *);
 *
 * Arguments:
 * char * - flat password (I)
 * char * - encoded password (I)  
 *
 * Returned code:
 * kaaUmlOk - if successful, return ok
 * In error returns:
 * kaaUmlInvalidEncodedPassword - if the pointer is null (size zero) or does not satisfy the conditions of the type of each algorithm
 * kaaUmlInvalidCryptAlgorithmType - if the type of crypt algorithm choosed doesn't exist
 * kaaUmlInvalidSymbolAmount - if the dollar sign amount is wrong (2,3 or above 3) 
 * kaaUmlInvalidSymbolPosition - if the dollar sign is in the wrong position according to the type of each algorithm
 * kaaUmlInvalidString - if the pointer is null (size zero)
 * kaaUmlInvalidCharacterSet - the same (size zero)
 * kaaUmlInvalidMinimumSize - if the minimum size is equal to zero                
 * kaaUmlMinimumSizeBiggerMaximum- if the minimum size is longer than maximum size 
 * kaaUmlInvalidStringSize - if the length of the string is less than the minimum size or is bigger than maximum size 
 * kaaUmlInvalidStringComparison - if the string is not present in the character set
 * kaaUmlInvalidFlatPassword - if the pointer is null or size zero
 * kaaUmlInvalidCompleteSalt - if the pointer is null or size zero
 *
 * Description:
 * This functions compares the flat password with encoded password. 
 */

kaaUmlErrorType
KaaUmlCheckPassword (char *, char *);


#endif
/* $RCSfile: kaaUmlFunctions.h,v $ */


