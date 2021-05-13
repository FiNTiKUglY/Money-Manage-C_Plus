#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <assert.h>

#include "main.h"

using namespace std;

extern char currentDate[11];

int test_all() {
    vector<Human> test;
    vector<Human> testCopy;
    initialization(&test, "test.txt");
    sortList(&test);
    assert(test[0].lastName == "User2");
    assert(test[3].lastName == "User3");
    assert(getAllMoney(test) == 18000);
    moneyTopUp(&test[0], 1000, "testdischarge.txt");
    assert(test[0].money == 7000);
    moneyWithdraw(&test[3], 1000, "testdischarge.txt");
    assert(test[3].money == 2000);
    moneyTransfer(&test[1], &test[2], 500, "testdischarge.txt");
    assert(test[1].money == 4500);
    assert(test[2].money == 4500);
    synchronization(test, "testNew.txt");
    initialization(&testCopy, "testNew.txt");
    assert(test[0].lastName == "User2");
    assert(procent(test[0], "15.05.2023") == 10092);
    assert(procent(test[0], "19.12.2021") == 7783);
    assert(dateFormat("01.04.2021"));
    assert(!dateFormat("2..12.2022"));
    assert(!dateFormat("20.13.2022"));
    assert(!dateFormat("31.11.2022"));
}

#undef main

int main() {
    time_t rawtime;
    struct tm * timeinfo;       
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(currentDate, 11, "%d.%m.%Y", timeinfo);
    test_all();
    printf("\nTest succesfully completed");
    return 0;
}

