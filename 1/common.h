/**
 * Файл для подключения остальных файлов и задания всех констант
 */

#ifndef __COMMON_C
#define __COMMON_C
// Защита от повторного включения файла, что позволяет в каждом файле прописать #include "common.c" и не беспокоиться

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SET 10
    // Максимальное количество задаваемых аргументов SET (из условия задачи)
#define MAX_STRING_LENGHT 255
    // Максимальная длина создаваемой в программе строки (из здравого смысла)

#include "parse.h"
    // здесь лежат функции разбора аргументов консоли
#include "errors.h"
    // Здесь обрабатываются ошибки и настраиваются константы ошибок

// </защита>
#endif