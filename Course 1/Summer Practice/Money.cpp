#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include <fstream>
#include "matric.cpp"
#include "arithmetics_easy.cpp"
#include "arithmetics_middle.cpp"
#include "arithmetics_hard.cpp"
#include "darts.cpp"
#include "kazino.cpp"
using namespace std;

int balance;
bool first_time_now = false, first_time = false;

int GetBalance(){
    ifstream Ifile;
    ofstream Ofile;
    Ofile.open("UU_Inventory.txt");
    Ifile.open("Inventory.txt");
    string info="m", dop_info;
    int pos, history_pos;
    for (int i = 0; !Ifile.eof() && info != "" ; i++)
    {
        if (first_time == false)
        {
            getline(Ifile,info);
            pos = info.find(":")+1;
            info = info.substr(pos);
            balance = stoi(info);
            Ofile<<"Gold:"+to_string(balance)<<endl;
            getline(Ifile,info);
            Ofile<<info<<endl;
            getline(Ifile,info);
            Ofile<<info<<endl;
            getline(Ifile,info);
            Ofile<<info<<endl;
            getline(Ifile,info);
            Ofile<<info<<endl;
            getline(Ifile,info);
            Ofile<<info<<endl;
            first_time = true;
            Ofile.close();
            Ifile.close();
            remove("Inventory.txt");
            rename("UU_Inventory.txt","Inventory.txt");
            break;
        }
        switch (i)
        {
        case 1:
            getline(Ifile,info);
            Ofile<<"Gold:"+to_string(balance)<<endl;
            first_time_now = true;
        break;
        case 2:
            getline(Ifile,info);
            Ofile<<info<<endl;
            break;
            case 3:
            getline(Ifile,info);
            Ofile<<info<<endl;
            break;
            case 4:
            getline(Ifile,info);
            Ofile<<info<<endl;
            break;
            case 5:
            getline(Ifile,info);
            Ofile<<info<<endl;
            break;
            case 6:
            getline(Ifile,info);
            Ofile<<info<<endl;
            break;
            case 7:
            info = "";
            break;
            }
    }
    
    if (first_time_now==true)
    {
        Ofile.close();
        Ifile.close();
        remove("Inventory.txt");
        rename("UU_Inventory.txt","Inventory.txt");
    }
    
    return balance;
}


int main()
{
    srand(time(NULL));
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    bool inputIsOK = true;
    string choiceInput = "";

    int choice = 0;


    do
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        cout << "На вашем счету " << GetBalance() << " голды." << endl;
        cout<<"BALANC = "<<balance<<endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "Выберите, как хотите заработать деньги:" << endl
            << "1 - Матрицы(Математика)" << endl
            << "2 - Устный счет(Математика)" << endl
            << "3 - Дартс" << endl
            << "4 - Казино" << endl
            << "5 - Выход из программы" << endl
            << "Вы выбрали операцию под номером: ";

        do
        {
            cin>>choiceInput;
            inputIsOK = true;

            try
            {
                if (choiceInput.length() != 1) {
                    throw out_of_range("");
                }

                choice = stoi(choiceInput);
                if ((choice < 1) || (choice > 5)) {
                    throw out_of_range("");
                }
            }
            catch (...)
            {
                inputIsOK = false;
                cout << "Некорректный вариант, введите еще раз: ";
            }
        } while (!inputIsOK);

        switch (choice)
        {
        case 1:
        {
            balance = matric1(balance);
            // system("cls");
            continue;
        }
        case 2:
        {
            do
            {
                // system("cls");
                cout << "Выберите уровень сложности:\n 1 - легкий\n 2 - средний\n 3 - сложный\n 4 - выход в главное меню\n"
                    "Вы выбрали операцию под номером: ";


                do
                {

                    cin>>choiceInput;
                    inputIsOK = true;
                    try
                    {
                        if (choiceInput.length() != 1)
                        {
                            throw out_of_range("");
                        }

                        choice = stoi(choiceInput);
                        if ((choice < 1) || (choice > 4))
                        {
                            throw out_of_range("");
                        }
                    }
                    catch (...)
                    {
                        inputIsOK = false;
                        cout << "Некорректный вариант, введите еще раз: ";
                    }
                } while (!inputIsOK);


                switch (choice) {
                case 1:
                {
                    balance = operations(balance);
                    // system("cls");
                    continue;
                }
                case 2:
                {
                    balance = operations_middle(balance);
                    // system("cls");
                    continue;
                }
                case 3:
                {
                    balance = operations_hard(balance);
                    // system("cls");
                    continue;
                }

                case 4:
                {
                    // system("cls");
                    break;
                }

                }
            } while (choice != 4);
            continue;
        }
        case 3:
        {
            balance = darts(balance);
            // system("cls");
            continue;
        }
        case 4:
        {
            if (balance > 0)
            {
            balance = kazino(balance);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                cout << "На вашем счёте недостаточно средств." << endl;
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                // system("pause");
                // system("cls");
            }
            continue;
        }
        case 5:
        {
            break;
        }
        cout << endl << endl;
        default:
        {
            cout << "Некорректный вариант, введите еще раз: ";
        }
        }
    } while (choice != 5);

    return 0;
}