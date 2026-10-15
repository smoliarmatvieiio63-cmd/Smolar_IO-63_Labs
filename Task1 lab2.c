#include <stdio.h>

int main(void) {
    int n;
    double x = 1.5;

    printf("Введіть n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Некоректне значення n!\n");
        return 1;
    }

    double S = 0.0;
    long long ops = 0; // Лічильник кількості операцій

    ops++; // double S = 0.0
    ops++; // int i = 0

    for (int i = 0; i <= n; i++) {
        ops++; // Перевірка i <= n

        // 1. Визначення знака (-1)^i
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        ops += 2; // Модуль (%) та тернарний вибір

        // 2. Вкладений цикл для обчислення x^(2i)
        double pow_x = 1.0;
        int j = 0;
        ops += 2; // Ініціалізація pow_x та j
        for (j = 0; j < 2 * i; j++) {
            ops++; // Перевірка j < 2*i
            pow_x *= x;
            ops++; // Множення
            ops++; // j++
        }
        ops++; // Перевірка виходу з циклу j

        // 3. Вкладений цикл для обчислення i!
        double fact = 1.0;
        int k = 1;
        ops += 2; // Ініціалізація fact та k
        for (k = 1; k <= i; k++) {
            ops++; // Перевірка k <= i
            fact *= k;
            ops++; // Множення
            ops++; // k++
        }
        ops++; // Перевірка виходу з циклу k

        // 4. Обчислення члена та додавання до суми
        double term = sign * pow_x / fact;
        ops += 2; // Множення та ділення
        S += term;
        ops++; // Додавання

        ops++; // i++
    }
    ops++; // Перевірка виходу з outer циклу

    printf("\n=== Спосіб 1 (Вкладені цикли) ===\n");
    printf("S = %.7f\n", S);
    printf("Кількість операцій: %lld\n", ops);

    return 0;
}
