#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_fact() {
    assert(fact(5) == 120);
    assert(fact(7) == 5040);
}

int test_foundN() {
    assert(foundN(3, 0.006) == 5);
}

#undef main

int main() {
    test_fact();
    test_foundN();
    printf("Test succesfully completed");
    return 0;
}
