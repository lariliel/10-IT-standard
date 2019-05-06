/**
 * Файл с прототипами функций разбора командной строки
 * @see http://ddsh.ru/msu/c/06/0608.htm
 */

#ifndef __PARSE_H
#define __PARSE_H
int parseSet(char* curSet, int* curArgvVal, char* curArgvName);
int parseFunction(char* curFunction, char* curFunName, char* curFunArgName, int* curFunK, char* curFuncOp, int* curFunB);

#include "parse.c"
#endif