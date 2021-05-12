#include <iostream>
#include <math.h>
#include <fstream>
#include <time.h>
#include <vector>

#include "main.h"

using namespace std;

char currentDate[11];

int inputCheck(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (input >= min && input <= max) return input;
        cout << "Try again" << endl;
    }
}

void initialization(vector<Human> *list, string fileName) {
    ifstream fin(fileName);
    Human chel;
	while (!fin.eof()) {
		fin >> chel.account;
		fin >> chel.category;
		fin >> chel.name;
		fin >> chel.lastName;
        fin >> chel.birthDate;
        fin >> chel.city;
        fin >> chel.number;
        fin >> chel.money;
        (*list).push_back(chel);
	}
    fin.close();
}

void synchronization(vector<Human> list, string fileName) {
    ofstream fout;
    int i;
    fout.open(fileName, ios::out | ios::trunc);
    for (i = 0; i < list.size() - 1; i++) {
        fout << list[i].account << " ";
		fout << list[i].category << " ";
		fout << list[i].name << " ";
		fout << list[i].lastName << " ";
        fout << list[i].birthDate << " ";
        fout << list[i].city << " ";
        fout << list[i].number << " ";
        fout << list[i].money << "\n";
    }
    fout << list[i].account << " ";
	fout << list[i].category << " ";
	fout << list[i].name << " ";
	fout << list[i].lastName << " ";
    fout << list[i].birthDate << " ";
    fout << list[i].city << " ";
    fout << list[i].number << " ";
    fout << list[i].money;
    fout.close();
}

void lookList(vector<Human> list) {
    int i = 0;
    for (Human chel : list) {
        cout << i + 1 << ". " << chel.name << " " << chel.lastName << endl;
        i++;
    }
}

void lookInfo(Human chel) {
	cout << "Number of account: " << chel.account << endl;
	cout << "Category of account: ";
	if (chel.category == (int)VysheNet) cout << "Vyshe.net" << endl;
	else if (chel.category == (int)VysheNetIrrevocable) cout << "Vyshe.net (irrevocalbe)" << endl;
	else if (chel.category == (int)Stars5) cout << "5 stars" << endl;
	else if (chel.category == (int)Stars5Irrevocable) cout << "5 stars (irrevocalbe)" << endl;
	cout << "Name: " << chel.name << " " << chel.lastName << endl;
    cout << "Date of birth: " << chel.birthDate << endl;
    cout << "City of birth: " << chel.city << endl;
    cout << "Passport`s number: " << chel.number << endl;
    cout << "Left money: " << chel.money << endl << endl;
}

void sortList(vector<Human> *list) {
    for (int i = 1; i < (*list).size(); i++) {
		for (int j = 0; j < (*list).size() - i; j++) {
			if ((*list)[j].money < (*list)[j + 1].money) {
				swap((*list)[j], (*list)[j + 1]);
			}
		}
	}
}

int getAllMoney(vector<Human> list) {
    int all = 0;
    for (Human chel : list) {
        all += chel.money;
    }
    return all;
}

void moneyTransfer(Human* sender, Human* receiver, int money) {
    (*sender).money -= money;
    (*receiver).money += money;
    //квитанция
}

void moneyWithdraw(Human* acc, int money) {
    (*acc).money -= money;
    //квитанция
}

void moneyTopUp(Human* acc, int money) {
    (*acc).money += money;
    //квитанция
}

int procent(Human acc, string date) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = 0, month = 0, year = 0, dateInt;
    int currDay = 0, currMonth = 0, currYear = 0;
    double procent;
    int newmoney = acc.money;
	if (acc.category == (int)VysheNetIrrevocable || acc.category == (int)Stars5Irrevocable) procent = 0.185;
	else procent = 0.11;
    for (int i = 0; i < 2; i++) {
        day += (date[i] - '0') * pow(10, (1 - i));
        currDay += (currentDate[i] - '0') * pow(10, (1 - i));
    }
    for (int i = 3; i < 5; i++) {
        month += (date[i] - '0') * pow(10, (4 - i));
        currMonth += (currentDate[i] - '0') * pow(10, (4 - i));
    }
    for (int i = 6; i < 10; i++) {
        year += (date[i] - '0') * pow(10, (9 - i));
        currYear += (currentDate[i] - '0') * pow(10, (9 - i));
    }
    dateInt = (year - currYear) * 12 + (month - currMonth);
    if (currDay > day) dateInt--;
    if (dateInt > 24) dateInt = 24;
    for (int i = 0; i < dateInt; i++) {
        int n = i % 12;
        newmoney = newmoney * (1 + (procent / 365 * days[n]));
    }
    return newmoney;
}

void lookInfoInDate(Human acc, string date) {
    int dayMoney;
    dayMoney = procent(acc, date);
    printf("\nYour amount of money in this day will be %d\n", dayMoney);
}

bool dateFormat(string date)
{
	int check = true;
	static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, day = 0, mon = 0, year = 0;
	if (date.length() != 10) return false;
	for (i = 0; i < 2; i += 1) {
		if (!(date[i] > 47 && date[i] < 58)) check = false;
		day += (date[i] - 48) * pow(10, 1 - i);
	}
	for (i = 3; i < 5; i += 1) {
		if (!(date[i] > 47 && date[i] < 58)) check = false;
		mon += (date[i] - 48) * pow(10, 4 - i);
	}
    for (i = 6; i < 10; i += 1) {
        if (!(date[i] > 47 && date[i] < 58)) check = false;
        year += (date[i] - 48) * pow(10, 9 - i);
    }
	if (date[2] != '.' || date[5] != '.') check = false;
	if (day > days[mon - 1] || mon > 12) check = false;
    if (year < 2021) check = false;
	return check;
}

#ifndef TESTING

int main() {
    time_t rawtime;
    struct tm * timeinfo;       
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(currentDate, 11, "%d.%m.%Y", timeinfo);
    vector<Human> chel;
    int choose = 1, index, index2, money;
	initialization(&chel, "data.txt");
    system("cls");
    do {
        cout << currentDate << endl;
        printf("\n");
        lookList(chel);
        printf("\n");
        cout << "0. Close the system" << endl;
        cout << "1. To choose client" << endl;
        cout << "2. Sort list" << endl;
        cout << "3. Get money of every client" << endl;
        choose = inputCheck(0, 3);
        system("cls");
        switch (choose)
        {
            case 1:
                lookList(chel);
                printf("\n");
                index = inputCheck(1, chel.size());
                system("cls");
                do {
                    cout << "0. Back to menu" << endl;
                    cout << "1. Look info" << endl;
                    cout << "2. Top up money" << endl;
                    cout << "3. Withdraw money" << endl;
                    cout << "4. To transfer money" << endl;
                    cout << "5. To look money at date" << endl << endl;
                    choose = inputCheck(0, 5);
                    system("cls");
                    switch (choose)
                    {
                        case 1:
                            lookInfo(chel[index - 1]);
                            system("pause");
                            cin.get();
                            system("cls");
                            break;
                        case 2:
                            cout << "Enter amount of money to top up" << endl;
                            cin >> money;
                            moneyTopUp(&chel[index - 1], money);
                            system("pause");
                            cin.get();
                            system("cls");
                            break;
                        case 3:
                            cout << "Enter amount of money to withdraw" << endl;
                            cin >> money;
                            moneyWithdraw(&chel[index - 1], money);
                            system("pause");
                            cin.get();
                            system("cls");
                            break;
                        case 4:
                            lookList(chel);
                            cout << "\nChoose receiver" << endl;
                            index2 = inputCheck(1, chel.size());
                            cout << "Enter amount of money to transfer" << endl;
                            cin >> money;
                            moneyTransfer(&chel[index - 1], &chel[index2 - 1], money);
                            system("pause");
                            cin.get();
                            system("cls");
                            break;
                        case 5:
                            char date[20];
                            cout << "Enter date" << endl;
                            while (true)
                            {
                                cin >> date;
                                if (dateFormat(date) == true) break;
                                else cout << "Invalid date" << endl;
                            }
                            lookInfoInDate(chel[index - 1], date);
                            system("pause");
                            cin.get();
                            system("cls");
                            break;
                        default:
                            system("cls");
                            break;
                    }
                } while (choose != 0);
                choose = 1;
                break;
            case 2:
                sortList(&chel);
                system("cls");
                break;
            case 3:
                cout << getAllMoney(chel) << endl;
                system("pause");
                cin.get();
                system("cls");
                break;
            default:
                system("cls");
                break;
        }
    } while (choose != 0);
    cout << "Closing system..........";
    synchronization(chel, "data.txt");
}

#endif
