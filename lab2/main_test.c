#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_procent() {
    assert(procent(1000, "02.03.2022") == 1128);
}

int test_AddMoney() {
    assert(AddMoney(1000, 100) == 1100);
}

int test_dateChecker() {
    assert(dateChecker("01.04.2021"));
    assert(!dateChecker("2..12.2022"));
}

#undef main

int main() {
    test_procent();
    test_AddMoney();
    test_dateChecker();
    printf("Test succesfully completed");
    return 0;
}
