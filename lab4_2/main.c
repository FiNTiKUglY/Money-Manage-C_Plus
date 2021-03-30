#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "main.h"

int dateChecker(char* date) {
    int day, month, year, i, dateInt;
    day = 0;
    month = 0;
    year = 0;
    for (i = 0; i < 2; i += 1) {
        day += (date[i] - '0') * pow(10, (1 - i));
    }
    for (i = 3; i < 5; i += 1) {
        month += (date[i] - '0') * pow(10, (4 - i));
    }
    for (i = 6; i < 8; i += 1) {
        year += (date[i] - '0') * pow(10, (7 - i));
        if (year > 60) year = 60 - year;
    }
    dateInt = (year - 21) * 365 + (month - 4) * 12 + (day - 1);
    if (dateInt < 0) return 1;
    else return 0;
}

int number(char* string) {
    int i;
    int number = 0;
    for (i = 0; i < strlen(string); i += 1) {
        number += (string[i] - 48) * pow(10, strlen(string) - i - 1);
    }
    return number;
}

#ifndef TESTING

int main() {
    char string[50];
    char name[50];
    char date[50];
    char countS[50];
    char costS[50];
    int count, cost, n, lostMoney = 0;
    FILE* file = fopen("input.txt", "r");
    if(file == NULL) {
        printf("Can`t find current file");
        return 0;
    }
    while (!feof(file)) {
        int i = 0, j = 0, k = 0, l = 0, m = 0;
        n = 0;
        fgets(string, 50, file);
        while (string[i] != '\0') {
            if (string[i] == ' ' || string[i] == '\n') {
                name[j] = '\0';
                date[k] = '\0';
                countS[l] = '\0';
                costS[m] = '\0';
                n += 1;
            }
            else if (n == 0) {
                name[j] = string[i];
                j += 1;
            }
            else if (n == 1) {
                date[k] = string[i];
                k += 1;
            }
            else if (n == 2) {
                countS[l] = string[i];
                l += 1;
            }
            else if (n == 3) {
                costS[m] = string[i];
                m += 1;
            }
            i += 1;
        }
        count = number(countS);
        cost = number(costS);
        if (dateChecker(date)) {
            printf("%s", string);
            lostMoney += count * cost;
        }
    }
    fclose(file);
    printf("Lost money: %d", lostMoney);
}

#endif
