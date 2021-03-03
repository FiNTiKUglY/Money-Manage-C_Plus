#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "main.h"

int sumChecker(int sum, int a, int b)  {
    if (sum == (a + b)) return 1;
    return 0;
}

#ifndef TESTING

int main() {
    int i, j, s;
    printf("Enter sum (>7): ");

    while (!scanf("%d", &s) || s <= 7) {
        while (getchar() != '\n') {}
        printf("Incorrect input. Try again: ");
    }

    for (i = 0; i <= s/3; i = i + 1)  {
        for (j = 0; j <= s/5; j = j + 1) {
            int check = sumChecker(s, i * 3, j * 5);
            if (check) printf ("%d threes and %d fives\n", i, j);
        }
    }

    getch();
}

#endif
