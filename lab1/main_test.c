#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_sumChecker() {
    assert(sumChecker(5, 3, 2));
}

#undef main

int main() {
    test_sumChecker();
    printf("Test succesfully completed");
    return 0;
}
