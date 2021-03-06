#include "pch.h"
#include <iostream>
#include <conio.h>

using namespace std;

void stringsOutput(char(&string1)[51], char(&string2)[51])
{
	cout << "First string: " << '\t';
	for (int i = 0; i < 50; i++)
	{
		cout << string1[i];
		if (string1[i + 1] == 0)
			break;
	}
	cout << '\n' << '\n' << "Second string: " << '\t';
	for (int i = 0; i < 50; i++)
	{
		cout << string2[i];
		if (string2[i + 1] == 0)
			break;
	}
	cout << '\n';
}

void stringComparison(char(&string1)[51], char(&string2)[51])
{
	short int rel = 0, i = 0;
	while ((rel == 0) && (i < 51))
	{
		if (string1[i] > string2[i])
			rel = -1;
		else if (string1[i] < string2[i])
			rel = 1;
		i++;
	}
	switch (rel)
	{
	case -1:
		cout << "String 1 > String 2";
		break;
	case 0:
		cout << "String 1 = String 2";
		break;
	case 1:
		cout << "String 1 < String 2";
	}
}

void stringCopying(char(&string1)[51], char(&string2)[51])
{
	for (int i = 0; i < 51; i++)
		string1[i] = string2[i];
	cout << "Done";
}

void combineStrings(char(&string1)[51], char(&string2)[51], char(&string3)[101])
{
	int i = 0, j = 0;
	for (i = 0; i < 50; i++)
	{
		string3[i] = string1[i];
		if (string1[i + 1] == 0)
			break;
	}
	for (int j = 0; j < 51; j++)
	{
		string3[i] = string2[j];
		if (string2[j + 1] == 0)
			break;
		i++;
	}
	i++;
	for (; i < 101; i++)
		string3[i] = 0;
}

short int menu(short int num1, short int num2, short int arrow)
{
	if (num1 == 224)
	{
		if (num2 == 72)
			if (arrow > 49)
				num1 = --arrow;
			else
				num1 = 52; //num1 = arrow;
		else if (num2 == 80)
			if (arrow < 52)
				num1 = ++arrow;
			else
				num1 = 49; //num1 = arrow;
		else
			num1 = arrow;
	}

	cout << '\n' << "Lengths of strings  ";
	if (num1 == 49)
		cout << "<--";
	cout << '\n' << "String comparison   ";
	if (num1 == 50)
		cout << "<--";
	cout << '\n' << "Copying string      ";
	if (num1 == 51)
		cout << "<--";
	cout << '\n' << "Combine strings     ";
	if (num1 == 52)
		cout << "<--";
	cout << '\n' << '\n' << "Press Esc to exit";
	return num1;
}

int main()
{
	char stringArr1[51] = {0}, stringArr2[51] = {0}, stringArr3[101] = {0};
	short int symbolCounter = 0, ch = 0, firstStringSize = 0, secondStringSize = 0;
	short int choose = 0, tempChoose = 0, arrowControl = 49;

	while ((symbolCounter < 51) && (ch != 13) && (ch != 27))
	{
		system("cls");
		cout << "First string input:" << '\n';
		for (int i = 0; i < 50; i++)
		{
			cout << stringArr1[i];
			if (stringArr1[i + 1] == 0)
				break;
		}
		ch = _getch();
		if ((ch == 8) && (symbolCounter > 0))
		{
			symbolCounter--;
			stringArr1[symbolCounter] = 0;
		}
		if ((ch >= 32) && (ch <= 252))
		{
			if (ch != 224)
			{
				stringArr1[symbolCounter] = ch;
				symbolCounter++;
			}
			else if (!_getch())
			{
				stringArr1[symbolCounter] = ch;
				symbolCounter++;
			}
		}
	}
	if (symbolCounter == 51)
		symbolCounter--;
	firstStringSize = symbolCounter;
	if (ch == 27)
	{
		firstStringSize = 0;
		for (int i = 0; i < 51; i++)
			stringArr2[i] = 0;
	}

	system("cls");
	symbolCounter = 0;
	ch = 0;
	while ((symbolCounter < 51) && (ch != 13) && (ch != 27))
	{
		system("cls");
		cout << "Second string input:" << '\n';
		for (int i = 0; i < 50; i++)
		{
			cout << stringArr2[i];
			if (stringArr2[i + 1] == 0)
				break;
		}
		ch = _getch();
		if ((ch == 8) && (symbolCounter > 0))
		{
			symbolCounter--;
			stringArr2[symbolCounter] = 0;
		}
		if ((ch >= 32) && (ch <= 252))
		{
			if (ch != 224)
			{
				stringArr2[symbolCounter] = ch;
				symbolCounter++;
			}
			else if (!_getch())
			{
				stringArr2[symbolCounter] = ch;
				symbolCounter++;
			}
		}
	}
	if (symbolCounter == 51)
		symbolCounter--;
	secondStringSize = symbolCounter;
	if (ch == 27)
	{
		secondStringSize = 0;
		for (int i = 0; i < 51; i++)
			stringArr2[i] = 0;
	}
	ch = 0;

	system("cls");
	stringsOutput(stringArr1, stringArr2);
	cout << '\n' << "Lengths of strings  ";
	cout << "<--";
	cout << '\n' << "String comparison   ";
	cout << '\n' << "Copying string      ";
	cout << '\n' << "Combine strings     ";
	cout << '\n' << '\n' << "Press Esc to exit";

	while (choose != 27)
	{
		do
		{
			choose = _getch();
			if (choose == 224)
				tempChoose = _getch();
		} while ((choose != 27) && (choose != 49) && (choose != 50) && (choose != 51)
			&& (choose != 52) && (choose != 224) && (choose != 13));

		if (choose == 13)
		{
			system("cls");
			switch (arrowControl)
			{
			case 49:
				cout << "First string length:  " << firstStringSize << '\n';
				cout << "Second string length: " << secondStringSize;
				break;
			case 50:
				stringComparison(stringArr1, stringArr2);
				break;
			case 51:
				stringCopying(stringArr1, stringArr2);
				firstStringSize = secondStringSize;
				break;
			case 52:
				combineStrings(stringArr1, stringArr2, stringArr3);
				cout << "New string: " << '\t';
				for (int i = 0; i < 100; i++)
				{
					cout << stringArr3[i];
					if (stringArr3[i + 1] == 0)
						break;
				}
			}
			_getch();
			cout << '\n' << '\n' << "Press any key";
			_getch();
			choose = arrowControl;
		}
		system("cls");
		stringsOutput(stringArr1, stringArr2);
		arrowControl = menu(choose, tempChoose, arrowControl);
	}
	return 0;

	system("pause");
	return 0;
}
