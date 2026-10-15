#include <stdio.h>

int main(void) {
    int n;
    double x = 1.5;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Incorrect value n!\n");
        return 1;
    }

    long long ops = 0;

    double x2 = x * x; ops++;
    double term = 1.0; ops++;
    double S = 1.0;    ops++;

    int i = 1; ops++;

    for (i = 1; i <= n; i++) {
        ops++;

        term = term * (-x2) / i;
        ops += 2;

        S += term;
        ops++;
1
        ops++;
    }
    ops++;

    printf("\n=== Method 2 (Dynamic programming) ===\n");
    printf("S = %.7f\n", S);
    printf("Number of operations: %lld\n", ops);

    return 0;
}
