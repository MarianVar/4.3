

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include <time.h>
#include <stdio.h>

using namespace std;

struct Student {
	string name, lastname;
	string inizials;
	int Note[5];
};

void AddTXT(char* fname);
void PrintTXT(char* fname);
void SearchTXTStudentWith(char* fname, const char* cheker, const int count);
int SearchAndRemoteTXTStudentWithTwo(char* fname, const char* cheker, const int count);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[100];

	int menuItem;
	do {
		cout << "Оберіть дію: " << endl;
		cout << "[1]  Cтворити файл." << endl;
		cout << "[2]  Додати елементи до списку." << endl;
		cout << "[3]  Переглянути список." << endl;
		cout << "[4]  Вивести список з хочаб одною трійкою." << endl;
		cout << "[5]  Вивести список з хочаб одною двійкою." << endl;
		cout << "[6]  Вивести список відміників." << endl;
		cout << "[7]  Вивести список з 2-ма або більше двійок." << endl;
		cout << "[8]  Видалити із списка студента з 2-ма або більше двійок." << endl;
		cout << "[9]  Відкрити файл." << endl;
		cout << "[0]  вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		switch (menuItem) {
		case 1:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			AddTXT(fname);
			break;
		case 2:
			AddTXT(fname);
			break;
		case 3:
			PrintTXT(fname);
			break;
		case 4:
			SearchTXTStudentWith(fname, "3", 1);
			break;
		case 5:
			SearchTXTStudentWith(fname, "2", 1);
			break;
		case 6:
			SearchTXTStudentWith(fname, "5", 5);
			break;
		case 7:
			SearchTXTStudentWith(fname, "2", 2);
			break;
		case 8:
			SearchAndRemoteTXTStudentWithTwo(fname, "2", 2);
			break;
		case 9:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;
}

void AddTXT(char* fname) {
	ofstream fout;
	fout.open(fname, ios::app);

	int k;
	cout << "Кількість елементів: "; cin >> k;
	Student* s = new Student[k];

	for (int i = 0; i < k; i++)
	{
		cin.get();
		cin.sync();

		cout << "Iм'я: "; getline(cin, s[i].name);
		fout << ' ' << s[i].name;

		cout << "Ініціали: "; getline(cin, s[i].inizials);
		fout << ' ' << s[i].inizials;

		for (int j = 0; j < 5; j++)
		{
			cout << "Оцінка з " << j + 1 << "предмету : ";
			cin >> s[i].Note[j];
			fout << ' ' << s[i].Note[j];
		}
		fout << endl;
	}
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	cout << endl;
}

void  SearchTXTStudentWith(char* fname, const char* cheker, const int count) {

	ifstream fin(fname);
	char s[400];
	char* w;
	cin.ignore();
	int counter;
	bool isUsed = false;

	while (fin.getline(s, sizeof(s))) {
		char tmp[400];
		strcpy(tmp, s);
		isUsed = false;
		w = strtok(tmp, " ");
		counter = 0;

		while (w != NULL)
		{
			if ((strcmp(w, cheker)) == 0)
			{
				counter++;
				if (counter >= count)
					if (!isUsed)
					{
						cout << "Дані про людину з " << cheker << " : " << s << endl;
						isUsed = true;
					}
			}
			w = strtok(NULL, " ");
		}
	}

}

int  SearchAndRemoteTXTStudentWithTwo(char* fname, const char* cheker, const int count) {
	ifstream fin(fname);
	ofstream t("TMP.TXT");
	char s[400];
	char* w;
	cin.ignore();
	int counter;
	bool isUsed, isUsed1;
	int rem = 0;

	while (fin.getline(s, sizeof(s))) {
		char tmp[400];
		strcpy(tmp, s);
		isUsed = false;
		isUsed1 = false;
		w = strtok(tmp, " ");
		counter = 0;

		while (w != NULL)
		{
			if ((strcmp(w, cheker)) == 0)
			{
				counter++;
				if (counter >= count)
					if (!isUsed)
					{
						cout << "Видалення : " << s << endl;
						isUsed = true;
						rem++;
					}
			}



			w = strtok(NULL, " ");
		}
		if ((!isUsed == true) && (!isUsed1 == true))
		{
			t << s << endl;
			isUsed1 = true;
		}
	}
	fin.close(); // для вилучення і перейменування
	t.close(); // файли мають бути закриті

	remove(fname); // знищуємо заданий файл
	rename("TMP.TXT", fname); // перейменовуємо тимчасовий файл
	return rem;

}