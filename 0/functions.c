/**
 * Практическое задание 0, эталонное решение
 * Файл с функциями калькулятора, подключается внутри файла main.c
 * @see main.c
 * */
#include <math.h>

/**
 * Функция деления двух вещественных чисел.
 * @example division(5, 2); // 2.5
 * @param double a -- делимое
 * @param double b -- делитель
 * @param int* err -- флаг ошибки
 * @throws err = -1: деление на ноль
 * @return double 0 == b ? 0 : a/b
 * */
double division(double a, double b, int* err){
    if(0 == b)
        *err = -1;
    return 0 == *err ? a / b : 0;
}

/**
 * Функция деления нацело двух целых чисел со взятием частного
 * @example div(5, 2); // 2
 * @param int a -- делимое
 * @param int b -- делитель
 * @param int* err -- флаг ошибки
 * @throws err = -1: деление на ноль
 * @return int 0 == b ? 0 : a div b
 * */
int div(int a, int b, int* err){
    if(0 == b)
        *err = -1;
    return 0 == *err ? a / b : 0;
}

/**
 * Функция деления нацело двух целых чисел со взятием остатка
 * @example mod(5, 2); // 1
 * @param int a -- делимое
 * @param int b -- делитель
 * @param int* err -- флаг ошибки
 * @throws err = -1: деление на ноль
 * @return int 0 == b ? 0 : a mod b
 * */
int mod(int a, int b, int* err){
    if(0 == b)
        *err = -1;
    return 0 == *err ? a % b : 0;
}

/**
 * Функция модуля числа
 * @example myFabs(-5); // 5
 * @param double a -- исходное число
 * @return double |a|
 * */
double myFabs(double a){
    return a < 0 ? -a : a;
}

/**
 * Фнукия извлечения корня квадратного из числа a
 * @param double a -- исходное число
 * @example mySqrt(4); // 2
 * @return double sqrt(a)
 * @throws *err = -3: нельзя извлекать корень из a < 0
 * @uses <math.h>
 * */
double mySqrt(double a, int* err){
    if(a < 0)
        *err = -3;
    return 0 == *err ? sqrt(a) : 0;
}