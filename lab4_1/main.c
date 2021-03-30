#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "main.h"

int n = 0;

int strCheck(char* str) {
    int check = 1;
    int i;
    for (i = 0; i < strlen(str); i += 1) {
        if (!(str[i] >= 48 && str[i] <= 57)) check = 0;
    }
    if (strlen(str) > 10) check = 0;
    return check;
}

int StoI(int number, char* str) {
    if (str[n] == '\0') {
        return number;
    }
    else {
        number += (str[n] - 48) * pow(10, strlen(str) - n - 1);
        n += 1;
        return StoI(number, str);
    }
}

#ifndef TESTING

int main() {
    char string[25];
    int number;
    printf("Enter the number: ");
    scanf("%s", string);
    while (!strCheck(string)) {
        printf("String has not only digits or has more than 10 digits\n");
        printf("Try again: ");
        while (getchar() != '\n') {}
        scanf("%s", string);
    }

    number = StoI(0, string);
    printf("%d", number);
}

#endif
