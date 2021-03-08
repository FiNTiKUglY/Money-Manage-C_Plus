#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_procent() {
    assert(procent(1000, "02.03.2022") == 1128);
}

int test_AddMoney() {
    assert(AddMoney(1000, 100) == 1100);
}

#undef main

int main() {
    test_procent();
    test_AddMoney();
    printf("Test succesfully completed");
    return 0;
}
