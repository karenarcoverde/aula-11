/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/12/20 21:22:00 $
 * $Log: kaaUmlFunctions.c,v $
 * Revision 1.11  2018/12/20 21:22:00  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.10  2018/12/16 00:30:30  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.9  2018/11/16 04:51:13  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.8  2018/11/16 04:49:43  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.7  2018/11/15 02:25:34  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.6  2018/11/14 13:26:49  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.5  2018/11/14 02:41:27  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.4  2018/11/14 00:03:47  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/05 12:40:16  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/03 06:22:55  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/02 23:59:53  karen.arcoverde
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE		500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "kaaUmlTypes.h"
#include "kaaUmlConst.h"
#include "kaaUmlErrors.h"
#include "kaaUmlFunctions.h"




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
KaaUmlGetLanguageIndex (char *kaaUmlLanguage)
{
	if (!kaaUmlLanguage)
		return kaaUmlEnglish;

	if (!(strlen (kaaUmlLanguage)))
		return kaaUmlEnglish;

	if (strcmp (kaaUmlLanguage, "kaaUmlPortuguese") == 0)
		return kaaUmlPortuguese;


	return kaaUmlEnglish;

}



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
KaaUmlGetAbsoluteFileName (char * kaaUmlAbsolutePathDirectory, char * kaaUmlFileName, char * kaaUmlAbsolutePathFile)
{
	
	unsigned kaaUmlIndex;
	
	if (!kaaUmlAbsolutePathDirectory)
		return kaaUmlInvalidPathDirectory;

	if (!kaaUmlFileName)
		return kaaUmlInvalidFileName;

	if (!kaaUmlAbsolutePathFile)
		return kaaUmlInvalidAbsolutePathFile;
	
	if (strlen (kaaUmlAbsolutePathDirectory) > KAA_UML_PATH_SIZE) 
		return kaaUmlInvalidAbsolutePathDirectorySize;

	if (strlen (kaaUmlFileName) > KAA_UML_FILE_NAME_SIZE)
		return kaaUmlInvalidFileNameSize; 
	
	for (kaaUmlIndex = 0; kaaUmlIndex < strlen (kaaUmlAbsolutePathDirectory); kaaUmlIndex ++)
		if (kaaUmlIndex == (strlen (kaaUmlAbsolutePathDirectory) - 1) && (kaaUmlAbsolutePathDirectory [kaaUmlIndex]) != '/') 
			snprintf (kaaUmlAbsolutePathFile, strlen (kaaUmlAbsolutePathDirectory) + strlen (kaaUmlFileName) + 2, "%s/%s", kaaUmlAbsolutePathDirectory, kaaUmlFileName);	
		else
			snprintf (kaaUmlAbsolutePathFile, strlen (kaaUmlAbsolutePathDirectory) + strlen (kaaUmlFileName) + 1, "%s%s", kaaUmlAbsolutePathDirectory, kaaUmlFileName);	


	return kaaUmlOk;
}






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
KaaUmlCheckStringField (char * kaaUmlString, char * kaaUmlCharacterSet, size_t kaaUmlMinimumSize, size_t kaaUmlMaximumSize)
{
	char kaaUmlStringCompareSet;
	unsigned kaaUmlIndex;

	if (!kaaUmlString)
		return kaaUmlInvalidString;	
	
	if (!kaaUmlCharacterSet)
		return kaaUmlInvalidCharacterSet;

	if(kaaUmlMinimumSize == 0)
		return kaaUmlInvalidMinimumSize; 

	if (kaaUmlMinimumSize > kaaUmlMaximumSize) 
		return kaaUmlMinimumSizeBiggerMaximum;
	
	if ((strlen (kaaUmlString) < kaaUmlMinimumSize) || (strlen (kaaUmlString) > kaaUmlMaximumSize))	
		 return kaaUmlInvalidStringSize; 
	


	for (kaaUmlIndex = 0; kaaUmlIndex < strlen (kaaUmlString); kaaUmlIndex ++)
	{
		kaaUmlStringCompareSet = kaaUmlString [kaaUmlIndex];

		if (strchr (kaaUmlCharacterSet, kaaUmlStringCompareSet)  == NULL) 
			return kaaUmlInvalidStringComparison;				
	}

	return kaaUmlOk;
}                       




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
KaaUmlCheckNickname (char * kaaUmlString, char *kaaUmlCharacterSet, size_t kaaUmlMinimumSize, size_t kaaUmlMaximumSize)
{
	unsigned kaaUmlStringSize;
	kaaUmlErrorType kaaUmlReturnCode;
	char *kaaUmlFirstPointer;
	char *kaaUmlLastPointer;

	kaaUmlCharacterSet = KAA_UML_CHARACTER_NICKNAME_SET;
	kaaUmlMinimumSize = KAA_UML_MINIMUM_NICKNAME_SIZE;
	kaaUmlMaximumSize = KAA_UML_MAXIMUM_NICKNAME_SIZE;

	

	kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlString, KAA_UML_CHARACTER_NICKNAME_SET, KAA_UML_MINIMUM_NICKNAME_SIZE, KAA_UML_MAXIMUM_NICKNAME_SIZE);

	if (kaaUmlReturnCode != kaaUmlOk)
		return kaaUmlReturnCode;

	kaaUmlStringSize = strlen (kaaUmlString);
					
	if (kaaUmlString [0] == '.' || kaaUmlString [kaaUmlStringSize - 1] == '.')
		return kaaUmlInvalidNicknameDotPosition;

		
	kaaUmlFirstPointer = strchr (kaaUmlString, '.');


	if (kaaUmlFirstPointer == NULL) 
		return kaaUmlNoDotInNickname;


	kaaUmlLastPointer = strrchr (kaaUmlString, '.');


	if (kaaUmlFirstPointer != kaaUmlLastPointer)
		return kaaUmlDotMoreThanOneOccurrence;

	
	return kaaUmlOk;
}





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
KaaUmlCheckEmail (char * kaaUmlString, char *kaaUmlCharacterSet, size_t kaaUmlMinimumSize, size_t kaaUmlMaximumSize)
{
	unsigned kaaUmlStringSize;
	kaaUmlErrorType kaaUmlReturnCode;
	char *kaaUmlFirstPointer;
	char *kaaUmlLastPointer;

	kaaUmlCharacterSet = KAA_UML_CHARACTER_CHECK_EMAIL_SET;
	kaaUmlMinimumSize = KAA_UML_MINIMUM_CHECK_EMAIL_SIZE;
	kaaUmlMaximumSize = KAA_UML_MAXIMUM_CHECK_EMAIL_SIZE;


	kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlString, KAA_UML_CHARACTER_CHECK_EMAIL_SET, KAA_UML_MINIMUM_CHECK_EMAIL_SIZE, KAA_UML_MAXIMUM_CHECK_EMAIL_SIZE);

	if (kaaUmlReturnCode != kaaUmlOk)
		return kaaUmlReturnCode;

	kaaUmlStringSize = strlen (kaaUmlString);
					
	if (kaaUmlString [0] == '@' || kaaUmlString [kaaUmlStringSize - 1] == '@')
		return kaaUmlInvalidEmailAtPosition;

		
	kaaUmlFirstPointer = strchr (kaaUmlString, '@');


	if (kaaUmlFirstPointer == NULL) 
		return kaaUmlNoAtInEmail;


	kaaUmlLastPointer = strrchr (kaaUmlString, '@');


	if (kaaUmlFirstPointer != kaaUmlLastPointer)
		return kaaUmlAtMoreThanOneOccurrence;

	
	return kaaUmlOk;
}






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
 * kaaUmlOk - if successful, return ok
 * In error returns:
 * kaaUmlInvalidCharacterSet - if the pointer is null (size zero)
 * kaaUmlInvalidStringCreate - the same (size zero)
 *  
 * Description:
 * This function generates a random string from a set of valid characters and the desired length for string. 
 */

kaaUmlErrorType
KaaUmlCreateRandomString (char * kaaUmlCharacterSet, size_t kaaUmlStringSize, char * kaaUmlStringCreate)
{
	
	size_t kaaUmlIndex;
	

	if (!kaaUmlCharacterSet)
		return kaaUmlInvalidCharacterSet;

	if (!kaaUmlStringCreate)
		return kaaUmlInvalidStringCreate;


	srand ((unsigned) time (NULL));	

	for (kaaUmlIndex = 0; kaaUmlIndex < kaaUmlStringSize; kaaUmlIndex ++)
		kaaUmlStringCreate [kaaUmlIndex] = kaaUmlCharacterSet [rand () % strlen (kaaUmlCharacterSet)];

	kaaUmlStringCreate [kaaUmlStringSize] = KAA_UML_EOS;


	return kaaUmlOk;	
}





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
 * kaaUmlOk - if successful, return ok
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
KaaUmlCreateNickname (char * kaaUmlFullName, char * kaaUmlFirstNickname, char * kaaUmlSecondNickname)
{
	char * kaaUmlWord;
	unsigned kaaUmlSpacesNumber, kaaUmlIndex, kaaUmlFullNameAndSpaceSize, kaaUmlIndexTwo, kaaUmlIndexThree;
	char *kaaUmlWordSet [KAA_UML_FULL_NAME_SIZE];
        char kaaUmlFullNameCopy [KAA_UML_FULL_NAME_SIZE];
	kaaUmlErrorType kaaUmlReturnCode;

	kaaUmlIndexThree = 0;

		

	if (!kaaUmlFullName)
	{
		kaaUmlFirstNickname [0] = KAA_UML_EOS;
		kaaUmlSecondNickname [0]= KAA_UML_EOS;
		return kaaUmlInvalidFullName;
	}

	if (!kaaUmlFirstNickname)
	{	
		kaaUmlFirstNickname [0] = KAA_UML_EOS;
		kaaUmlSecondNickname [0] = KAA_UML_EOS;
		return kaaUmlInvalidFirstNickname;
	}

	if (!kaaUmlSecondNickname)
	{
		kaaUmlFirstNickname [0] = KAA_UML_EOS;
		kaaUmlSecondNickname [0]= KAA_UML_EOS;
		return kaaUmlInvalidSecondNickname;
	}
	
	
	kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlFullName, KAA_UML_CHARACTER_FULL_NAME_SET, KAA_UML_MINIMUM_FULL_NAME_SIZE, KAA_UML_MAXIMUM_FULL_NAME_SIZE);
	if (kaaUmlReturnCode != kaaUmlOk)
	{
		kaaUmlFirstNickname [0] = KAA_UML_EOS;
		kaaUmlSecondNickname [0]= KAA_UML_EOS;
		return	kaaUmlReturnCode;
	}

	


	kaaUmlSpacesNumber = 0;
	kaaUmlFullNameAndSpaceSize = strlen (kaaUmlFullName);
	strcpy (kaaUmlFullNameCopy, kaaUmlFullName); 

	for (kaaUmlIndexTwo = 0; kaaUmlIndexTwo < kaaUmlFullNameAndSpaceSize; kaaUmlIndexTwo ++)
		if (kaaUmlFullNameCopy [kaaUmlIndexTwo] == '\'' || kaaUmlFullNameCopy [kaaUmlIndexTwo] == '-' || kaaUmlFullNameCopy [kaaUmlIndexTwo] == '.')
		{
			kaaUmlIndexThree = kaaUmlIndexTwo;
			while (kaaUmlIndexThree < kaaUmlFullNameAndSpaceSize)
			{
				if (kaaUmlIndexThree == (kaaUmlFullNameAndSpaceSize - 1))
					kaaUmlFullNameCopy [kaaUmlIndexThree] = KAA_UML_EOS;

				else
					kaaUmlFullNameCopy [kaaUmlIndexThree] = kaaUmlFullNameCopy [kaaUmlIndexThree + 1];
				
				kaaUmlIndexThree ++;
			}
		}

	for (kaaUmlIndex = 0; kaaUmlIndex < kaaUmlFullNameAndSpaceSize; kaaUmlIndex ++)
	{	
		if (kaaUmlFullName [kaaUmlIndex] == ' ')	
			kaaUmlSpacesNumber ++;

		if (kaaUmlFullName [kaaUmlIndex] >= 'A' && kaaUmlFullName [kaaUmlIndex] <= 'Z')
			kaaUmlFullNameCopy [kaaUmlIndex] = kaaUmlFullNameCopy [kaaUmlIndex] + 32; 
	}		
	

	if (kaaUmlSpacesNumber == 0)
	{
		kaaUmlFirstNickname [0] = KAA_UML_EOS;
		kaaUmlSecondNickname [0] = KAA_UML_EOS;	
		return kaaUmlInvalidFullName;
	}

	

	kaaUmlWord = strtok (kaaUmlFullNameCopy, " ");	

	
	
	kaaUmlIndex = 0;

	while (kaaUmlWord != NULL)
	{

		kaaUmlWordSet [kaaUmlIndex] = kaaUmlWord;
		kaaUmlWord = strtok (NULL, " ");
				 
		kaaUmlIndex ++;
	}

	



	if (kaaUmlSpacesNumber == 1)
	{
		snprintf (kaaUmlFirstNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex - 1]); 
		kaaUmlSecondNickname [0] = KAA_UML_EOS;

	}

		
	if (kaaUmlSpacesNumber > 2)
	{		
		if (strcmp ("des", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("dos", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("de", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("do", kaaUmlWordSet [kaaUmlIndex -2]) == 0 ||strcmp ("da", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("e", kaaUmlWordSet [kaaUmlIndex -2]) == 0)
		{       	
			snprintf (kaaUmlFirstNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex -1]); 
			snprintf (kaaUmlSecondNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex - 3]);
			
		}
		else
		{
			snprintf (kaaUmlFirstNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex -1]); 
			snprintf (kaaUmlSecondNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex - 2]); 

		}


	}



	if (kaaUmlSpacesNumber == 2)
	{	
		if (strcmp ("des", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("dos", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("de", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("do", kaaUmlWordSet [kaaUmlIndex -2]) == 0 ||strcmp ("da", kaaUmlWordSet [kaaUmlIndex -2]) == 0 || strcmp ("e", kaaUmlWordSet [kaaUmlIndex -2]) == 0)
		{       	
			snprintf (kaaUmlFirstNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex -1]);
			kaaUmlSecondNickname [0] = KAA_UML_EOS;


		}
				
		else
		{	
			snprintf (kaaUmlFirstNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex -1]); 
			snprintf (kaaUmlSecondNickname, KAA_UML_FULL_NAME_SIZE + 1, "%s.%s", kaaUmlWordSet [0], kaaUmlWordSet [kaaUmlIndex -2]);

				
		}
	}
		
	if ((strlen (kaaUmlFirstNickname) < KAA_UML_MINIMUM_NICKNAME_SIZE) || (strlen (kaaUmlFirstNickname) > KAA_UML_MAXIMUM_NICKNAME_SIZE))
			kaaUmlFirstNickname [0] = KAA_UML_EOS;

	if ((strlen (kaaUmlSecondNickname) < KAA_UML_MINIMUM_NICKNAME_SIZE) || (strlen (kaaUmlSecondNickname) > KAA_UML_MAXIMUM_NICKNAME_SIZE))
			kaaUmlSecondNickname [0] = KAA_UML_EOS;


	if (((strlen (kaaUmlFirstNickname) < KAA_UML_MINIMUM_NICKNAME_SIZE) || (strlen (kaaUmlFirstNickname) > KAA_UML_MAXIMUM_NICKNAME_SIZE)) && (((strlen (kaaUmlSecondNickname) < KAA_UML_MINIMUM_NICKNAME_SIZE) || (strlen (kaaUmlSecondNickname) > KAA_UML_MAXIMUM_NICKNAME_SIZE))))
	{
			kaaUmlFirstNickname [0] = KAA_UML_EOS;
			kaaUmlSecondNickname [0] = KAA_UML_EOS;

			return kaaUmlInvalidNicknameSize;
	}


	return kaaUmlOk;
}



/*
 * kaaUmlErrorType                                                                  
 * KaaUmlGetCryptAlgorithm (char *, kaaUmlCryptAlgorithms *);                         
 *  
 * Arguments:
 * char * - encoded password (I)                                                 
 * kaaUmlCryptAlgorithms * - algorithm used for encondig (O)
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
 * Description:
 * This function gives it back the crypt algorithm used for encoding for the enum type variable. 
 */

kaaUmlErrorType
KaaUmlGetCryptAlgorithm (char * kaaUmlEncodedPassword, kaaUmlCryptAlgorithms * kaaUmlCryptAlgorithmType)
{
	
	unsigned kaaUmlFirstIndex, kaaUmlSecondIndex, kaaUmlEncodedPasswordSize, kaaUmlSymbolAmount;
	char * kaaUmlElements [KAA_UML_ELEMENTS_AMOUNT];
	char kaaUmlEncodedPasswordCopy [KAA_UML_ENCODED_PASSWORD_MAXIMUM];
	char *kaaUmlElement;
	kaaUmlErrorType kaaUmlReturnCode;
	 

	kaaUmlSymbolAmount = 0;
	kaaUmlSecondIndex = 0;
	

	if (!kaaUmlEncodedPassword)
		return kaaUmlInvalidEncodedPassword;

	if (!kaaUmlCryptAlgorithmType)
		return kaaUmlInvalidCryptAlgorithmType;
	
	

	kaaUmlEncodedPasswordSize = strlen (kaaUmlEncodedPassword);

	for (kaaUmlFirstIndex = 0; kaaUmlFirstIndex < kaaUmlEncodedPasswordSize; kaaUmlFirstIndex ++)	
		if (kaaUmlEncodedPassword [kaaUmlFirstIndex] == '$')
			kaaUmlSymbolAmount ++;


			


	if (kaaUmlSymbolAmount == 0)
	{		
			kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlEncodedPassword, KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_ENCODED_PASSWORD_DES_SIZE, KAA_UML_ENCODED_PASSWORD_DES_SIZE);
			if (kaaUmlReturnCode != kaaUmlOk)					
				return kaaUmlReturnCode;
			
			else
				return kaaUmlDes;
	}

	
	if (kaaUmlSymbolAmount == 1 || kaaUmlSymbolAmount == 2)
		return kaaUmlInvalidSymbolAmount;

	
	if (kaaUmlSymbolAmount == 3)
	{
			if (kaaUmlEncodedPassword [0] != '$' || kaaUmlEncodedPassword [2] != '$')
				return kaaUmlInvalidSymbolPosition;

			else
			{	
			
					
					strcpy (kaaUmlEncodedPasswordCopy, kaaUmlEncodedPassword);
				
					kaaUmlElement = strtok (kaaUmlEncodedPasswordCopy, "$");
				
					while (kaaUmlElement != NULL)
					{			
						kaaUmlElements [kaaUmlSecondIndex] = kaaUmlElement;
						kaaUmlElement = strtok (NULL, "$");

						kaaUmlSecondIndex ++; 

					}

				
					
				
					if (kaaUmlElements [0][0] == KAA_UML_MD5_ID)
					{
						
						kaaUmlReturnCode =  KaaUmlCheckStringField (kaaUmlElements [1], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, 1, KAA_UML_MD5_SALT_LIMIT);
						if (kaaUmlReturnCode != kaaUmlOk)	
							return kaaUmlReturnCode;
					
							
         					kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [2], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_MD5_ENCRYPT_SIZE, KAA_UML_MD5_ENCRYPT_SIZE); 						                  		      
						
						if (kaaUmlReturnCode != kaaUmlOk)
							return kaaUmlReturnCode;
						
						
						*kaaUmlCryptAlgorithmType = kaaUmlMd5;
						
	              			}
					
					
					else if (kaaUmlElements [0][0] == KAA_UML_SHA256_ID)
					{
						
						kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [1], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, 1, KAA_UML_SHA256_SALT_LIMIT);
						if (kaaUmlReturnCode != kaaUmlOk)			
							return kaaUmlReturnCode;
						

                                		kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [2], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_SHA256_ENCRYPT_SIZE, KAA_UML_SHA256_ENCRYPT_SIZE); 						
						if (kaaUmlReturnCode != kaaUmlOk)
							return kaaUmlReturnCode;

						*kaaUmlCryptAlgorithmType = kaaUmlSha256;
					}	

						
					else if (kaaUmlElements [0][0] == KAA_UML_SHA512_ID)
					{
						
						kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [1], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, 1, KAA_UML_SHA512_SALT_LIMIT);
						if (kaaUmlReturnCode != kaaUmlOk)
							return kaaUmlReturnCode;

							
						kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [2], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_SHA512_ENCRYPT_SIZE, KAA_UML_SHA512_ENCRYPT_SIZE); 						
						if (kaaUmlReturnCode != kaaUmlOk)
							return kaaUmlReturnCode;

						*kaaUmlCryptAlgorithmType = kaaUmlSha512;
					}
				
						
					if((kaaUmlElements [0][0] != KAA_UML_MD5_ID)  && (kaaUmlElements [0][0] != KAA_UML_SHA256_ID) && (kaaUmlElements [0][0] != KAA_UML_SHA512_ID))
					{

						kaaUmlCryptAlgorithmType = NULL;
						return kaaUmlInvalidEncodedPassword; 
					} 
				

					 
			}		
	}

	
	if (kaaUmlSymbolAmount > 3)
		return kaaUmlInvalidSymbolAmount;


	return kaaUmlOk;
}






/*
 * kaaUmlErrorType                                                                  
 * KaaUmlEncodePasswordWithSpecificAlgorithm (char *, kaaUmlCryptAlgorithms, char *);                         
 *  
 * Arguments:
 * char * - flat password (I)                                                 
 * kaaUmlCryptAlgorithms - algorithm used for encondig (I)
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
 * This function generates an encoded password from a flat password and the identifier of an encoding algorithm
 */

kaaUmlErrorType
KaaUmlEncodePasswordWithSpecificAlgorithm (char * kaaUmlFlatPassword, kaaUmlCryptAlgorithms kaaUmlCryptAlgorithmType, char * kaaUmlEncodedPassword)
{
	
	char kaaUmlDesSalt [KAA_UML_DES_SALT_LIMIT + 1]; /* 1 = EOS */
	char kaaUmlMd5Salt [KAA_UML_MD5_SALT_LIMIT + 1]; 
	char kaaUmlSha256Salt [KAA_UML_SHA256_SALT_LIMIT + 1]; 
	char kaaUmlSha512Salt [KAA_UML_SHA512_SALT_LIMIT + 1];
       	char kaaUmlCompleteMd5Salt [4 + KAA_UML_MD5_SALT_LIMIT + 1]; /* 4 = $ID$...$ */
	char kaaUmlCompleteSha256Salt [4 + KAA_UML_SHA256_SALT_LIMIT + 1]; 
	char kaaUmlCompleteSha512Salt [4 + KAA_UML_SHA512_SALT_LIMIT + 1]; 

	kaaUmlErrorType kaaUmlReturnCode;


	if (!kaaUmlFlatPassword)
		return kaaUmlInvalidFlatPassword;

	if (!kaaUmlEncodedPassword)
		return kaaUmlInvalidEncodedPassword;

	
	kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlFlatPassword, KAA_UML_CHARACTER_FLAT_PASSWORD_SET, KAA_UML_MINIMUM_FLAT_PASSWORD_SIZE, KAA_UML_MAXIMUM_FLAT_PASSWORD_SIZE);  	 
	if (kaaUmlReturnCode != kaaUmlOk)
		return kaaUmlReturnCode;



	if (kaaUmlCryptAlgorithmType == kaaUmlDes)
	{
		kaaUmlReturnCode = KaaUmlCreateRandomString (KAA_UML_CHARACTER_SALT_SET, KAA_UML_DES_SALT_LIMIT, kaaUmlDesSalt);
		if (kaaUmlReturnCode != kaaUmlOk)
			return kaaUmlReturnCode;

		strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlDesSalt));

		if (kaaUmlEncodedPassword == NULL) 
			return kaaUmlInvalidEncodedPassword;


	}
	
	if (kaaUmlCryptAlgorithmType == kaaUmlMd5)
	{

		kaaUmlReturnCode = KaaUmlCreateRandomString (KAA_UML_CHARACTER_SALT_SET, KAA_UML_MD5_SALT_LIMIT, kaaUmlMd5Salt);
		if (kaaUmlReturnCode != kaaUmlOk)
			return kaaUmlReturnCode;

		
		snprintf (kaaUmlCompleteMd5Salt, 4 + KAA_UML_MD5_SALT_LIMIT + 1 , "$%c$%s$", KAA_UML_MD5_ID, kaaUmlMd5Salt);   /* identification + dollar sign + salt */    

		strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteMd5Salt));

		if (kaaUmlEncodedPassword == NULL)
			return kaaUmlInvalidEncodedPassword;	

	}


	else if (kaaUmlCryptAlgorithmType == kaaUmlSha256)
	{

		kaaUmlReturnCode = KaaUmlCreateRandomString (KAA_UML_CHARACTER_SALT_SET, KAA_UML_SHA256_SALT_LIMIT, kaaUmlSha256Salt);
		if (kaaUmlReturnCode != kaaUmlOk)
			return kaaUmlReturnCode;

		
		snprintf (kaaUmlCompleteSha256Salt, 4 + KAA_UML_SHA256_SALT_LIMIT + 1 , "$%c$%s$", KAA_UML_SHA256_ID, kaaUmlSha256Salt);   /* identification + dollar sign + salt */    

		strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSha256Salt));

		if (kaaUmlEncodedPassword == NULL)
			return kaaUmlInvalidEncodedPassword;	

	}



	else if (kaaUmlCryptAlgorithmType == kaaUmlSha512)
	{

		kaaUmlReturnCode = KaaUmlCreateRandomString (KAA_UML_CHARACTER_SALT_SET, KAA_UML_SHA512_SALT_LIMIT, kaaUmlSha512Salt);
		if (kaaUmlReturnCode != kaaUmlOk)
			return kaaUmlReturnCode;

		
		snprintf (kaaUmlCompleteSha512Salt, 4 + KAA_UML_SHA512_SALT_LIMIT + 1 , "$%c$%s$", KAA_UML_SHA512_ID, kaaUmlSha512Salt);   /* identification + dollar sign + salt */    

		strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSha512Salt));

		if (kaaUmlEncodedPassword == NULL)
			return kaaUmlInvalidEncodedPassword;	

	}

	else 
		return kaaUmlInvalidCryptAlgorithmType;



	return kaaUmlOk;
}







/*
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
 * This function generates an encoded password from a flat password and the complete salt (identification and random salt).
 */

kaaUmlErrorType
KaaUmlEncodePasswordWithSpecificSalt (char * kaaUmlFlatPassword, char * kaaUmlCompleteSalt, char * kaaUmlEncodedPassword)
{

	unsigned kaaUmlFirstIndex, kaaUmlCompleteSaltSize, kaaUmlSymbolAmount;
	kaaUmlErrorType kaaUmlReturnCode;

	kaaUmlSymbolAmount = 0;

	if (!kaaUmlFlatPassword)
		return kaaUmlInvalidFlatPassword;

	if (!kaaUmlCompleteSalt)
		return kaaUmlInvalidCompleteSalt;
	
	if (!kaaUmlEncodedPassword)
		return kaaUmlInvalidEncodedPassword;

	
	kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlFlatPassword, KAA_UML_CHARACTER_FLAT_PASSWORD_SET, KAA_UML_MINIMUM_FLAT_PASSWORD_SIZE, KAA_UML_MAXIMUM_FLAT_PASSWORD_SIZE);  	 
	if (kaaUmlReturnCode != kaaUmlOk)
		return kaaUmlReturnCode;

	


	kaaUmlCompleteSaltSize = strlen (kaaUmlCompleteSalt);

	
	for (kaaUmlFirstIndex = 0; kaaUmlFirstIndex < kaaUmlCompleteSaltSize; kaaUmlFirstIndex ++)	
		if (kaaUmlCompleteSalt [kaaUmlFirstIndex] == '$')
			kaaUmlSymbolAmount ++;


	if (kaaUmlSymbolAmount == 0)
	{
		kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlCompleteSalt, KAA_UML_CHARACTER_SALT_SET, KAA_UML_DES_SALT_LIMIT, KAA_UML_DES_SALT_LIMIT);
		if (kaaUmlReturnCode != kaaUmlOk)
			return kaaUmlReturnCode;

		strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSalt));
		if (kaaUmlEncodedPassword == NULL)
			return kaaUmlInvalidEncodedPassword;

	}


	if (kaaUmlSymbolAmount == 1 && kaaUmlSymbolAmount == 2)
		return kaaUmlInvalidSymbolAmount;


	if (kaaUmlSymbolAmount == 3)
	{
		if (kaaUmlCompleteSalt [0] != '$' || kaaUmlCompleteSalt [2] != '$' || kaaUmlCompleteSalt [kaaUmlCompleteSaltSize - 1] != '$')
			return kaaUmlInvalidSymbolPosition;
		
		else 
		{
				if (kaaUmlCompleteSalt [1] == KAA_UML_MD5_ID)  
				{
					kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlCompleteSalt, KAA_UML_CHARACTER_COMPLETE_SALT_SET, 1, 4 + KAA_UML_MD5_SALT_LIMIT); 
					if (kaaUmlReturnCode != kaaUmlOk)
						return kaaUmlReturnCode;

					strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSalt));
					if (kaaUmlEncodedPassword == NULL)
						return kaaUmlInvalidEncodedPassword;

				}


				else if (kaaUmlCompleteSalt [1] == KAA_UML_SHA256_ID)  
				{
					kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlCompleteSalt, KAA_UML_CHARACTER_COMPLETE_SALT_SET, 1, 4 + KAA_UML_SHA256_SALT_LIMIT); 
					if (kaaUmlReturnCode != kaaUmlOk)
						return kaaUmlReturnCode;

					strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSalt));
					if (kaaUmlEncodedPassword == NULL)
						return kaaUmlInvalidEncodedPassword;

				}


				
				else if (kaaUmlCompleteSalt [1] == KAA_UML_SHA512_ID)  
				{
					kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlCompleteSalt, KAA_UML_CHARACTER_COMPLETE_SALT_SET, 1, 4 + KAA_UML_SHA512_SALT_LIMIT); 
					if (kaaUmlReturnCode != kaaUmlOk)
						return kaaUmlReturnCode;

					strcpy (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSalt));
					if (kaaUmlEncodedPassword == NULL)
						return kaaUmlInvalidEncodedPassword;

				}

				else
					return kaaUmlInvalidCryptAlgorithmType;

		}		

	}

	if (kaaUmlSymbolAmount > 3)
		return kaaUmlInvalidSymbolAmount; 

	return kaaUmlOk;

}









/*
 * kaaUmlErrorType                                                                  
 * KaaUmlCheckPassword (char * kaaUmlFlatPassword, char * kaaUmlEncodedPassword);                         
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
KaaUmlCheckPassword (char * kaaUmlFlatPassword, char * kaaUmlEncodedPassword)
{
	unsigned kaaUmlReturnCode, kaaUmlFirstIndex, kaaUmlSecondIndex, kaaUmlEncodedPasswordSize, kaaUmlSymbolAmount;
	char kaaUmlDesSalt [KAA_UML_DES_SALT_LIMIT + 1];
	char kaaUmlCompleteMd5Salt [KAA_UML_MD5_SALT_LIMIT];
	char kaaUmlCompleteSha256Salt [KAA_UML_SHA256_SALT_LIMIT];
	char kaaUmlCompleteSha512Salt [KAA_UML_SHA512_SALT_LIMIT];
	char * kaaUmlElements [KAA_UML_ELEMENTS_AMOUNT];
	char kaaUmlEncodedPasswordCopy [KAA_UML_ENCODED_PASSWORD_MAXIMUM];
	char * kaaUmlElement;


	kaaUmlSymbolAmount = 0;
	kaaUmlSecondIndex = 0;

	if (!kaaUmlFlatPassword)
		return kaaUmlInvalidFlatPassword;

	if (!kaaUmlEncodedPassword)
		return kaaUmlInvalidEncodedPassword;

	
	kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlFlatPassword, KAA_UML_CHARACTER_FLAT_PASSWORD_SET, KAA_UML_MINIMUM_FLAT_PASSWORD_SIZE, KAA_UML_MAXIMUM_FLAT_PASSWORD_SIZE);  	 
	if (kaaUmlReturnCode != kaaUmlOk)
		return kaaUmlReturnCode;

	
	kaaUmlEncodedPasswordSize = strlen (kaaUmlEncodedPassword);

	
	for (kaaUmlFirstIndex = 0; kaaUmlFirstIndex < kaaUmlEncodedPasswordSize; kaaUmlFirstIndex ++)	
		if (kaaUmlEncodedPassword [kaaUmlFirstIndex] == '$')
			kaaUmlSymbolAmount ++;


	if (kaaUmlSymbolAmount == 0)
	{
		kaaUmlDesSalt [0] = kaaUmlEncodedPassword [0];
		kaaUmlDesSalt [1] = kaaUmlEncodedPassword [1];
		kaaUmlDesSalt [2] = KAA_UML_EOS;


		kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlEncodedPassword, KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_ENCODED_PASSWORD_DES_SIZE, KAA_UML_ENCODED_PASSWORD_DES_SIZE);
		if (kaaUmlReturnCode != kaaUmlOk)					
			return kaaUmlReturnCode;
		
		if (strcmp (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlDesSalt)) == 0)
			return kaaUmlOk;
					
		else 
			return kaaUmlCheckPasswordNotMatch;

	}


	if (kaaUmlSymbolAmount == 1 && kaaUmlSymbolAmount == 2)
		return kaaUmlInvalidSymbolAmount;


	if (kaaUmlSymbolAmount == 3)
	{

		strcpy (kaaUmlEncodedPasswordCopy, kaaUmlEncodedPassword);
				
		kaaUmlElement = strtok (kaaUmlEncodedPasswordCopy, "$");
				
		while (kaaUmlElement != NULL)
		{			
			kaaUmlElements [kaaUmlSecondIndex] = kaaUmlElement;
			kaaUmlElement = strtok (NULL, "$");

			kaaUmlSecondIndex ++; 

		}
		

		
		if (kaaUmlElements [0][0] == KAA_UML_MD5_ID)  
		{

			snprintf (kaaUmlCompleteMd5Salt, "$%s$%s", kaaUmlElements [0], kaaUmlElements [1]);

			kaaUmlReturnCode =  KaaUmlCheckStringField (kaaUmlElements [1], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, 1, KAA_UML_MD5_SALT_LIMIT);
			if (kaaUmlReturnCode != kaaUmlOk)	
				return kaaUmlReturnCode;
						
         		kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [2], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_MD5_ENCRYPT_SIZE, KAA_UML_MD5_ENCRYPT_SIZE); 						                  		      if (kaaUmlReturnCode != kaaUmlOk)
				return kaaUmlReturnCode;

			if (strcmp (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteMd5Salt)) == 0)
				return kaaUmlOk;
					
			else 
				return kaaUmlCheckPasswordNotMatch;

		}


		else if (kaaUmlElements [0][0] == KAA_UML_SHA256_ID)  
		{
			snprintf (kaaUmlCompleteSha256Salt, "$%s$%s", kaaUmlElements [0], kaaUmlElements [1]);


			kaaUmlReturnCode =  KaaUmlCheckStringField (kaaUmlElements [1], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, 1, KAA_UML_SHA256_SALT_LIMIT);
			if (kaaUmlReturnCode != kaaUmlOk)	
				return kaaUmlReturnCode;
						
         		kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [2], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_SHA256_ENCRYPT_SIZE, KAA_UML_SHA256_ENCRYPT_SIZE); 						                  		      if (kaaUmlReturnCode != kaaUmlOk)
				return kaaUmlReturnCode;

			if (strcmp (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSha256Salt)) == 0)
				return kaaUmlOk;
					
			else 
				return kaaUmlCheckPasswordNotMatch;

		}


				
		else if (kaaUmlElements [0][0] == KAA_UML_SHA512_ID)  
		{
			snprintf (kaaUmlCompleteSha512Salt, "$%s$%s", kaaUmlElements [0], kaaUmlElements [1]);

	
			kaaUmlReturnCode =  KaaUmlCheckStringField (kaaUmlElements [1], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, 1, KAA_UML_SHA512_SALT_LIMIT);
			if (kaaUmlReturnCode != kaaUmlOk)	
				return kaaUmlReturnCode;
						
         		kaaUmlReturnCode = KaaUmlCheckStringField (kaaUmlElements [2], KAA_UML_CHARACTER_ENCODED_PASSWORD_SET, KAA_UML_SHA512_ENCRYPT_SIZE, KAA_UML_SHA512_ENCRYPT_SIZE); 						                  		      if (kaaUmlReturnCode != kaaUmlOk)
				return kaaUmlReturnCode;


			if (strcmp (kaaUmlEncodedPassword, crypt (kaaUmlFlatPassword, kaaUmlCompleteSha512Salt)) == 0)
				return kaaUmlOk;
					
			else 
				return kaaUmlCheckPasswordNotMatch;
		}

		else
			return kaaUmlInvalidCryptAlgorithmType;

			

	}

	if (kaaUmlSymbolAmount > 3)
		return kaaUmlInvalidSymbolAmount; 

	
	return kaaUmlOk;

}

/* $RCSfile: kaaUmlFunctions.c,v $ */
