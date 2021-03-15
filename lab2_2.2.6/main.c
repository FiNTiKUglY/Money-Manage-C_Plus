#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "main.h"

int fact(int n) {
    if (n == 1) return 1;
    return fact(n - 1) * n;
}

int foundN(double x, double e) {
    double comparison, right;
    int n = 1;

    do {
        right += pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
        comparison = fabs(sin(x) - right);
        n++;
    } while (comparison > e);

    printf("Taylor is %f\n", right);
    return n - 1;
}

#ifndef TESTING

int main() {
    float x, e;
    printf("Enter x: ");
    while (!(scanf("%f", &x)) == 1) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    printf("Enter e: ");
    while (!(scanf("%f", &e)) == 1) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    printf("sin is %f\n", sin(x));
    printf("n is %d", foundN(x, e));
}

#endif
