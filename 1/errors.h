/**
 * Файл с кодами ошибок и подключением функции-обработчика ошибок.
 */

#ifndef __ERRORS_H
#define __ERRORS_H

#define NO_FUNCTION 1
    // Когда у нас нет функции в FUNCTION()
#define CANNOT_SET_CONSTANT 2
    // Когда мы пробуем задать в SET() значение для функции
#define HAVE_NO_VAR 3
    // Когда у нас в FUNCTION() нет переменной, которую мы задаем в SET()
#define UNKNOWN_ARG 4
    // Когда мы не распознали аргумент консоли

void handleError(int curErrCode, char curSetArgName);

#include "errors.c"
#endif