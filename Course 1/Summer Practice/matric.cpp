#include <ctime>
#include "matric.h"
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;

int mat33(int* mark, int number_of_exercise);
int mat22(int* mark, int number_of_exercise);

int matric1(int balance)
{
  srand(time(NULL));
  cout << "\nПроверим, как вы умеете считать определители матриц 2х2 и 3х3!\n\n";
  cout << "К вашему вниманию будет представленно 10 матриц." << endl << "ЗАДАЧА: найти их определители." << endl;
  // system("pause");
  // system("cls");


  int count = 0;
  int mark = 0;
  int number_of_exercise = 1;
  for (count; count < 5; count++)
  {

    cout << "Задание номер: " << number_of_exercise << "\n\n";
    mat33(&mark, number_of_exercise);
    number_of_exercise++;


    cout << "Задание номер: " << number_of_exercise << "\n\n";
    mat22(&mark, number_of_exercise);
    number_of_exercise++;
    /*count++;
    if (count == 5)
      break;*/

  }

  cout << "Ваша отметка: " << mark << endl;
  int salary;
  salary = mark * 1;
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
  cout << "Вы заработали " << salary << " голды." << endl;
  cout << "У вас на счету " << balance + salary << " голды." << endl;
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
  // system("pause");
  // system("cls");
  balance = balance + salary;
  return balance;
}

int mat33(int* mark, int number_of_exercise)
{

  int opredelitel;
  int a[3][3];
  int A;
  int B;
  int C;
  int answer;


  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      a[i][j] = rand() % 10;
      cout << a[i][j] << " ";

    }

    cout << endl;
  }

  A = (a[1][1] * a[2][2]) - (a[2][1] * a[1][2]);
  B = (a[1][0] * a[2][2]) - (a[2][0] * a[1][2]);
  C = (a[1][0] * a[2][1]) - (a[2][0] * a[1][1]);

  opredelitel = ((a[0][0] * A) - (a[0][1] * B) + (a[0][2] * C));


  string numberInput;
  bool numberIsPositive = true;

  while (true)
  {
    cout << "Введите ваш ответ: ";
    cin>>numberInput;
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

      answer = stoi(numberInput);
      if (!numberIsPositive) {
        answer *= -1;
      }

      break;
    }
    catch (...) {
      cout << "Некорректный ввод, попробуйте еще раз:\n";

    }
  }
  if (answer == opredelitel)
  {
    (*(mark))++;
  }
  // system("pause");
  // system("cls");
  return 0;


}

int mat22(int* mark, int number_of_exercise)
{
  int opredelitel2;
  int answer;
  int b[2][2];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      b[i][j] = rand() % 10;
      cout << b[i][j] << " ";
    }
    cout << endl;
  }

  opredelitel2 = (b[0][0] * b[1][1]) - (b[1][0] * b[0][1]);
  opredelitel2 = (b[0][0] * b[1][1]) - (b[1][0] * b[0][1]);


  string numberInput;
  bool numberIsPositive = true;

  while (true)
  {
    cout << "Введите ваш ответ: ";
    cin>>numberInput;
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

      answer = stoi(numberInput);
      if (!numberIsPositive) {
        answer *= -1;
      }

      break;
    }
    catch (...) {
      cout << "Некорректный ввод, попробуйте еще раз:\n";

    }
  }
  if (answer == opredelitel2)
  {
    (*(mark))++;
  }
  // system("pause");
  // system("cls");
  return 0;
}