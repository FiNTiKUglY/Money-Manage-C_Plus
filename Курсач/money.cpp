﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "money.h"

#include <cmath>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <vcl.h>
#include <locale.h>

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)

void initialization(vector<Wallet> *list, String fileName) {
	TStringList *Wallets = new TStringList;
    Wallets -> LoadFromFile(fileName);
	for (int i = 0; i < Wallets -> Count; i++)
	{
        Wallet elem;
		TStringList *Strings = new TStringList;
        Strings -> Delimiter = ' ';
		Strings -> DelimitedText = Wallets -> Strings[i];
		elem.name = Strings -> Strings[0];
		elem.money = StrToFloat(Strings -> Strings[1]);
        (*list).push_back(elem);
	}
}

void discharge(Wallet acc, String text, String fileName) {
    String currentDate = DateToStr(Date());
    TStringList *Wallets = new TStringList;
    Wallets -> LoadFromFile(fileName);
	Wallets -> Add(currentDate + " " + acc.name + " " + text);
    Wallets -> SaveToFile(fileName);
}

void synchronization(vector<Wallet> list, String fileName) {
	TStringList *Wallets = new TStringList;
    for (int i = 0; i < list.size(); i++) {
		Wallets -> Add(list[i].name + " " + FloatToStrF(list[i].money, ffFixed, 18, 2));
	}
    Wallets -> SaveToFile(fileName);
}

void moneyWithdraw(Wallet* acc, float money, String fileName, String flag) {
	(*acc).money -= money;
	String text;
	text = flag + "на сумму " + FloatToStrF(money, ffFixed, 18, 2);
	discharge((*acc), text, fileName);
}

void moneyTopUp(Wallet* acc, float money, String fileName, String flag) {
    (*acc).money += money;
    String text;
	text = flag + "на сумму " + FloatToStrF(money, ffFixed, 18, 2);
	discharge((*acc), text, fileName);
}

void printMoney(int index, TLabel* Label8, float money)
{
    switch (index)
	{
		case 0:
            Label8 -> Caption = FormatFloat("0.00", money);
			Label8 -> Caption += " BYN";
			break;
		case 1:
			Label8 -> Caption = FormatFloat("0.00", money / 0.034);
			Label8 -> Caption += " RUS";
			break;
		case 2:
			Label8 -> Caption = FormatFloat("0.00", money / 2.51);
			Label8 -> Caption += " $";
			break;
		case 3:
			Label8 -> Caption = FormatFloat("0.00", money / 3.06);
			Label8 -> Caption += " €";
			break;
		case 4:
			Label8 -> Caption = FormatFloat("0.00", money / 0.091);
			Label8 -> Caption += " UAH";
            break;
	}
}

void printTotalMoney(int index, TLabel* Label, float money)
{
    switch (index)
	{
		case 0:
			Label -> Caption = FormatFloat("0.00", money);
			break;
		case 1:
			Label -> Caption = FormatFloat("0.00", money / 0.034);
			break;
		case 2:
			Label -> Caption = FormatFloat("0.00", money / 2.51);
			break;
		case 3:
			Label -> Caption = FormatFloat("0.00", money / 3.06);
			break;
		case 4:
			Label -> Caption = FormatFloat("0.00", money / 0.091);
            break;
	}
}

float moneyConvert(int index, float money)
{
    int temp;
    float x;
    switch (index)
	{
		case 0:
			return money;
		case 1:
			money = money * 0.034;
			return money;
		case 2:
			money = money * 2.51;
			return money;
		case 3:
			money = money * 3.06;
			return money;
		case 4:
			money = money * 0.091;
			return money;
	}
    return 0;
}

void checkAutoPays(vector<Wallet> *list, String fileName)
{
	TDateTime today = Date();
	TStringList *Lists = new TStringList;
	Lists -> LoadFromFile(fileName);
	for (int i = 0; i < Lists -> Count; i++)
	{
		TStringList *Strings = new TStringList;
        Strings -> Delimiter = ' ';
		Strings -> DelimitedText = Lists -> Strings[i];
		TDateTime begin = StrToDate(Strings -> Strings[0]);
		int compare = StrToInt(Strings -> Strings[1]);
		String name = Strings -> Strings[2];
		String type = Strings -> Strings[3] + " ";
		float money = StrToFloat(Strings -> Strings[4]);
		int comparision = today.Val - begin.Val;
		if (comparision % compare != 0) continue;
		int index = getIndex(*list, name);
		moneyWithdraw(&(*list)[index], money, "C:\\Users\\ilyap\\source\\repos\\Курсач\\Win32\\Debug\\discharge.txt", type);
	}
}

int getIndex(vector<Wallet> list, String name)
{
	for (int i = 0; i < list.size(); i++)
	{
        if (list[i].name == name) return i;
	}
    return 0;
}

float expenses(vector<TLabel*> labels, String walletName, String fileName)
{
    vector<float> amounts = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    TDateTime today = Date();
	TStringList *Lists = new TStringList;
	Lists -> LoadFromFile(fileName);
	for (int i = 0; i < Lists -> Count; i++)
	{
		TStringList *Strings = new TStringList;
        Strings -> Delimiter = ' ';
		Strings -> DelimitedText = Lists -> Strings[i];
		TDateTime date = StrToDate(Strings -> Strings[0]);
		if ((today.Val - date.Val) > 31) continue;
		String name = Strings -> Strings[1];
		if (name != walletName) continue;
        String type = Strings -> Strings[2];
		float money = StrToFloat(Strings -> Strings[5]);
		if (type ==  "развлечения") amounts[0] += money;
		else if (type == "такси") amounts[1] += money;
		else if (type == "жильё") amounts[2] += money;
		else if (type == "еда") amounts[3] += money;
		else if (type == "одежда") amounts[4] += money;
		else if (type == "здоровье") amounts[5] += money;
		else if (type == "транспорт") amounts[6] += money;
		else if (type == "путешествия") amounts[7] += money;
		else if (type == "прочее(расход)") amounts[8] += money;
	}
	float total = totalMoney(amounts);
	if (total != 0)
	{
		for (int i = 0; i < amounts.size(); i++)
		{
			labels[i] -> Caption = FormatFloat("0.00", amounts[i] / total * 100) + "%";
		}   	
    }
	else
	{
		for (int i = 0; i < amounts.size(); i++)
		{
			labels[i] -> Caption = "0,00%";
		}
    }
	return total;
}

float income(vector<TLabel*> labels, String walletName, String fileName)
{
    vector<float> amounts = {0, 0, 0, 0};
    TDateTime today = Date();
	TStringList *Lists = new TStringList;
	Lists -> LoadFromFile(fileName);
	for (int i = 0; i < Lists -> Count; i++)
	{
		TStringList *Strings = new TStringList;
        Strings -> Delimiter = ' ';
		Strings -> DelimitedText = Lists -> Strings[i];
		TDateTime date = StrToDate(Strings -> Strings[0]);
		if ((today.Val - date.Val) > 31) continue;
		String name = Strings -> Strings[1];
		if (name != walletName) continue;
        String type = Strings -> Strings[2];
		float money = StrToFloat(Strings -> Strings[5]);
		if (type ==  "зарплата") amounts[0] += money;
		else if (type == "подарки") amounts[1] += money;
		else if (type == "ставки") amounts[2] += money;
		else if (type == "прочее(доход)") amounts[3] += money;
	}
	float total = totalMoney(amounts);
	if (total != 0)
	{
		for (int i = 0; i < amounts.size(); i++)
		{
			labels[i] -> Caption = FormatFloat("0.00", amounts[i] / total * 100) + "%";
		}   	
    }
	else
	{
		for (int i = 0; i < amounts.size(); i++)
		{
			labels[i] -> Caption = "0,00%";
		}
    }
	return total;
}

float totalMoney(vector<float> amounts)
{
	float total = 0;
	for (int i = 0; i < amounts.size(); i++)
	{
		total += amounts[i];
	}
	return total;
}
