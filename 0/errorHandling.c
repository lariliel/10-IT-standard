/**
 * Практическое задание 0, эталонное решение
 * Файл с обработкой ошибок, подключается внутри файла main.c
 * @see main.c
 * @uses <stdio.h>
 * */

/**
 * Функция, обрабатывающая ошибки и выводящая сообщения о них на экран.
 * @param double a -- первое введённое число
 * @param int* err -- указатель на номер ошибки из главной функции
 * @global err возвращается в 0 в конце функции.
 * @example handleError(-1); // printf("DIVISION BY ZERO");
 * */
void handleError(double a, int* err){
    switch(*err){
        case -1:
            printf("DIVISION BY ZERO\n");
            break;
        case -2:
            printf("UNKNOWN COMMAND!\n");
            break;
        case -3:
            printf("CANNOT EXTRACT SQUARE ROOT FROM %lg < 0\n", a);
            break;
    }
    *err = 0;
}
