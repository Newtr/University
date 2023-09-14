#include "arithmetics_middle.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int operations_middle(int balance)
{
    int number = 0;
    string numberInput = "";
    bool numberIsPositive = true;
    srand(time(0));
    cout << "\nВы выбрали средний уровень сложности.\n";
    cout << "Проверим, как вы умеете решать примеры!\n\n";
    cout << "Вам будет представлено 10 примеров на устный счет." << endl << "ЗАДАЧА: решить их!" << endl;
    // system("pause");
    // system("cls");
    int const size = 5, exercises = 10;
    int count = 1;
    int arr[size], right_answer, answer_from_user, quality_of_right_answers = 0;
    for (int n = 0; n < exercises; n++) {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 15 + 10;
        }

        right_answer = arr[0] + arr[3] * arr[2] - arr[1] * arr[4];


        cout << "Номер задания: " << count << endl << endl;
        count++;
        cout << arr[0] << "+" << arr[3] << "*" << arr[2] << "-" << arr[1] << "*" << arr[4] << "= ? " << endl;
        cout << "Введите ваш ответ: ";
        while (true)
        {
            getline(cin, numberInput);
            numberIsPositive = true;

            try
            {
                if (numberInput[0] == '-')
                {
                    numberIsPositive = false;
                    numberInput.erase(numberInput.begin());
                }


                for (char ch : numberInput)
                {
                    if (!isdigit(ch)) {
                        throw invalid_argument("");
                    }
                }

                number = stoi(numberInput);
                if (!numberIsPositive) {
                    number *= -1;
                }

                break;
            }
            catch (...) {
                cout << " Некорректный ввод, попробуйте еще раз: ";
            }
        }
        if (right_answer == number) {
            quality_of_right_answers++;
            cout << "Верно!\n";
        }
        else {
            cout << "Неверно!\n";
        }
        // system("pause");
        // system("cls");
    }
    cout << "Количество верно решенных примеров: " << quality_of_right_answers << endl;
    int salary;
    salary = quality_of_right_answers * 2;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    cout << "Вы заработали " << salary << " голды." << endl;
    cout << "У вас на счету " << balance + salary << " голды." << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    // system("pause");
    balance = balance + salary;
    return balance;
}


