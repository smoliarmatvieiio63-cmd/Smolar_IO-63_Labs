#include <stdio.h>

int main() {
    double x, y;
    int is_defined = 1;

    printf("Enter x: ");
    scanf("%lf", &x);

    /* Перевірка належності до D2: (-нескінченність, -41] */
    if (x <= -41.0) {
        y = 13.0 * x * x / 11.0 - 6.0;
    } else {
        /* Перевірка належності до D1: (-21, 3] U (12, +нескінченність) */
        if (x > -21.0) {
            if (x <= 3.0) {
                y = -14.0 * x - 20.0;
            } else {
                if (x > 12.0) {
                    y = -14.0 * x - 20.0;
                } else {
                    is_defined = 0; /* x потрапляє в проміжок (3, 12] */
                }
            }
        } else {
            is_defined = 0; /* x потрапляє в проміжок (-41, -21] */
        }
    }

    /* Вивід результату */
    if (is_defined == 1) {
        printf("y = %lf\n", y);
    } else {
        printf("Function is undefined for given x.\n");
    }

    return 0;
}