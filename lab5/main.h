#ifndef MAINH
#define MAINH

typedef struct item {
    int digit;
    struct item *next;
    struct item *prev;
} Item;

typedef struct mnumber {
    Item *head;
    Item *tail;
    int n;
} MNumber;

MNumber CreateMNumber(char* initStr);
char* MNumberToString(MNumber number);
void AddDigit(MNumber *number, int digit);
void ReverseAddDigit(MNumber *number, int digit);
void PrintMNumber(MNumber number);
int Rank(int number);
MNumber SumMNumber(MNumber n1, MNumber n2);
int Equal(MNumber n1, MNumber n2);
MNumber LongMulShort(MNumber n1, int n2);
MNumber LongDivShort(MNumber n1, int n2);
int LongModShort(MNumber n1, int n2);
void freeNumb(MNumber number);

#endif
