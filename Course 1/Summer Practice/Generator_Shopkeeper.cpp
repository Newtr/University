#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int choice;

struct Shopkeeper {
    string name;
    string secondname;
    int SaleTime;
    string specialization;
    string product1, product2, product3;
    int countP1, countP2, countP3;
    float price1, price2, price3;
    void Buy_Sell();
};

void goods_menu()
{
    cout << "Что-то еще?" << endl
        << "(0) - да ничего, посмотреть зашёл" << endl
        << "(1) - ягоды" << endl
        << "(2) - рыба" << endl
        << "(3) - стройматериалы" << endl
        << "(4) - мясо" << endl
        << "(5) - фрукты" << endl;
    cin >> choice;
}

void goods_menu_of_first_shopkeeper(Shopkeeper first_shopkeeper)
{
    cout << "Вот, что у меня есть - выбирай!" << endl << endl;
    cout << "[1] " << first_shopkeeper.product1
        << "\tКоличество: " << first_shopkeeper.countP1
        << "\tЦена: " << first_shopkeeper.price1 << endl;

    cout << "[2] " << first_shopkeeper.product2
        << "\tКоличество: " << first_shopkeeper.countP2
        << "\tЦена: " << first_shopkeeper.price2 << endl;

    cout << "[3] " << first_shopkeeper.product3
        << "\tКоличество: " << first_shopkeeper.countP3
        << "\tЦена: " << first_shopkeeper.price3 << endl << endl;
}

void goods_menu_of_second_shopkeeper(Shopkeeper second_shopkeeper)
{
    cout << "Вот, что у меня есть - выбирай!" << endl << endl;
    cout << "[1] " << second_shopkeeper.product1
        << "\tКоличество: " << second_shopkeeper.countP1
        << "\tЦена: " << second_shopkeeper.price1 << endl;

    cout << "[2] " << second_shopkeeper.product2
        << "\tКоличество: " << second_shopkeeper.countP2
        << "\tЦена: " << second_shopkeeper.price2 << endl;

    cout << "[3] " << second_shopkeeper.product3
        << "\tКоличество: " << second_shopkeeper.countP3
        << "\tЦена: " << second_shopkeeper.price3 << endl << endl;
}

void goods_menu_of_third_shopkeeper(Shopkeeper third_shopkeeper)
{
    cout << "Вот, что у меня есть - выбирай!" << endl << endl;
    cout << "[1] " << third_shopkeeper.product1
        << "\tКоличество: " << third_shopkeeper.countP1
        << "\tЦена: " << third_shopkeeper.price1 << endl;

    cout << "[2] " << third_shopkeeper.product2
        << "\tКоличество: " << third_shopkeeper.countP2
        << "\tЦена: " << third_shopkeeper.price2 << endl;

    cout << "[3] " << third_shopkeeper.product3
        << "\tКоличество: " << third_shopkeeper.countP3
        << "\tЦена: " << third_shopkeeper.price3 << endl << endl;
}

void goods_menu_of_fourth_shopkeeper(Shopkeeper fourth_shopkeeper)
{
    cout << "Вот, что у меня есть - выбирай!" << endl << endl;
    cout << "[1] " << fourth_shopkeeper.product1
        << "\tКоличество: " << fourth_shopkeeper.countP1
        << "\tЦена: " << fourth_shopkeeper.price1 << endl;

    cout << "[2] " << fourth_shopkeeper.product2
        << "\tКоличество: " << fourth_shopkeeper.countP2
        << "\tЦена: " << fourth_shopkeeper.price2 << endl;

    cout << "[3] " << fourth_shopkeeper.product3
        << "\tКоличество: " << fourth_shopkeeper.countP3
        << "\tЦена: " << fourth_shopkeeper.price3 << endl << endl;
}

void goods_menu_of_fifth_shopkeeper(Shopkeeper fifth_shopkeeper)
{
    cout << "Вот, что у меня есть - выбирай!" << endl << endl;
    cout << "[1] " << fifth_shopkeeper.product1
        << "\tКоличество: " << fifth_shopkeeper.countP1
        << "\tЦена: " << fifth_shopkeeper.price1 << endl;

    cout << "[2] " << fifth_shopkeeper.product2
        << "\tКоличество: " << fifth_shopkeeper.countP2
        << "\tЦена: " << fifth_shopkeeper.price2 << endl;

    cout << "[3] " << fifth_shopkeeper.product3
        << "\tКоличество: " << fifth_shopkeeper.countP3
        << "\tЦена: " << fifth_shopkeeper.price3 << endl << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    Shopkeeper first_shopkeeper, second_shopkeeper, third_shopkeeper, fourth_shopkeeper, fifth_shopkeeper;
    first_shopkeeper.name = "Nikita";
    first_shopkeeper.secondname = "Ilyin";
    first_shopkeeper.SaleTime = 16;
    first_shopkeeper.specialization = "Berry-picker";
    first_shopkeeper.product1 = "product1.1";
    first_shopkeeper.product2 = "product1.2";
    first_shopkeeper.product3 = "product1.3";
    first_shopkeeper.countP1 = 1;
    first_shopkeeper.countP2 = 2;
    first_shopkeeper.countP3 = 3;
    first_shopkeeper.price1 = 1.1;
    first_shopkeeper.price2 = 1.2;
    first_shopkeeper.price3 = 1.3;



    second_shopkeeper.name = "Roman";
    second_shopkeeper.secondname = "Tyshkevich"; 
    second_shopkeeper.SaleTime = 10;
    second_shopkeeper.specialization = "Fisherman"; 
    second_shopkeeper.product1 = "product2.1";
    second_shopkeeper.product2 = "product2.2";
    second_shopkeeper.product3 = "product2.3";
    second_shopkeeper.countP1 = 1;
    second_shopkeeper.countP2 = 2;
    second_shopkeeper.countP3 = 3;
    second_shopkeeper.price1 = 2.1; 
    second_shopkeeper.price2 = 2.2;
    second_shopkeeper.price3 = 2.3;



    third_shopkeeper.name = "Dmitry"; 
    third_shopkeeper.secondname = "Barabanov";
    third_shopkeeper.SaleTime = 12; 
    third_shopkeeper.specialization = "Builder"; 
    third_shopkeeper.product1 = "product3.1";
    third_shopkeeper.product2 = "product3.2"; 
    third_shopkeeper.product3 = "product3.3";
    third_shopkeeper.countP1 = 1;
    third_shopkeeper.countP2 = 2;
    third_shopkeeper.countP3 = 3;
    third_shopkeeper.price1 = 3.1;
    third_shopkeeper.price2 = 3.2; 
    third_shopkeeper.price3 = 3.3;





    fourth_shopkeeper.name = "Elizabeth"; 
    fourth_shopkeeper.secondname = "Volynec"; 
    fourth_shopkeeper.SaleTime = 18;
    fourth_shopkeeper.specialization = "Butcher";
    fourth_shopkeeper.product1 = "product4.1"; 
    fourth_shopkeeper.product2 = "product4.2";
    fourth_shopkeeper.product3 = "product4.3";
    fourth_shopkeeper.countP1 = 1;
    fourth_shopkeeper.countP2 = 2;
    fourth_shopkeeper.countP3 = 3;
    fourth_shopkeeper.price1 = 4.1; 
    fourth_shopkeeper.price2 = 4.2;
    fourth_shopkeeper.price3 = 4.3;






    fifth_shopkeeper.name = "Egorik"; 
    fifth_shopkeeper.secondname = "Martini"; 
    fifth_shopkeeper.SaleTime = 9;
    fifth_shopkeeper.specialization = "Fruit seller"; 
    fifth_shopkeeper.product1 = "product5.1";
    fifth_shopkeeper.product2 = "product5.2";
    fifth_shopkeeper.product3 = "product5.3";
    fifth_shopkeeper.countP1 = 1;
    fifth_shopkeeper.countP2 = 2;
    fifth_shopkeeper.countP3 = 3;
    fifth_shopkeeper.price1 = 5.1; 
    fifth_shopkeeper.price2 = 5.2; 
    fifth_shopkeeper.price3 = 5.3;




    cout << "\t\t\t\t\t\tДобро пожаловать на рынок Долбогномов!" << endl;
    cout << "\t\t\tУ нас самые честные продавцы с самыми свежими и качественными товарами. Отвечаю." << endl << endl;
    cout << "Вот они, сверху вниз:" << endl << endl;
    cout << "Никита Ильин - продавец всевозможных видов ягод. Малины немерено." << endl;
    cout << "Роман Тышкевич - настоящий профессионал рыболовства, имеет в своём прилавке абсолютно всё, что когда-либо плавало." << endl;
    cout << "Дмитрий Барабанов - продавец стройматериалов, закупившись у него можно с легкостью построить дворец Put In a" << endl;
    cout << "Лизочка Волынец - настоящий белорусский мясник. Хотите попробовать что-то экзотическое? - Вам к ней." << endl;
    cout << "Егорик Мартини - лучший в сфере фруктов, самые вкусные, самые сочные, самые красивые фрукты только у него." << endl << endl;
    goods_menu();
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
        {
            goods_menu_of_first_shopkeeper(first_shopkeeper);

            int first_choice;
            cin >> first_choice;
            while (first_choice != 0)
            {
                switch (first_choice)
                {
                case 1:
                {
                    cout << "У меня в наличии " << first_shopkeeper.countP1 << " " << first_shopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > first_shopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        first_choice = 1;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        first_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    cout << "У меня в наличии " << first_shopkeeper.countP2 << " " << first_shopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > first_shopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        first_choice = 2;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        first_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    cout << "У меня в наличии " << first_shopkeeper.countP3 << " " << first_shopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > first_shopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        first_choice = 3;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        first_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_first_shopkeeper(first_shopkeeper);
                    cin >> first_choice;
                    break;
                }
            }
            break;
        }
        case 2:
        {
            goods_menu_of_second_shopkeeper(second_shopkeeper);

            int second_choice;
            cin >> second_choice;
            while (second_choice != 0)
            {
                switch (second_choice)
                {
                case 1:
                {
                    cout << "У меня в наличии " << second_shopkeeper.countP1 << " " << second_shopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > second_shopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        second_choice = 1;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        second_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    cout << "У меня в наличии " << second_shopkeeper.countP2 << " " << second_shopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > second_shopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        second_choice = 2;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        second_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    cout << "У меня в наличии " << second_shopkeeper.countP3 << " " << second_shopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > second_shopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        second_choice = 3;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        second_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_second_shopkeeper(second_shopkeeper);
                    cin >> second_choice;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            goods_menu_of_third_shopkeeper(third_shopkeeper);

            int third_choice;
            cin >> third_choice;
            while (third_choice != 0)
            {
                switch (third_choice)
                {
                case 1:
                {
                    cout << "У меня в наличии " << third_shopkeeper.countP1 << " " << third_shopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > third_shopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        third_choice = 1;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        third_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    cout << "У меня в наличии " << third_shopkeeper.countP2 << " " << third_shopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > third_shopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        third_choice = 2;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        third_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    cout << "У меня в наличии " << third_shopkeeper.countP3 << " " << third_shopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > third_shopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        third_choice = 3;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        third_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_first_shopkeeper(first_shopkeeper);
                    cin >> third_choice;
                    break;
                }
            }
            break;
        }
        case 4:
        {
            goods_menu_of_fourth_shopkeeper(fourth_shopkeeper);

            int fourth_choice;
            cin >> fourth_choice;
            while (fourth_choice != 0)
            {
                switch (fourth_choice)
                {
                case 1:
                {
                    cout << "У меня в наличии " << fourth_shopkeeper.countP1 << " " << fourth_shopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > fourth_shopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fourth_choice = 1;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        fourth_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    cout << "У меня в наличии " << fourth_shopkeeper.countP2 << " " << fourth_shopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > fourth_shopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fourth_choice = 2;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        fourth_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    cout << "У меня в наличии " << fourth_shopkeeper.countP3 << " " << fourth_shopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > fourth_shopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fourth_choice = 3;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        fourth_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_fourth_shopkeeper(fourth_shopkeeper);
                    cin >> fourth_choice;
                    break;
                }
            }
            break;
        }
        case 5:
        {
            goods_menu_of_fifth_shopkeeper(fifth_shopkeeper);

            int fifth_choice;
            cin >> fifth_choice;
            while (fifth_choice != 0)
            {
                switch (fifth_choice)
                {
                case 1:
                {
                    cout << "У меня в наличии " << fifth_shopkeeper.countP1 << " " << fifth_shopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > fifth_shopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fifth_choice = 1;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        fifth_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    cout << "У меня в наличии " << fifth_shopkeeper.countP2 << " " << fifth_shopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > fifth_shopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fifth_choice = 2;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        fifth_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    cout << "У меня в наличии " << fifth_shopkeeper.countP3 << " " << fifth_shopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > fifth_shopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fifth_choice = 3;
                    }
                    else
                    {
                        //first_shopkeeper.Buy_Sell();
                        goods_menu();
                        fifth_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_fifth_shopkeeper(fifth_shopkeeper);
                    cin >> fifth_choice;
                    break;
                }
            }
            break;
        }
        default:
        {
            cout << "Некорректный вариант. Подумай еще." << endl;
            goods_menu();
            break;
        }
        }
    }
}