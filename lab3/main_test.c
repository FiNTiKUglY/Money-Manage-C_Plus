#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int test_posChecker() {
    int i;
    int* board = (int*)malloc(sizeof(int) * 8);
    board[0] = 0;
    board[1] = 2;
    board[2] = 3;
    board[3] = 0;
    assert(posChecker(board, 1) == 1);
    assert(posChecker(board, 2) == 0);
    assert(posChecker(board, 3) == 0);
}

#undef main

int main() {
    test_posChecker();
    printf("Test succesfully completed");
    return 0;
}
