#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "main.h"

int procent(int money, char* date) {
    int days[12] = {31, 30, 31, 30, 31, 31, 30, 31, 30 , 31, 31 , 28};
    int day, month, year, i, dateInt, newmoney;
    newmoney = money;
    day = 0;
    month = 0;
    year = 0;
    for (i = 0; i < 2; i += 1) {
        day += (date[i] - '0') * pow(10, (1 - i));
    }
    for (i = 3; i < 5; i += 1) {
        month += (date[i] - '0') * pow(10, (4 - i));
    }
    for (i = 6; i < 10; i += 1) {
        year += (date[i] - '0') * pow(10, (9 - i));
    }
    dateInt = (year - 2021) * 12 + (month - 3);
    if (dateInt > 12) dateInt = 12;
    for (i = 0; i < dateInt; i++) {
        newmoney = newmoney * (1 + (0.1275 / 365 * days[i]));
    }
    return newmoney;
}

int dateChecker(char* date) {
    int check = 1;
    int i;
    for (i = 0; i < 2; i += 1) {
        if (!(date[i] > 47 && date[i] < 58)) check = 0;
    }
    for (i = 3; i < 5; i += 1) {
        if (!(date[i] > 47 && date[i] < 58)) check = 0;
    }
    for (i = 6; i < 10; i += 1) {
        if (!(date[i] > 47 && date[i] < 58)) check = 0;
    }
    if (!(date[2] == '.' && date[5] == '.')) check = 0;
    return check;
}

int OpenAccount() {
    int money;
    printf("\nEnter the amount of money (10000000 max): ");
    while (!(scanf("%d", &money) == 1) || money > 10000000) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    return money;
}

int AddMoney(int money, int addedMoney) {
    money += addedMoney;
    return money;
}

void LookInfo(int money) {
    printf("\nYour amount of money is %d\n", money);
}

void LookDayInfo(int money, char* date) {
    int newmoney;
    newmoney = procent(money, date);
    printf("\nYour amount of money in this day will be %d\n", newmoney);
}

void CloseAccount(int money) {
    printf("___________________\n");
    printf("|   TransitBank   |\n");
    printf("| Closing account |\n");
    printf("|Date: 01.03.2021 |\n");
    printf("|Identficator:    |\n");
    printf("|780123451512     |\n");
    printf("|Amount of money: |\n");
    printf("|%17d|\n", money);
    printf("___________________\n");
}

void LookBankInfo() {
    printf("\nTransitBank is the most reliable bank in Minsk.\n");
    printf("Our location is 123 Sovietskaya street.\n");
    printf("Phone number is 80(17)44-55-66\n");
}

#ifndef TESTING

int main() {
    int money, number, addedMoney, i;
    char date[10];
    printf("Welcome to TransitBank system, please enter the number:\n");

    while(1) {
        while(number != 1) {
            printf("\n1. Open account\n");
            printf("2. Look bank info\n");
            printf("3. Close the system\n");
            scanf("%d", &number);

            switch (number) {
                case 1:
                    money = OpenAccount();
                    break;
                case 2:
                    LookBankInfo();
                    break;
                case 3:
                    exit(1);
            }
        }

        while(number != 4) {
            printf("\n1. Add money\n");
            printf("2. Look account info\n");
            printf("3. Look account info at specified day\n");
            printf("4. Close account\n");
            printf("5. Look bank info\n");
            printf("6. Close the system\n");
            scanf("%d", &number);

            switch (number) {
                case 1:
                    printf("\nEnter an additional amount of money (10000000 max): ");
                    while (!(scanf("%d", &addedMoney) == 1) || addedMoney > 10000000) {
                        printf("Try again: ");
                        while (getchar() != '\n') {}
                    }
                    money = AddMoney(money, addedMoney);
                    break;
                case 2:
                    LookInfo(money);
                    break;
                case 3:
                    while(1) {
                        printf("\nEnter date (xx.xx.xxxx format):\n");
                        scanf("%s", date);
                        if (dateChecker(date)) break;
                    }
                    LookDayInfo(money, date);
                    break;
                case 4:
                    CloseAccount(money);
                    break;
                case 5:
                    LookBankInfo();
                    break;
                case 6:
                    exit(1);
            }
        }
    }
}

#endif
