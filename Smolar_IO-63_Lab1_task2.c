#include <stdio.h>

int main() {
    double x, y;
    int is_defined = 1;

    printf("Enter x: ");
    scanf("%lf", &x);

    /* Перевірка належності до D2 */
    if (x <= -41.0) {
        y = 13.0 * x * x / 11.0 - 6.0;
    }
    /* Перевірка належності до D1 */
    else if ((x > -21.0 && x <= 3.0) || (x > 12.0)) {
        y = -14.0 * x - 20.0;
    }
    /* Якщо не належить жодному з проміжків */
    else {
        is_defined = 0;
    }

    /* Вивід результату */
    if (is_defined == 1) {
        printf("y = %lf\n", y);
    } else {
        printf("Function is undefined for given x.\n");
    }

    return 0;
}