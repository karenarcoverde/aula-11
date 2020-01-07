/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/12/20 21:21:12 $
 * $Log: kaaUmlErrors.c,v $
 * Revision 1.11  2018/12/20 21:21:12  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.10  2018/12/16 00:31:30  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.9  2018/11/16 04:52:08  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.8  2018/11/15 02:26:43  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.7  2018/11/14 02:42:17  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.6  2018/11/14 00:05:28  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.5  2018/11/05 15:47:44  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.4  2018/11/05 15:41:04  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/11/03 21:00:36  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/03 20:50:50  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/03 03:43:05  karen.arcoverde
 * Initial revision
 *
 */

#include <stdio.h>
#include "kaaUmlErrors.h"
#include "kaaUmlTypes.h"


char *kaaUmlCliErrorMessages [kaaUmlLanguageAmount] [kaaUmlErrorsAmount] = 
{
	{
		"Ok",
		"File error",
		"Error getting message",
		"Error getting interface message",
		"Invalid path directory",
		"Invalid file name",
		"Invalid absolute path file",
		"Invalid absolute path directory size",
		"Invalid file name size",
		"Invalid string",
		"Invalid character set",
		"Invalid minimum size",
		"Minimum size is bigger than maximum size",
		"Invalid string size",
		"String does not belong to the character set",
		"Dot character is at the wrong nickname position",
		"No dot character in nickname",
		"Dot character has more than one occurrence in nickname",
		"Character at is the wrong email position",
		"No at character in email",
		"At character has more than one occurrence in email",
		"Invalid string create",
		"Invalid full name",
		"Invalid first nickname",
		"Invalid second nickname",
		"Invalid nickname size",
		"Invalid encoded password",
		"Invalid type of crypt algorithm",
		"Invalid symbol amount",
		"Invalid position of symbol",
		"Invalid flat password",
		"Invalid complete salt",
		"Check password don't match"
	},

	{
		"Sucesso",
		"Erro relacionado com arquivo",
		"Erro pegando a mensagem",
		"Erro pegando a mensagem da interface",
		"Caminho do diretorio invalido",
		"Nome do arquivo invalido",
		"Caminho absoluto do arquivo invalido",
		"Tamanho do diretorio de caminho absoluto invalido",
		"Tamanho do nome do arquivo invalido",
		"String invalida",
		"Conjunto de caracteres invalido",
		"Tamanho minimo da string invalida",
		"Tamanho minimo e maior do que o tamanho maximo",
		"Tamanho da string invalido",
		"String nao pertence ao conjunto de caracteres",
		"Caractere ponto esta na posicao errada do apelido",
		"Sem caractere ponto no apelido",
		"Caractere ponto tem mais de uma ocorrencia no apelido",	
		"Caractere arroba esta na posicao errada do email",
		"Sem caractere arroba no email",
		"Caractere arroba tem mais de uma ocorrencia no email",
       		"String criada invalida",
		"Nome completo invalido",
		"Primeiro apelido invalido",
		"Segundo apelido invalido",
		"Tamanho do apelido invalido",
		"Senha codificada invalida",
		"Tipo de algoritmo utilizado invalido",
		"Quantidade de cifrao utilizado invalido",
		"Posicao invalida do cifrao",
		"Senha plana invalida",
		"Salt completo invalido",
		"Senha plana nao corresponde a senha codificada"
	}
};


char *kaaUmlNcursesErrorMessages [kaaUmlLanguageAmount] [kaaUmlErrorsAmount] =
{
	{
		"Ok",
		"File error",
		"Error getting message",
		"Error getting interface message",
		"Invalid path directory",
		"Invalid file name",
		"Invalid absolute path file",
		"Invalid absolute path directory size",
		"Invalid file name size",
		"Invalid string",
		"Invalid character set",
		"Invalid minimum size",
		"Minimum size is bigger than maximum size",
		"Invalid string size",
		"String does not belong to the character set",
		"Dot character is at the wrong nickname position",
		"No dot character in nickname",
		"Dot character has more than one occurrence in nickname",		 	   
		"Character at is the wrong email position",
		"No at character in email",
		"At character has more than one occurrence in email",
		"Invalid string create",
		"Invalid full name",
		"Invalid first nickname",
		"Invalid second nickname",
		"Invalid nickname size",
		"Invalid encoded password",
		"Invalid type of crypt algorithm",
		"Invalid symbol amount",
		"Invalid position of symbol",
		"Invalid flat password",
		"Invalid complete salt",
		"Check password don't match"
	},

	{
		"Sucesso",
		"Erro relacionado com arquivo",
		"Erro pegando a mensagem",
		"Erro pegando a mensagem da interface"	
		"Caminho do diretorio invalido",
		"Nome do arquivo invalido",
		"Caminho absoluto do arquivo invalido",
		"Tamanho do diretorio de caminho absoluto invalido",
		"Tamanho do nome do arquivo invalido",
		"String invalida",
		"Conjunto de caracteres invalido",
		"Tamanho minimo da string invalida",
		"Tamanho minimo e maior do que o tamanho maximo",
		"Tamanho da string invalido",
		"String nao pertence ao conjunto de caracteres",
		"Caractere ponto esta na posicao errada do apelido",
		"Sem caractere ponto no apelido",
		"Caractere ponto tem mais de uma ocorrencia no apelido",
		"Caractere arroba esta na posicao errada do email",
		"Sem caractere arroba no email",
		"Caractere arroba tem mais de uma ocorrencia no email",
       		"String criada invalida",
		"Nome completo invalido",
		"Primeiro apelido invalido",
		"Segundo apelido invalido",
		"Tamanho do apelido invalido",
		"Senha codificada invalida",
		"Tipo de algoritmo utilizado invalido",
		"Quantidade de cifrao utilizado invalido",
		"Posicao invalida do cifrao",
		"Senha plana invalida",
		"Salt completo invalido",
		"Senha plana nao corresponde a senha codificada"	
	}
};


char *kaaUmlWebErrorMessages [kaaUmlLanguageAmount] [kaaUmlErrorsAmount] =
{
	{
		"Ok",
		"File error",
		"Error getting message",
		"Error getting interface message",
		"Invalid path directory",
		"Invalid file name",
		"Invalid absolute path file",
		"Invalid absolute path directory size",
		"Invalid file name size",
		"Invalid string",
		"Invalid character set",
		"Invalid minimum size",
		"Minimum size is bigger than maximum size",
		"Invalid string size",
		"String does not belong to the character set",
		"Dot character is at the wrong nickname position",
		"No dot character in nickname",
		"Dot character has more than one occurrence in nickname",
		"Character at is the wrong email position",
		"No at character in email",
		"At character has more than one occurrence in email",
		"Invalid string create",
		"Invalid full name",
		"Invalid first nickname",
		"Invalid second nickname",
		"Invalid nickname size",
		"Invalid encoded password",
		"Invalid type of crypt algorithm",
		"Invalid symbol amount",
		"Invalid position of symbol",
		"Invalid flat password",
		"Invalid complete salt",
		"Check password don't match"
	},

	{
		"Sucesso",
		"Erro relacionado com arquivo",
		"Erro pegando a mensagem",
		"Erro pegando a mensagem da interface"
		"Caminho do diretorio invalido",
		"Nome do arquivo invalido",
		"Caminho absoluto do arquivo invalido",
		"Tamanho do diretorio de caminho absoluto invalido",
		"Tamanho do nome do arquivo invalido",
		"String invalida",
		"Conjunto de caracteres invalido",
		"Tamanho minimo da string invalido",
		"Tamanho minimo e maior do que o tamanho maximo",
		"Tamanho da string invalido",
		"String nao pertence ao conjunto de caracteres",
		"Caractere ponto esta na posicao errada do apelido",
		"Sem caractere ponto no apelido",
		"Caractere ponto tem mais de uma ocorrencia no apelido",			 
		"Caractere arroba esta na posicao errada do email",
		"Sem caractere arroba no email",
		"Caractere arroba tem mais de uma ocorrencia no email",
       		"String criada invalida",
		"Nome completo invalido",
		"Primeiro apelido invalido",
		"Segundo apelido invalido",
		"Tamanho do apelido invalido",
		"Senha codificada invalida",
		"Tipo de algoritmo utilizado invalido",
		"Quantidade de cifrao utilizado invalido",
		"Posicao invalida do cifrao",
		"Senha plana invalida",
		"Salt completo invalido",
		"Senha plana nao corresponde a senha codificada"	
	}
};





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
KaaUmlGetCliErrorMessage (kaaUmlErrorType kaaUmlErrorCode, kaaUmlLanguageType kaaUmlLanguageCode)
{
	if ((kaaUmlErrorCode >= kaaUmlErrorsAmount) || (kaaUmlErrorCode < 0))
	{
		if ((kaaUmlLanguageCode < 0) || (kaaUmlLanguageCode >= kaaUmlLanguageAmount))
			return kaaUmlCliErrorMessages [kaaUmlEnglish] [kaaUmlErrorGettingMessage];

		return kaaUmlCliErrorMessages [kaaUmlLanguageCode] [kaaUmlErrorGettingMessage];
	}

	if ((kaaUmlLanguageCode >= kaaUmlLanguageAmount) || (kaaUmlLanguageCode < 0))
		kaaUmlLanguageCode = 0; /* if it is not possible to identify the language, return english */
	
	return kaaUmlCliErrorMessages [kaaUmlLanguageCode] [kaaUmlErrorCode];	
}





/*
 * char *
 * KaaUmlGetNcursesErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);
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
KaaUmlGetNcursesErrorMessage (kaaUmlErrorType kaaUmlErrorCode, kaaUmlLanguageType kaaUmlLanguageCode)
{
	if ((kaaUmlErrorCode >= kaaUmlErrorsAmount) || (kaaUmlErrorCode < 0))
	{
		if ((kaaUmlLanguageCode < 0) || (kaaUmlLanguageCode >= kaaUmlLanguageAmount))
			return kaaUmlNcursesErrorMessages [kaaUmlEnglish] [kaaUmlErrorGettingMessage];

		return kaaUmlNcursesErrorMessages [kaaUmlLanguageCode] [kaaUmlErrorGettingMessage];
	}


	if ((kaaUmlLanguageCode >= kaaUmlLanguageAmount) || (kaaUmlLanguageCode < 0))
		kaaUmlLanguageCode = 0; /* if it is not possible to identify the language, return english */
	
	return kaaUmlNcursesErrorMessages [kaaUmlLanguageCode] [kaaUmlErrorCode];	
}





/*
 * char *
 * KaaUmlGetWebErrorMessage (kaaUmlErrorType, kaaUmlLanguageType);
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
KaaUmlGetWebErrorMessage (kaaUmlErrorType kaaUmlErrorCode, kaaUmlLanguageType kaaUmlLanguageCode)
{
	
	if ((kaaUmlErrorCode >= kaaUmlErrorsAmount) || (kaaUmlErrorCode < 0))
	{
		if ((kaaUmlLanguageCode < 0) || (kaaUmlLanguageCode >= kaaUmlLanguageAmount))
			return kaaUmlWebErrorMessages [kaaUmlEnglish] [kaaUmlErrorGettingMessage];

		return kaaUmlWebErrorMessages [kaaUmlLanguageCode] [kaaUmlErrorGettingMessage];
	}

	if ((kaaUmlLanguageCode >= kaaUmlLanguageAmount) || (kaaUmlLanguageCode < 0))
		kaaUmlLanguageCode = 0; /* if it is not possible to identify the language, return english */
	
	return kaaUmlWebErrorMessages [kaaUmlLanguageCode] [kaaUmlErrorCode];	
}



/* $RCSfile: kaaUmlErrors.c,v $ */
