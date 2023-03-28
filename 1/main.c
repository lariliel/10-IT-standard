/**
 * @author Lari Shirokova
 * Практика 1, эталонное решение
 * @link http://moria.1586.su/moodle/mod/page/view.php?id=1709
 * @link https://github.com/lariliel/10-IT-standard
 * @example test: ./test.bat
 * @example compile: ./compile.bat
 */
#include "common.h"

/**
 * Главная функция, принимает в себя аргументы консоли
 * @argv ARGC количество аргументов в консоли
 * @argv ARGV массив строк аргументов консоли
 * @uses common.h
 */
int main(int ARGC, char* ARGV[]){
    int setArgValues[MAX_SET];
    char setArgNames[MAX_SET];
    int haveArgs = 0, tmpArgVal = 0;
    char tmpArgName = '\0';

    int functionK = 0, functionB = 0;
    char functionName = '\0', functionArgName = '\0', functionOperation = '\0';

    int errorCode = 0;

#ifdef DEBUG
    printf("Всего аргументов: %d\nИмя программы: %s\n", ARGC, ARGV[0]);
#endif

    for(int i = 1; i < ARGC; i++) {
#ifdef DEBUG
        printf("ARGV[%d]: %s\n", i, ARGV[i]);
#endif
        if(strncmp("SET", ARGV[i], 3) == 0){
            errorCode = parseSet(ARGV[i], &tmpArgVal, &tmpArgName);
            setArgNames[haveArgs] = tmpArgName;
            setArgValues[haveArgs] = tmpArgVal;
#ifdef DEBUG
            printf("\tЗадаётся независимая переменная '%c' = %d\n", setArgNames[haveArgs], setArgValues[haveArgs]);
#endif
            haveArgs++;
        }
        else if(strncmp("FUNCTION", ARGV[i], 8) == 0){
            errorCode = parseFunction(ARGV[i], &functionName, &functionArgName, &functionK, &functionOperation, &functionB);
#ifdef DEBUG
            printf("\tЗадана функция относительно '%c'\n", functionName);
            printf("\tНезависимая переменная '%c'\n", functionArgName);
            printf("\tk = %d, b = %d\n", functionK, functionB);
            printf("\t%c(%c) = %d * %c %c %d\n", functionName, functionArgName, functionK, functionArgName, functionOperation, functionB);
#endif
        }
        else errorCode = UNKNOWN_ARG;
        handleError(errorCode, tmpArgName);
    }

#ifdef DEBUG
    printf("Всего задан(о) %d аргумент(а)\n", haveArgs);
#endif

    for(int i = 0; i < haveArgs; i++){
        if(functionArgName == functionName)
            handleError(NO_FUNCTION, '\0');
        else if(functionName == setArgNames[i])
            handleError(CANNOT_SET_CONSTANT, '\0');
        else if(functionArgName != setArgNames[i])
            handleError(HAVE_NO_VAR, setArgNames[i]);
        else if('+' == functionOperation)
            printf("%c(%d) = %d\n", functionName, setArgValues[i], functionK*setArgValues[i]+functionB);
        else if('-' == functionOperation)
            printf("%c(%d) = %d\n", functionName, setArgValues[i], functionK*setArgValues[i]-functionB);
        else if('*' == functionOperation)
            printf("%c(%d) = %d\n", functionName, setArgValues[i], functionK*setArgValues[i]*functionB);
    }
    return 0;
}
