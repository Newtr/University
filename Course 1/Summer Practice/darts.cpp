#include "darts.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int darts(int balance)
{
cout << endl << "Ваша задача состоит в том, чтобы вовремя нажать на нужную клавишу." << endl;
    // system("pause");
    // system("cls");
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int random = rand() % 25;
    char ch = alphabet[random];
    string press;
    cout << "Нажмите на букву " << ch << endl;
    clock_t start = clock();
    cout << "Введённая буква: "; cin >> press; cout << endl;
    clock_t end = clock();
    int ms = end - start;
    if (press.length() == 1)
    {
    if (press[0] == ch)
    {
        if (ms < 1500)
        {
            cout << "Вы успели вовремя нажать на нужную букву!" << endl;
            HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "Вы заработали 1 голды." << endl;
            balance++;
            cout << "Ваш баланс теперь составляет " << balance << " голды." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            return balance;
        }
        else
        {
            cout << "Вы не успели вовремя нажать на нужную букву!" << endl;
            // system("pause");
            // system("cls");
            return balance;
        }
    }
    else
    {
        cout << "Вы нажали не на ту букву!" << endl;
        // system("pause");
        // system("cls");
        return balance;
    }
    }
    else
    {
        cout << "Неверно!" << endl;
        // system("pause");
        // system("cls");
        return balance;
    }
}