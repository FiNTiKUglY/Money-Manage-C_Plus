#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"

void addNode(int data, Node **node) {
    if (*node == NULL) {
        *node = (Node *)malloc(1 * sizeof(Node));
        if (*node == NULL) {
            printf("No memory");
            exit(1);
        }
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    }
    else {
        if (data < (*node)->data) addNode(data, &(*node)->left);
        else if (data > (*node)->data) addNode(data, &(*node)->right);
    }
}

int nodesSum(Node *node) {
    if (node == NULL) return 0;
    return node->data + nodesSum(node->left) + nodesSum(node->right);
}

Node* findMax(Node ***trees, int size_n, int size_m) {
    int i, j, temp;
    int i_max = 0, j_max = 0;
    int max = nodesSum(trees[0][0]);
    printf("\nValues of trees:\n");
    for (i = 0; i < size_n; i += 1) {
        for (j = 0; j < size_m; j += 1) {
            temp = nodesSum(trees[i][j]);
            printf("%5d ", temp);
            if (max < temp) {
                max = temp;
                i_max = i;
                j_max = j;
            }
        }
        printf("\n");
    }
    return trees[i_max][j_max];
}

void ascendingOrder(Node *node) {
    if (node->left) ascendingOrder(node->left);
    printf("%d ", node->data);
    if (node->right) ascendingOrder(node->right);
}

void descendingOrder(Node *node) {
    if (node->right) descendingOrder(node->right);
    printf("%d ", node->data);
    if (node->left) descendingOrder(node->left);
}

#ifndef TESTING

int main() {
    char buffer[128];
    int i, j, n, m;
    Node*** root;
    Node* rootMax;
    FILE *file;
    srand(time(NULL));
    printf("Enter field range (n * m):\n");
    while (!(scanf("%d", &n) == 1)) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    while (!(scanf("%d", &m) == 1)) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    root = (Node***)malloc(sizeof(Node**) * n);
    if (root == NULL) {
        printf("No memory\n");
        exit(1);
    }
    for (i = 0; i < n; i += 1) {
        root[i] = (Node**)malloc(sizeof(Node*) * m);
        if (root[i] == NULL) {
            printf("No memory\n");
            exit(1);
        }
    }
    for (i = 0; i < n; i += 1) {
        for (j = 0; j < m; j += 1) {
            root[i][j] = NULL;
        }
    }
    file = fopen("input.txt", "r");
    if (!file) exit(1);
    while (fgets(buffer, 128, file) != NULL) {
        i = rand() % n;
        j = rand() % m;
        addNode(atoi(buffer), &root[i][j]);
    }
    rootMax = findMax(root, n, m);
    printf("\nAscending tree output:\n");
    ascendingOrder(rootMax);
    printf("\n\nDescending tree output:\n");
    descendingOrder(rootMax);
    fclose(file);
}

#endif
