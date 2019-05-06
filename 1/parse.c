/**
 * Файл с функциями разбора аргументов командной строки
 * @see http://ddsh.ru/msu/c/06/0604.htm
 */

#ifndef __PARSE_C
#define __PARSE_C

/**
 * Разбирает на составные части аргумент с указанием переменной
 * @param curSet указатель на массив с аргументом
 * @param curArgvName -- указатель, куда сохранить Имя переменной
 * @param curArgvVal -- указатель, куда сохранить Значение переменной
 */
int parseSet(char* curSet, int* curArgvVal, char* curArgvName){
    int digitCount = 0;
    char tmpStr[MAX_STRING_LENGHT];

    *curArgvName = curSet[4];
    
    while(isdigit(curSet[6+digitCount]))
        digitCount++;
    for(int i = 0; i < digitCount; i++)
        tmpStr[i] = curSet[6+i];
    *curArgvVal = atoi(tmpStr);
    
    return 0;
}

/**
 * Разбирает на составные части аргумент с функцией
 * @param curFunction указатель на массив с аргументом
 * @param curFun* указатель на переменные, где будут лежать составные части уравнения y=K*x Op B
 */
int parseFunction(char* curFunction, char* curFunName, char* curFunArgName, int* curFunK, char* curFuncOp, int* curFunB){
    int digitCount = 0;
    char tmpStr[MAX_STRING_LENGHT], tmpStr2[MAX_STRING_LENGHT];

    *curFunName = curFunction[9];

    while(isdigit(curFunction[11+digitCount]))
        digitCount++;
    for(int i = 0; i < digitCount; i++)
        tmpStr[i] = curFunction[11+i];

    if (isdigit(curFunction[11+digitCount+1])) {
        // y=b+k*x
        *curFunB = atoi(tmpStr);
        *curFuncOp = curFunction[11+digitCount];
        int kStartCoord = 11+digitCount+1;

        digitCount = 0;
        while(isdigit(curFunction[kStartCoord+digitCount]))
            digitCount++;
        for(int i = 0; i < digitCount; i++)
            tmpStr2[i] = curFunction[kStartCoord+i];
        *curFunK = atoi(tmpStr2);

        *curFunArgName = curFunction[kStartCoord+digitCount+1];
        
    } else {
        // y=k*x+b
        *curFunK = atoi(tmpStr);
        *curFuncOp = curFunction[11+digitCount+2];

        int xCoord = 11+digitCount+1;
        *curFunArgName = curFunction[xCoord];

        digitCount = 0;
        while(isdigit(curFunction[xCoord+2+digitCount]))
            digitCount++;
        for(int i = 0; i < digitCount; i++)
            tmpStr2[i] = curFunction[xCoord+2+i];
        *curFunB = atoi(tmpStr2);
    }
    
    return 0;
}

#endif