#ifndef MAINH
#define MAINH

using namespace std;

enum Deposit {
	VysheNet = 1,
	VysheNetIrrevocable,
	Stars5,
	Stars5Irrevocable,
};

struct Human {
    int account;
    int category;
    string name;
    string lastName;
    string birthDate;
    string city;
    int number;
    int money; 
};

int inputCheck(int min, int max);
void initialization(vector<Human> *list, string fileName);
void synchronization(vector<Human> list, string fileName);
void lookList(vector<Human> list);
void lookInfo(Human chel);
void sortList(vector<Human> *list);
int getAllMoney(vector<Human> list);
void moneyTransfer(Human* sender, Human* receiver, int money);
void moneyWithdraw(Human* acc, int money);
void moneyTopUp(Human* acc, int money);
int procent(Human acc, string date);
void lookInfoInDate(Human acc, string date);
bool dateFormat(string date);

#endif
