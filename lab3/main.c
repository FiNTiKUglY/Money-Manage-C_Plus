#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
#include "main.h"

int min(int first, int second) {
    if (first < second)
        return first;
    return second;
}
 
void show(int board[][8]) {
    int i, j;
    for (i = 0; i < 8; i += 1) {
        for (j = 0; j < 8; j += 1) {
            if (board[i][j] == 0) printf(". ");
            else printf("Q ");
        }
        printf("\n");
    }
}
 
int posChecker(int board[][8], int x, int y) {
    int i, j, m;
    for (i = 0; i < 8; i += 1) {
        if (board[i][y] || board[x][i])
            return 0;
    }
    m = min(x, y);
    for (i = x - m, j = y - m; i < 8 && j < 8; i += 1, j += 1) {
        if (board[i][j])
            return 0;
    }
    m = min(x, 7 - y);
    for (i = x - m, j = y + m; i < 8 && j < 8; i += 1, j -= 1) {
        if (board[i][j])
            return 0;
    }
    return 1;
}
 
int put(int board[][8], int count) {
    int i, j;
    if (count == 8)
        return 1;
    for (i = 0; i < 8; i += 1) {
        for (j = 0; j < 8; j += 1) {
            if (posChecker(board, i, j)) {
                board[i][j] = count + 1;
                if (put(board, count + 1))
                    return 1;
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

#ifndef TESTING

int main(int argc, char** argv)
{
    int board[8][8] = {0};
    int r1, r2, n;
    printf("If you want to put the first queen by yourself type '1'\nif you want to get random position type '2'\n");
    scanf("%d", &n);
    switch(n) {
        case 1:
            printf("First cord (from 1 to 8): ");
            scanf("%d", &r1);
            r1 -= 1;
            printf("Second cord(from 1 to 8): ");
            scanf("%d", &r2);
            r2 -= 1;
            break;
        case 2:
            srand(time(NULL));
            r1 = rand() % 8;
            r2 = rand() % 8;
            break;
        default:
            exit(0);    
    }
    board[r1][r2] = 1;
    show(board);
    printf("\n\n");
    put(board, 1);
    show(board);
    return 0;
}

#endif
