#include <assert.h>
#include <stdio.h>

#include "main.h"

extern int n;

int test_strlen() {
    assert(strlen("1234") == 4);
    assert(strlen("65123") == 5);
}

int test_strCheck() {
    assert(strCheck("e23ae") == 0);
    assert(strCheck("12345678901") == 0);
    assert(strCheck("1234") == 1);
}

int test_StoI() {
    n = 0;
    assert(StoI(0, "1234") == 1234);
    n = 0;
    assert(StoI(0, "696123") == 696123);
}

#undef main

int main() {
    test_strlen();
    test_strCheck();
    test_StoI();
    printf("Test succesfully completed");
    return 0;
}
