/**
 * Практическое задание 0, эталонное решение
 * Файл с функциями прогрессий, подключается внутри файла main.c
 * @see main.c
 * */
#include <stdio.h>

/**
 * Функция, считающая арифм. прогрессию.
 * @example arifmProgr(1,3); // Прогрессия с a0=1, b=3
 * @param double a0 -- стартовое число
 * @param double b -- модификатор, прибавляющийся к каждому следующему.
 * @return void
 * @uses <stdio.h>
 * */
void arifmProgr(double a0, double b){
    int n = 0; // последний номер прогрессии
    double sum = a0, mult = a0; // Сумма и произведение прогрессии

    printf("Арифметическая програссия a0 = %lg, b = %lg\nУкажите n = ", a0, b);
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        a0 += b;
        printf("a[%d] = %lg\n", i, a0);
        sum += a0;
        mult *= a0;
    }
    printf("Сумма %d членов прогрессии = %lg\n", n+1, sum);
    printf("Произведение %d членов прогрессии = %lg\n", n+1, mult);
}

/**
 * Функция, считающая геом. прогрессию.
 * @example geomProgr(1,3); // Прогрессия с g0=1, q=3
 * @param double g0 -- стартовое число
 * @param double q -- модификатор, домножающий каждое следующему.
 * @return void
 * @uses <stdio.h>
 * */
void geomProgr(double g0, double q){
    int n = 0; // последний номер прогрессии
    double sum = g0, mult = g0; // Сумма и произведение прогрессии

    printf("Геометрическая програссия g0 = %lg, q = %lg\nУкажите n = ", g0, q);
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        g0 *= q;
        printf("g[%d] = %lg\n", i, g0);
        sum += g0;
        mult *= g0;
    }
    printf("Сумма %d членов прогрессии = %lg\n", n+1, sum);
    printf("Произведение %d членов прогрессии = %lg\n", n+1, mult);
}