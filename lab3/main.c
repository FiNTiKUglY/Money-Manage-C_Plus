#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void show(int* board) {
    int i, j;
    for (i = 0; i < 8; i += 1) {
        for (j = 0; j < board[i]; j += 1) {
            printf(". ");
        }
        printf("Q ");
        for (j = board[i] + 1; j < 8; j += 1) {
            printf(". ");
        }
        printf("\n");
    }
}

int posChecker(int* board, int pos) {
    int i;
    for (i = 0; i < pos; i += 1) {
        if (board[i] == (board[pos] - (pos - i))) return 0;
        else if (board[i] == ((pos - i) + board[pos])) return 0;
        else if (board[i] == board[pos]) return 0;
    }
    return 1;
}

void put(int* board, int constPos) {
    int i = 0;
    while (1) {
        if (i == 8) return;               
        if (board[i] == 8) {
            board[i] = 0;
            i -= 1;
            if (i == constPos) i -= 1;
            board[i] += 1; 
            continue;
        }
        if (posChecker(board, i)) i += 1;
        else {
            if (i == constPos) i -= 1; 
            board[i] += 1;
        }
    }
}

#ifndef TESTING

int main(int argc, char** argv)
{
    int i;
    int r1, r2, n;
    int* board = (int*)malloc(sizeof(int) * 8);
    for (i = 0; i < 8; i += 1) {
        board[i] = 0;
    }
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
    board[r1] = r2;
    printf("Your cords: %d row and %d column\n", r1 + 1, r2 + 1);
    put(board, r1);
    show(board);
    free(board);
    return 0;
}

#endif
