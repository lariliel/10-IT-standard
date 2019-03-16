/**
 * Практическое задание 0, эталонное решение
 * @author ddsh
 * @link http://moria.1586.su/moodle/mod/page/view.php?id=1705
 * @link https://github.com/lariliel/10-IT-standard
 * */
#include <stdio.h>
#include "functions.c"
#include "progressions.c"
#include "errorHandling.c"

/**
 * Основная программа
 * @uses <stdio.h>
 * @uses functions.c
 * @uses progressions.c
 * @uses errorHandling.c
 * */
int main(void){
    double a = 0, b = 0;
    int errorCode = 0;  // Флаг отслеживания ошибок. При 0 ошибок нет.
    int resInt = 0;
    double resDouble = 0;
    char cmd = '\0';

    while(1){
        scanf("%lg%c%lg", &a, &cmd, &b);

        switch(cmd){    // основная логика программы
            case '+':
                printf("%lg + %lg = %lg\n", a, b, a + b);
                break;
            case '-':
                printf("%lg - %lg = %lg\n", a, b, a - b);
                break;
            case '*':
                printf("%lg * %lg = %lg\n", a, b, a * b);
                break;
            case '/':
                resDouble = division(a, b, &errorCode);
                if(0 == errorCode)
                    printf("%lg / %lg = %lg\n", a, b, resDouble);
                break;
            case 'D':
                resInt = div((int) a, (int) b, &errorCode);
                if(0 == errorCode)
                    printf("%lg D %lg = %d\n", a, b, resInt);
                break;
            case '%':
                resInt = mod((int) a, (int) b, &errorCode);
                if(0 == errorCode)
                    printf("%lg %% %lg = %d\n", a, b, resInt);
                break;
            case 'S':
                resDouble = mySqrt(a, &errorCode);
                if(0 == errorCode)
                    printf("%lg S = %lg\n", a, resDouble);
                break;
            case 'M':
                printf("%lg M = %lg\n", a, myFabs(a));
                break;
            case 'X': // Если использовать E -- будет возникать ошибка распознания между 1е5 = (число) 10000 и 1Е5 "выход"
                printf("EXIT\n");
                return 0;
                break;
            case 'A':
                arifmProgr(a,b);
                break;
            case 'G':
                geomProgr(a,b);
                break;
            default:
                errorCode = -2;
        }
        handleError(a, &errorCode);
    }
    return 0;
}
