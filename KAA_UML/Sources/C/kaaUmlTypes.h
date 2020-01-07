/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/12/20 21:22:43 $
 * $Log: kaaUmlTypes.h,v $
 * Revision 1.8  2018/12/20 21:22:43  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.7  2018/11/14 00:06:00  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.6  2018/11/03 20:37:57  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.5  2018/11/03 20:27:57  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.4  2018/11/03 06:21:20  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/02 23:16:14  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/10/31 04:19:19  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/10/31 04:17:37  karen.arcoverde
 * Initial revision
 *
 * Revision 1.1  2018/10/31 04:16:37  karen.arcoverde
 * Initial revision
 *
 */

#ifndef KAA_UML_LANGUAGE_TYPE
#define KAA_UML_LANGUAGE_TYPE "@(#)kaaUmlLanguageTypes.h $Revision: 1.8 $"

#include "kaaUmlConst.h"

typedef enum {kaaUmlEnglish, kaaUmlPortuguese, kaaUmlLanguageAmount} kaaUmlLanguageType;


typedef unsigned long long kaaUmlUserIdentifierType;

typedef unsigned long long kaaUmlUserProfileType;


typedef enum {kaaUmlDes, kaaUmlMd5, kaaUmlSha256, kaaUmlSha512, kaaUmlAlgorithmsAmount} kaaUmlCryptAlgorithms;


typedef struct kaaUmlUserDataStruct
{
	kaaUmlUserIdentifierType kaaUmlUserIdentifier;
	char kaaUmlUserNickname [KAA_UML_MAXIMUM_NICKNAME_SIZE + 1];
	char kaaUmlUserPassword [KAA_UML_MAXIMUM_FLAT_PASSWORD_SIZE + 1];
	char kaaUmlUserPasswordConfirmation [KAA_UML_MAXIMUM_FLAT_PASSWORD_SIZE + 1];
	kaaUmlUserProfileType kaaUmlUserProfile;
        char kaaUmlUserName [KAA_UML_MAXIMUM_FULL_NAME_SIZE + 1];
	char kaaUmlUserNameConfirmation [KAA_UML_MAXIMUM_FULL_NAME_SIZE + 1];
	char kaaUmlUserEmail [KAA_UML_MAXIMUM_CHECK_EMAIL_SIZE + 1];
	char kaaUmlUserEmailConfirmation [KAA_UML_MAXIMUM_CHECK_EMAIL_SIZE + 1];
	struct kaaUmlUserDataStruct * kaaUmlPreviousUser;
	struct kaaUmlUserDataStruct * kaaUmlNextUser;
	
} kaaUmlUserDataType;


#endif
/* $RCSfile: kaaUmlTypes.h,v $ */
