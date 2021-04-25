#ifndef MAINH
#define MAINH

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

void addNode(int data, Node **node);
void ascendingOrder(Node *node);
void descendingOrder(Node *node);
int nodesSum(Node *node);
Node* findMax(Node ***trees, int size_n, int size_m);

#endif
