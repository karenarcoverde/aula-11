/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * Prof. Marcelo Luiz Drumond Lanza 
 * EEL270 - Computacao II - Turma 2018/2
 *
 * $Author: karen.arcoverde $
 * $Date: 2018/12/20 21:20:53 $
 * $Log: kaaUmlConst.h,v $
 * Revision 1.4  2018/12/20 21:20:53  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.3  2018/12/16 00:31:01  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.2  2018/11/16 04:52:32  karen.arcoverde
 * *** empty log message ***
 *
 * Revision 1.1  2018/11/14 00:06:38  karen.arcoverde
 * Initial revision
 *
 *
 *
 */



#ifndef KAA_UML_CONST
#define KAA_UML_CONST "@(#)kaaUmlConst.h $Revision: 1.4 $"


#define KAA_UML_PATH_SIZE                                        1024
#define KAA_UML_FILE_NAME_SIZE                                   255 
#define KAA_UML_EOS                                              '\0'
#define KAA_UML_FULL_NAME_SIZE                                   64
#define KAA_UML_MD5_ID                                           '1'
#define KAA_UML_SHA256_ID                                        '5'
#define KAA_UML_SHA512_ID                                        '6'
#define KAA_UML_DES_SALT_LIMIT                                   2
#define KAA_UML_MD5_SALT_LIMIT                                   8
#define KAA_UML_SHA256_SALT_LIMIT                                16
#define KAA_UML_SHA512_SALT_LIMIT                                16
#define KAA_UML_MD5_ENCRYPT_SIZE                                 22
#define KAA_UML_SHA256_ENCRYPT_SIZE                              43
#define KAA_UML_SHA512_ENCRYPT_SIZE                              86
#define KAA_UML_ENCODED_PASSWORD_DES_SIZE                        13
#define KAA_UML_ENCODED_PASSWORD_MAXIMUM                         106
#define KAA_UML_ELEMENTS_AMOUNT                                  20
#define KAA_UML_CHARACTER_ENCODED_PASSWORD_SET                   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
#define KAA_UML_CHARACTER_NICKNAME_SET                           "abcdefghijklmnopqrstuvwxyz."
#define KAA_UML_MINIMUM_NICKNAME_SIZE                            5
#define KAA_UML_MAXIMUM_NICKNAME_SIZE                            65
#define KAA_UML_CHARACTER_CHECK_EMAIL_SET                        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.-_@"
#define KAA_UML_MINIMUM_CHECK_EMAIL_SIZE                         11
#define KAA_UML_MAXIMUM_CHECK_EMAIL_SIZE                         1024
#define KAA_UML_CHARACTER_FULL_NAME_SET                          "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .-\'"
#define KAA_UML_MINIMUM_FULL_NAME_SIZE                           11
#define KAA_UML_MAXIMUM_FULL_NAME_SIZE                           512
#define KAA_UML_CHARACTER_FLAT_PASSWORD_SET                      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .-\'\"(){}[]!?@#$%&*/\\+=;:"
#define KAA_UML_MINIMUM_FLAT_PASSWORD_SIZE                       8
#define KAA_UML_MAXIMUM_FLAT_PASSWORD_SIZE                       127
#define KAA_UML_CHARACTER_SALT_SET                               "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./"
#define KAA_UML_CHARACTER_COMPLETE_SALT_SET                               "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./$"



#endif
/* $RCSfile: kaaUmlConst.h,v $ */
