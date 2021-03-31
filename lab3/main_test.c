#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_min() {
    assert(min(1, 2) == 1);
    assert(min(7, 4) == 4);
}

int test_posChecker() {
    int testboard[8][8] = 
    {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    assert(posChecker(testboard, 0, 3) == 0);
    assert(posChecker(testboard, 5, 5) == 0);
    assert(posChecker(testboard, 4, 3) == 1);
}

#undef main

int main() {
    test_min();
    test_posChecker();
    printf("Test succesfully completed");
    return 0;
}
