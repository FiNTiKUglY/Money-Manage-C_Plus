#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void receipt() {
	printf("________________\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("|              |\n");
	printf("________________\n");
}

int procent(int money, char* date) {
	int days[12] = {31, 30, 31, 30, 31, 31, 30, 31, 30 , 31, 31 , 28};
	int day, month, year, i, dateInt, newmoney;
	newmoney = money;
	day = 0;
	month = 0;
	year = 0;
	for (i = 0; i < 2; i += 1) {
		day = day + (date[i] - 48) * pow(10, (1 - i));
	}
	for (i = 3; i < 5; i += 1) {
		month += (date[i] - '0') * pow(10, (4 - i));
	}
	for (i = 6; i < 10; i += 1) {
		year += (date[i] - '0') * pow(10, (9 - i));
	}
	dateInt = (year - 2021) * 12 + (month - 3);
	for (i = 0; i < dateInt; i++) {
		newmoney = newmoney * (1 + (0.1275 / 365 * days[i]));
	}
	return newmoney;
}

int OpenAccount() {
    int money;
    printf("\nEnter the amount of money: ");
    while (!(scanf("%d", &money) == 1)) {
        printf("Try again: ");
        while (getchar() != '\n') {}
	}
    return money;
}

int AddMoney(int money, int addedMoney) {
    money += addedMoney;
    return money;
}

void LookInfo(int money) {
    printf("\nYour amount of money is %d\n", money);
}

void LookDayInfo(int money, char* date) {
	int newmoney;
	newmoney = procent(money, date);
	printf("\nYour amount of money in this day will be %d\n", newmoney);
}

void CloseAccount(int money) {
	receipt(); 
}

void LookBankInfo() {
    printf("\nTransitBank is the most reliable bank in Minsk.\nOur location is 123 Sovietskaya street.\n");
    printf("Phone number is 80(17)44-55-66\n");
}

int main() {	
    int money, number, addedMoney, i;
	char date[15];
    printf("Welcome to TransitBank system, please enter the number:\n");

    while(number != 1) {
	    printf("\n1. Open account\n");
	    printf("2. Look bank info\n");
	    printf("3. Close the system\n");
	    scanf("%d", &number);

	    switch (number) {
		    case 1:  
			    money = OpenAccount();
			    break;
		    case 2: 
			    LookBankInfo();
			    break;
		    case 3: 
			    exit(1);
		} 

	}

	while(number != 4) {
        printf("\n1. Add money\n");
        printf("2. Look account info\n");
		printf("3. Look account info at specified day\n");
		printf("4. Close account\n");
		printf("5. Look bank info\n");
		printf("6. Close the system\n");
		scanf("%d", &number);

		switch (number) {
			case 1:
				printf("\nEnter an additional amount of money: ");
				while (!(scanf("%d", &addedMoney) == 1)) {
    				printf("Try again: ");
    				while (getchar() != '\n') {}
				}
			    money = AddMoney(money, addedMoney);
				break;
			case 2:
			    LookInfo(money);
				break;
			case 3:
				printf("\nEnter date (xx.xx.xxxx format):\n");
				scanf("%s", &date);
			    LookDayInfo(money, date);
				break;
			case 4:
			    CloseAccount(money);
				exit(1);
			case 5:
			    LookBankInfo();
				break;
			case 6:
			    exit(1);
		}

	}
	
}
