#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_fileExist() {
    assert(fopen("input.txt", "r") != NULL);
    assert(fopen("doesn`tExist.txt", "r") == NULL);
}

int test_dateChecker() {
    assert(dateChecker("22.12.77") == 1);
    assert(dateChecker("12.07.12") == 1);
    assert(dateChecker("08.04.27") == 0);
}

int test_number() {
    assert(number("2320") == 2320);
    assert(number("716870") == 716870);
}

#undef main

int main() {
    test_fileExist();
    test_dateChecker();
    test_number();
    printf("Test succesfully completed");
    return 0;
}
