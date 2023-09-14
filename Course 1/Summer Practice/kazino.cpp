#include "kazino.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

int kazino(int balance)
{
srand(time(NULL));
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << endl << "Ваша задача состоит в том, чтобы выбрать на что поставить - на красное, черное или зелёное." << endl;
    cout << "При совпадении черного или красного вам будет начислено 2 голды. При совпадении зелёного, ваш баланс удваивается." << endl;
    cout << "За каждую ставку снимается 1 голда." << endl;
    // system("pause");
    // system("cls");
    cout << "На что ставить будем?" << endl << "1 - красное, 2 - чёрное, 3 - зелёное" << endl;
    int what; cin >> what;
    switch (what)
    {
    case 1:
    {
        int a = rand() % 101;
        if (a < 40)
        {
            cout << "Поздравляем! Выпало красное!" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "На ваш счёт было зачислено 2 голды" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            return balance + 2;
        }
        else
        {
            cout << "К сожалению, вам не повезло." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "С вашего счёта была снята 1 голда." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            balance--;
            return balance;
        }
        break;
    }
    case 2:
    {
        int b = rand() % 101;
        if (b >= 60 && b <= 100)
        {
            cout << "Поздравляем! Выпало чёрное!" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "На ваш счёт было зачислено 2 голды" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            return balance + 2;
        }
        else
        {
            cout << "К сожалению, вам не повезло." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "С вашего счёта была снята 1 голда." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            balance--;
            return balance;
        }
        break;
    }
    case 3:
    {
        int c = rand() % 101;
        int rand1 = rand() % 101, rand2 = rand() % 101, rand3 = rand() % 101, rand4 = rand() % 101, rand5 = rand() % 101;
        if (rand1 == c || rand2 == c || rand3 == c || rand4 == c || rand5 == c)
        {
            cout << "Поздравляем! Выпало зелёное!" << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "Ваш баланс был удвоен." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            return balance*2;
        }
        else
        {
            cout << "К сожалению, вам не повезло." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            cout << "С вашего счёта была снята 1 голда." << endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            // system("pause");
            // system("cls");
            balance--;
            return balance;
        }
        break;
    }
    default:
        cout << "Такого нет." << endl;
        // system("pause");
        // system("cls");
        return balance;
        break;
    }
}