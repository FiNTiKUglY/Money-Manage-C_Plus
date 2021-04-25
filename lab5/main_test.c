#include <assert.h>
#include <stdio.h>

#include "main.h"

int test_Rank() {
    assert(Rank(123) == 3);
    assert(Rank(1234) == 4);
}

int test_SumMNumber() {
    MNumber a, b;
    a = CreateMNumber("1234");
    b = CreateMNumber("4321");
    assert(!strcmp(MNumberToString(SumMNumber(a, b)), "5555"));
    b = CreateMNumber("54321");
    assert(!strcmp(MNumberToString(SumMNumber(a, b)), "55555"));
    freeNumb(a);
    freeNumb(b);
}

int test_Equal() {
    MNumber a, b;
    a = CreateMNumber("1234567");
    b = CreateMNumber("1234567");
    assert(Equal(a, b) == 0);
    b = CreateMNumber("1234566");
    assert(Equal(a, b) == 1);
    b = CreateMNumber("1234568");
    assert(Equal(a, b) == -1);
    freeNumb(a);
    freeNumb(b);
}

int test_LongMulShort() {
    MNumber a;
    a = CreateMNumber("1234");
    assert(!strcmp(MNumberToString(LongMulShort(a, 2)), "2468"));
    assert(!strcmp(MNumberToString(LongMulShort(a, 11)), "13574"));
    freeNumb(a);
}

int test_LongDivShort() {
    MNumber a;
    a = CreateMNumber("1234");
    assert(!strcmp(MNumberToString(LongDivShort(a, 2)), "617"));
    assert(!strcmp(MNumberToString(LongDivShort(a, 5)), "246"));
    freeNumb(a);
}

int test_LongModShort() {
    MNumber a;
    a = CreateMNumber("1234");
    assert(LongModShort(a, 2) == 0);
    assert(LongModShort(a, 4) == 2);
    assert(LongModShort(a, 5) == 4);
    freeNumb(a);
}

#undef main

int main() {
    test_Rank();
    test_SumMNumber();
    test_Equal();
    test_LongMulShort();
    test_LongDivShort();
    test_LongModShort();
    printf("Test succesfully completed");
    return 0;
}
