#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

MNumber CreateMNumber(char* initStr) {
    MNumber number = {NULL, NULL, 0};
    int n;
    for (n = strlen(initStr)-1; n >= 0; n--) {
        AddDigit(&number, initStr[n]-'0');
    }
    return number;
}

char* MNumberToString(MNumber number) {
    int i = 0;
    char* digit;
    Item* p = number.tail;
    char* string = (char*)malloc(sizeof(char) * 40);
    if (string == NULL) {
        printf("No memory");
        exit(1);
    }
    while (p) {
        string[i] = p->digit + '0';
        p = p->prev;
        i += 1;
    }
    string[i] = '\0';
    return string;
}

void AddDigit(MNumber *number, int digit) {
    Item *p = (Item *)malloc(sizeof(Item));
    if (p == NULL) {
        printf("No memory");
        exit(1);
    }
    p->digit = digit;
    p->next = p->prev = NULL;
    if (number->head == NULL) {
        number->head = number->tail = p;
    }
    else {
        number->tail->next = p;
        p->prev = number->tail;
        number->tail = p;
    }
    number->n++;
}

void ReverseAddDigit(MNumber *number, int digit) {
    Item *p = (Item *)malloc(sizeof(Item));
    if (p == NULL) {
        printf("No memory");
        exit(1);
    }
    p->digit = digit;
    p->next = p->prev = NULL;
    if (number->head == NULL) {
        number->head = number->tail = p;
    }
    else {
        number->head->prev = p;
        p->next = number->head;
        number->head = p;
    }
    number->n++;
}

void PrintMNumber(MNumber number) {
    Item *p = number.tail;
    printf("Number: ");
    while (p) {
        printf("%d", p->digit);
        p = p->prev;
    }
    printf("\n");
}

int Rank(int number) {
    int rank = 0;
    while (number != 0) {
        number /= 10;
        rank += 1;
    }
    return rank;
}

MNumber SumMNumber(MNumber n1, MNumber n2) {
    MNumber sum = CreateMNumber("");
    Item *p1 = n1.head, *p2 = n2.head;
    int digit, pos = 0, s1, s2;
    while (p1 || p2) {
        if (p1) {
            s1 = p1->digit;
            p1 = p1->next;
        }
        else {
            s1 = 0;
        }
        if (p2) {
            s2 = p2->digit;
            p2 = p2->next;
        }
        else {
            s2 = 0;
        }
        digit = (s1 + s2 + pos) % 10;
        pos = (s1 + s2 + pos) / 10;
        AddDigit(&sum, digit);
    }
    if (pos) AddDigit(&sum, pos);
    return sum;
}

int Equal(MNumber n1, MNumber n2) {
    Item *p1 = n1.tail;
    Item *p2 = n2.tail;
    while (p1 || p2) {
        if (p1 == NULL && p2 != NULL) return -1;
        else if (p2 == NULL && p1 != NULL) return 1;
        p1 = p1->prev;
        p2 = p2->prev;
    }
    p1 = n1.tail;
    p2 = n2.tail;
    while (p1 || p2) {
        if (p1->digit > p2->digit) return 1;
        else if (p2->digit > p1->digit) return -1;
        p1 = p1->prev;
        p2 = p2->prev;
    }
    return 0;
}

MNumber LongMulShort(MNumber n1, int n2) {
    MNumber prod = CreateMNumber("0");
    MNumber tempprod;
    Item *p;
    int i, j, s, pos, digit, m;
    int size = Rank(n2);
    for (i = 0; i < size; i += 1) {
        tempprod = CreateMNumber("");
        pos = 0;
        m = n2 % 10;
        p = n1.head;
        for (j = 0; j < i; j += 1) {
            AddDigit(&tempprod, 0);
        }
        while (p) {
            if (p) {
                s = p->digit;
                p = p->next;
            }
            else {
                s = 0;
            }
            digit = (s * m + pos) % 10;
            pos = (s * m + pos) / 10;
            AddDigit(&tempprod, digit);
        }
        if (pos) AddDigit(&tempprod, pos);
        prod = SumMNumber(tempprod, prod);
        n2 /= 10;
    }
    return prod;
}

MNumber LongDivShort(MNumber n1, int n2) {
    MNumber res = CreateMNumber("");
    Item *p = n1.tail;
    int temp = 0, digit;
    while (temp / n2 == 0) {
        if (p == NULL) return res = CreateMNumber("0");
        temp = temp * 10 + p->digit;
        p = p->prev;
    }
    while (p) {
        digit = temp / n2;
        ReverseAddDigit(&res, digit);
        temp = (temp % n2) * 10 + p->digit;
        p = p->prev;
    }
    digit = temp / n2;
    ReverseAddDigit(&res, digit);
    return res;
}

int LongModShort(MNumber n1, int n2) {
    MNumber res = CreateMNumber("");
    Item *p = n1.tail;
    int temp = 0, digit;
    while (temp / n2 == 0) {
        if (p == NULL) return temp;
        temp = temp * 10 + p->digit;
        p = p->prev;
    }
    while (p) {
        temp = (temp % n2) * 10 + p->digit;
        p = p->prev;
    }
    temp = temp % n2;
    return temp;
}

void freeNumb(MNumber number) {
    Item *n;
    Item *p = number.tail;
    while(p) {
        n = p->prev;
        free(p);
        p = n;
    }
}

#ifndef TESTING

int main() {
    MNumber a, b, c;
    char* string;
    char num1[30], num2[30];
    int choose, number;
    while (1) {
        printf("\nChoose function: \n");
        printf("1. To compare 2 numbers\n");
        printf("2. To multiply 2 numbers\n");
        printf("3. To divide 2 numbers\n");
        printf("4. To get a remainder of division\n");
        printf(">4. To close program\n");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                printf("Enter the first number: ");
                scanf("%s", num1);
                printf("Enter the second number: ");
                scanf("%s", num2);
                a = CreateMNumber(num1);
                b = CreateMNumber(num2);
                if (Equal(a, b) == 0) printf("Numbers are equal\n");
                else if (Equal(a, b) == 1) printf("First number is greater than second\n");
                else if (Equal(a, b) == -1) printf("Second number is greater than first\n");
                freeNumb(a);
                freeNumb(b);
                break;
            case 2:
                printf("Enter the first number (long): ");
                scanf("%s", num1);
                printf("Enter the second number (short): ");
                scanf("%d", &number);
                a = CreateMNumber(num1);
                c = LongMulShort(a, number);
                PrintMNumber(c);
                freeNumb(a);
                freeNumb(c);
                break;
            case 3:
                printf("Enter the first number (long): ");
                scanf("%s", num1);
                printf("Enter the second number (short): ");
                scanf("%d", &number);
                a = CreateMNumber(num1);
                c = LongDivShort(a, number);
                PrintMNumber(c);
                freeNumb(a);
                freeNumb(c);
                break;
            case 4:
                printf("Enter the first number (long): ");
                scanf("%s", num1);
                printf("Enter the second number (short): ");
                scanf("%d", &number);
                a = CreateMNumber(num1);
                printf("%d", LongModShort(a, number));
                freeNumb(a);
                break;
            default:
                return 0;
        }
    }
}

#endif
