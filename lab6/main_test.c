#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int amountOfNodes(Node *node) {
    if (node == NULL) return 0;
    return 1 + amountOfNodes(node->left) + amountOfNodes(node->right);
}

int test_all() {
    int i;
    Node*** rootsArr;
    Node* root = NULL;
    assert(amountOfNodes(root) == 0);
    addNode(7, &root);
    addNode(12, &root);
    assert(amountOfNodes(root) == 2);
    assert(nodesSum(root) == 19);
    rootsArr = (Node***)malloc(sizeof(Node**) * 1);
    if (rootsArr == NULL) {
        printf("No memory\n");
        exit(1);
    }
    for (i = 0; i < 1; i += 1) {
        rootsArr[i] = (Node**)malloc(sizeof(Node*) * 2);
        if (rootsArr[i] == NULL) {
            printf("No memory\n");
            exit(1);
        }
    }
    rootsArr[0][0] = root;
    rootsArr[0][1] = NULL;
    addNode(8, &rootsArr[0][1]);
    addNode(23, &rootsArr[0][1]);
    assert(findMax(rootsArr, 1, 2) == rootsArr[0][1]);
}

#undef main

int main() {
    test_all();
    printf("\nTest succesfully completed");
    return 0;
}
