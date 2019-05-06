/**
 * Файл с функцией-обработчиком ошибок
 */

#ifndef __ERRORS_C
#define __ERRORS_C

/**
 * Выводит на экран сообщение об ошибке
 * @param curErrCode Принимает в себя код ошибки (константу из errors.h)
 * @param curSetArgName b символ-название аргумента (используется при curErrCode == HAVE_NO_VAR только)
 */
void handleError(int curErrCode, char curSetArgName){
    switch (curErrCode)
    {
        case NO_FUNCTION:
            printf("HAVE NO FUNCTION AT ALL\n");
            break;

        case CANNOT_SET_CONSTANT:
            printf("CANNOT SET CONSTANT\n");
            break;

        case HAVE_NO_VAR:
            printf("HAVE NO '%c' VARIABLE\n", curSetArgName);
            break;
        
        case UNKNOWN_ARG:
            printf("UNCNOWN ARGUMENT\n");
            break;
    
        default:
            break;
    }
}

#endif