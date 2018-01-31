#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>

using namespace std;

int q;

void ShiftRight3(int*a, int *b, int *c);

void ShiftLeft3(int*a, int *b, int *c);

int IsLeapYear(int year);

int MonthDays(int month, int year);

void PrevDate(int year, int month, int day);


void main()

{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			cout << "Описать процедуру ShiftRight3(A, B, C), выполняющую правый циклический" << endl
				<< "сдвиг: значение A переходит в B, значение B — в C, значение C — в A " << endl
				<< "(A, B, C — вещественные параметры, являющиеся одновременно входными " << endl
				<< "и выходными). С помощью этой процедуры выполнить правый циклический " << endl
				<< "сдвиг для двух данных наборов из трех чисел: (A1, B1, C1) и (A2, B2, C2).\n\n";

			int a = rand() % 50, b = rand() % 50, c = rand() % 50;
			cout << "значения будут сгенерированы рандомно:\n";
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl;
			cout << "\nпосле действия функции: \n";

			ShiftRight3(&a, &b, &c);
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl << endl;


		}break;

		case 2:
		{
			cout << "Описать процедуру ShiftLeft3(A, B, C), выполняющую левый циклический" << endl
				<< "сдвиг : значение A переходит в C, значение C — в B, значение B — в A" << endl
				<< "(A, B, C — вещественные параметры, являющиеся одновременно входными" << endl
				<< "и выходными).С помощью этой процедуры выполнить левый циклический" << endl
				<< "сдвиг для двух данных наборов из трех чисел : (A1, B1, C1) и(A2, B2, C2).\n\n";

			int a = rand() % 50, b = rand() % 50, c = rand() % 50;
			cout << "значения будут сгенерированы рандомно:\n";
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl;
			cout << "\nпосле действия функции: \n";

			ShiftLeft3(&a, &b, &c);
			cout << "a = " << a << "; b = " << b << "; c = " << c << endl << endl;
		}break;

		case 3:
		{
			cout << "Описать функцию IsLeapYear(Y) логического типа, которая возвращает True," << endl
				<< "если год Y(целое положительное число) является високосным, и False" << endl
				<< "в противном случае.Вывести значение функции IsLeapYear для пяти данных " << endl
				<< "значений параметра Y.Високосным считается год, делящийся на 4, за" << endl
				<< "исключением тех годов, которые делятся на 100 и не делятся на 400.\n\n";
			int y;
			do
			{
				cout << "введите год для того, чтобы узнать является ли он високосным: ";
				cin >> y;
			} while (y < 1);


			IsLeapYear(y);
			if (IsLeapYear(y) == 1)
				cout << "true\n\n";
			else
				cout << "false\n\n";

		}break;

		case 4:
		{
			cout << "Используя функцию IsLeapYear из задания 3, описать функцию MonthDays(M, Y)" << endl
				<< "целого типа, которая возвращает количество дней для M - го месяца года Y" << endl
				<< "(1 ≤ M ≤ 12, Y > 0 — целые числа).Вывести значение функции MonthDays для" << endl
				<< "данного года Y и месяцев M1, M2, M3.\n\n";
			int month, year;
			do {
				cout << "Введите год: ";
				cin >> year;
			} while (year < 1);
			do {
				cout << "Введите номер месяца (1-12): ";
				cin >> month;
			} while ((month < 1) || (month>12));

			cout << "кол-во дней: " << MonthDays(month, year) << endl;
		}break;

		case 5:
		{
			cout << "Используя функцию MonthDays из задания 4, описать процедуру" << endl
				<< "PrevDate(D, M, Y), которая по информации о правильной дате, " << endl
				<< "включаю - щей день D, номер месяца M и год Y, определяет предыдущую " << endl
				<< "дату(пара - метры целого типа D, M, Y являются одновременно входными" << endl
				<< "и выходными).Применить процедуру PrevDate к трем исходным датам и " << endl
				<< "вывести полученные значения предыдущих дат\n\n";

			int month, year, day;
			do
			{
				cout << "Введите год: ";
				cin >> year;
			} while (year < 1);

			do 
			{
				cout << "Введите месяц: ";
				cin >> month;
			} while ((month < 1) || (month>12));
			
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 30));
			}
			
			if ((month == 2) && (IsLeapYear(year) == 1))
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 29));
			}
			else if ((month == 2) && (IsLeapYear(year) == 0))
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 28));
			}
			
			else 
			{
				do
				{
					cout << "Введите день: ";
					cin >> day;
				} while ((day < 1) || (day > 31));
			}
			PrevDate(year, month, day);

		}break;

		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "ошибка" << endl;
		}
		}
	} while (nz > 0);


}

void ShiftRight3(int*a, int *b, int *c)
{
	int z = *c;
	*c = *b;
	*b = *a;
	*a = z;
}

void ShiftLeft3(int*a, int *b, int *c)
{
	//значение A переходит в C, значение C — в B, значение B — в A
	int z = *a;
	*a = *b;
	*b = *c;
	*c = z;
}

int IsLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}

int MonthDays(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (IsLeapYear(year) == 1)
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

void PrevDate(int year, int month, int day)
{
	if (day == 1)
	{
		if (day == 1 && month == 1)
			year = year - 1;
		if (month == 1)
			month = 12;
		else
			month = month - 1;

		day = MonthDays(month, year);

	}
	else
		day = day - 1;

	cout << "дата предыдущего дня(ДД.ММ.ГГГГ): " <<day << "." <<month << "." <<year << endl;
}
