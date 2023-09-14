#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

struct Shopkeeper{
    string name;
    string secondname;
    int SaleTime;
    string specialization;
    string product1, product2, product3;    //Product Name
    int countP1, countP2, countP3;          // Count of Product
    float price1, price2, price3;           // Price of Product

    void Buy_Sell(int kol, Shopkeeper *Keper, int which_one_keeper, int which_one_pr);
}FirstShopkeeper, SecondShopkeeper, ThirdShopkeeper, FourthShopkeeper, FifthShopkeeper;

int choice;

void FindFullInfo(Shopkeeper *exmpl, string TextFile){
    string newinfo;
    int pos1, pos2;
    pos1 = TextFile.find("Name:");              //Find name of Shopkeeper +
    pos1 = pos1 + 5;
    pos2 = TextFile.find(",SecondName");
    pos2 = pos2 - pos1;                          
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->name = newinfo;

    pos1 = TextFile.find(",SecondName:");          //Find SecondName of Shopkeeper +
    pos1 = pos1 + 12;
    pos2 = TextFile.find(",Saletime:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->secondname = newinfo;

    pos1 = TextFile.find(",Saletime:");          //Find Saletime of Shopkeeper +
    pos1 = pos1 + 10;
    pos2 = TextFile.find(",Speacialization:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->SaleTime = stoi(newinfo);

    pos1 = TextFile.find(",Speacialization:");          //Find specizlization of Shopkeeper +
    pos1 = pos1 + 17;
    pos2 = TextFile.find(",NProduct1:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->specialization = newinfo;

    pos1 = TextFile.find(",NProduct1:");          //Find 1 NProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",NProduct2:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->product1 = newinfo;

    pos1 = TextFile.find(",NProduct2:");          //Find 2 NProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",NProduct3:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->product2 = newinfo;

    pos1 = TextFile.find(",NProduct3:");          //Find 3 NProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",CProduct1:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->product3 = newinfo;

    pos1 = TextFile.find(",CProduct1:");        //Find 1 CProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",CProduct2:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->countP1 = stoi(newinfo);

    pos1 = TextFile.find(",CProduct2:");        //Find 2 CProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",CProduct3:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->countP2 = stoi(newinfo);

    pos1 = TextFile.find(",CProduct3:");        //Find 3 CProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",PProduct1:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->countP3 = stoi(newinfo);

    pos1 = TextFile.find(",PProduct1:");        //Find 1 PProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",PProduct2:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->price1 = stof(newinfo);

    pos1 = TextFile.find(",PProduct2:");        //Find 2 PProduct of Shopkeeper +
    pos1 = pos1 + 11;
    pos2 = TextFile.find(",PProduct3:");
    pos2 = pos2 - pos1;
    newinfo = TextFile.substr(pos1,pos2);
    exmpl->price2 = stof(newinfo);

    pos1 = TextFile.find(",PProduct3:");        //Find 3 PProduct of Shopkeeper +
    pos1 = pos1 + 11;
    newinfo = TextFile.substr(pos1);
    exmpl->price3 = stof(newinfo);
}

void FillInfo(){
    ifstream IFile;
    IFile.open("Shopkeeper_Info.txt");
    string infoFile;
    for (int i = 0; i < 5; i++)
    {
        getline(IFile,infoFile);
        switch (i)
        {
        case 0:
        FindFullInfo(&FirstShopkeeper,infoFile);
/*         cout<<"Имя: "<<FirstShopkeeper.name<<endl;
        cout<<"Фамилия: "<<FirstShopkeeper.secondname<<endl;
        cout<<"Время скидки: "<<FirstShopkeeper.SaleTime<<endl;
        cout<<"Специализация: "<<FirstShopkeeper.specialization<<endl;
        cout<<"Продукт 1: "<<FirstShopkeeper.product1<<endl;
        cout<<"Продукт 2: "<<FirstShopkeeper.product2<<endl;
        cout<<"Продукт 3: "<<FirstShopkeeper.product3<<endl;
        cout<<"Количество 1 продукта: "<<FirstShopkeeper.countP1<<endl;
        cout<<"Количество 2 продукта: "<<FirstShopkeeper.countP2<<endl;
        cout<<"Количество 3 продукта: "<<FirstShopkeeper.countP3<<endl;
        cout<<"Цена 1 продукта: "<<FirstShopkeeper.price1<<endl;
        cout<<"Цена 2 продукта: "<<FirstShopkeeper.price2<<endl;
        cout<<"Цена 3 продукта: "<<FirstShopkeeper.price3<<endl; */
        break;

        case 1:
        FindFullInfo(&SecondShopkeeper,infoFile);
/*         cout<<"Имя: "<<SecondShopkeeper.name<<endl;
        cout<<"Фамилия: "<<SecondShopkeeper.secondname<<endl;
        cout<<"Время скидки: "<<SecondShopkeeper.SaleTime<<endl;
        cout<<"Специализация: "<<SecondShopkeeper.specialization<<endl;
        cout<<"Продукт 1: "<<SecondShopkeeper.product1<<endl;
        cout<<"Продукт 2: "<<SecondShopkeeper.product2<<endl;
        cout<<"Продукт 3: "<<SecondShopkeeper.product3<<endl;
        cout<<"Количество 1 продукта: "<<SecondShopkeeper.countP1<<endl;
        cout<<"Количество 2 продукта: "<<SecondShopkeeper.countP2<<endl;
        cout<<"Количество 3 продукта: "<<SecondShopkeeper.countP3<<endl;
        cout<<"Цена 1 продукта: "<<SecondShopkeeper.price1<<endl;
        cout<<"Цена 2 продукта: "<<SecondShopkeeper.price2<<endl;
        cout<<"Цена 3 продукта: "<<SecondShopkeeper.price3<<endl; */
        break;

        case 2:
        FindFullInfo(&ThirdShopkeeper,infoFile);
/*         cout<<"Имя: "<<ThirdShopkeeper.name<<endl;
        cout<<"Фамилия: "<<ThirdShopkeeper.secondname<<endl;
        cout<<"Время скидки: "<<ThirdShopkeeper.SaleTime<<endl;
        cout<<"Специализация: "<<ThirdShopkeeper.specialization<<endl;
        cout<<"Продукт 1: "<<ThirdShopkeeper.product1<<endl;
        cout<<"Продукт 2: "<<ThirdShopkeeper.product2<<endl;
        cout<<"Продукт 3: "<<ThirdShopkeeper.product3<<endl;
        cout<<"Количество 1 продукта: "<<ThirdShopkeeper.countP1<<endl;
        cout<<"Количество 2 продукта: "<<ThirdShopkeeper.countP2<<endl;
        cout<<"Количество 3 продукта: "<<ThirdShopkeeper.countP3<<endl;
        cout<<"Цена 1 продукта: "<<ThirdShopkeeper.price1<<endl;
        cout<<"Цена 2 продукта: "<<ThirdShopkeeper.price2<<endl;
        cout<<"Цена 3 продукта: "<<ThirdShopkeeper.price3<<endl; */
        break;

        case 3:
        FindFullInfo(&FourthShopkeeper,infoFile);
/*         cout<<"Имя: "<<FourthShopkeeper.name<<endl;
        cout<<"Фамилия: "<<FourthShopkeeper.secondname<<endl;
        cout<<"Время скидки: "<<FourthShopkeeper.SaleTime<<endl;
        cout<<"Специализация: "<<FourthShopkeeper.specialization<<endl;
        cout<<"Продукт 1: "<<FourthShopkeeper.product1<<endl;
        cout<<"Продукт 2: "<<FourthShopkeeper.product2<<endl;
        cout<<"Продукт 3: "<<FourthShopkeeper.product3<<endl;
        cout<<"Количество 1 продукта: "<<FourthShopkeeper.countP1<<endl;
        cout<<"Количество 2 продукта: "<<FourthShopkeeper.countP2<<endl;
        cout<<"Количество 3 продукта: "<<FourthShopkeeper.countP3<<endl;
        cout<<"Цена 1 продукта: "<<FourthShopkeeper.price1<<endl;
        cout<<"Цена 2 продукта: "<<FourthShopkeeper.price2<<endl;
        cout<<"Цена 3 продукта: "<<FourthShopkeeper.price3<<endl; */
        break;

        case 4:
        FindFullInfo(&FifthShopkeeper,infoFile);
/*         cout<<"Имя: "<<FifthShopkeeper.name<<endl;
        cout<<"Фамилия: "<<FifthShopkeeper.secondname<<endl;
        cout<<"Время скидки: "<<FifthShopkeeper.SaleTime<<endl;
        cout<<"Специализация: "<<FifthShopkeeper.specialization<<endl;
        cout<<"Продукт 1: "<<FifthShopkeeper.product1<<endl;
        cout<<"Продукт 2: "<<FifthShopkeeper.product2<<endl;
        cout<<"Продукт 3: "<<FifthShopkeeper.product3<<endl;
        cout<<"Количество 1 продукта: "<<FifthShopkeeper.countP1<<endl;
        cout<<"Количество 2 продукта: "<<FifthShopkeeper.countP2<<endl;
        cout<<"Количество 3 продукта: "<<FifthShopkeeper.countP3<<endl;
        cout<<"Цена 1 продукта: "<<FifthShopkeeper.price1<<endl;
        cout<<"Цена 2 продукта: "<<FifthShopkeeper.price2<<endl;
        cout<<"Цена 3 продукта: "<<FifthShopkeeper.price3<<endl; */
        break;
        }
    }
    IFile.close();
}

void Credit_Info(int crd_info, int which_one_keeper, int final_gold){
    ofstream OO;
    ifstream II;
    II.open("Inventory.txt");
    OO.open("User_Inventory.txt");
    string credit_info="m", gold_info, credit_dop_info;
    int your_gold, gold_pos, total_price_int, credit_history_pos,j, credit_history;
    float total_price_float;
    for (int i = 1; !II.eof() && credit_info != ""; i++)
    {
        switch (i)
        {
        case 1:
            getline(II,credit_info);
            OO<<"Gold:"+to_string(final_gold)<<endl;
        break;
        case 2:
            getline(II,credit_info);
            credit_dop_info = credit_info;
            credit_history_pos = credit_info.find(":")+1;
            credit_info = credit_info.substr(credit_history_pos);
            if (which_one_keeper == i-1)
            {
                credit_history = stoi(credit_info);
                if (credit_history<5)
                {
                    credit_history++;
                    OO<<"Credit_History_First_Shopkeeper:" + to_string(credit_history)<<endl;
                }
                else
                {
                    OO<<"Credit_History_First_Shopkeeper:" + to_string(credit_history)<<endl;
                }
            }
            else
            {
                OO<<credit_dop_info<<endl;
            }
            break;
            case 3:
            getline(II,credit_info);
            credit_dop_info = credit_info;
            credit_history_pos = credit_info.find(":")+1;
            credit_info = credit_info.substr(credit_history_pos);
            if (which_one_keeper == i-1)
            {
                credit_history = stoi(credit_info);
                if (credit_history<=5)
                {
                    credit_history ++;
                    OO<<"Credit_History_Second_Shopkeeper:" + to_string(credit_history)<<endl;
                }
                else
                {
                    OO<<"Credit_History_Second_Shopkeeper:" + to_string(credit_history)<<endl;
                }
            }
            else
            {
                OO<<credit_dop_info<<endl;
            }
            break;
            case 4:
            getline(II,credit_info);
            credit_dop_info = credit_info;
            credit_history_pos = credit_info.find(":")+1;
            credit_info = credit_info.substr(credit_history_pos);
            if (which_one_keeper == i-1)
            {
                credit_history = stoi(credit_info);
                if (credit_history<5)
                {
                    credit_history ++;
                    OO<<"Credit_History_Third_Shopkeeper:" + to_string(credit_history)<<endl;
                }
                else
                {
                    OO<<"Credit_History_Third_Shopkeeper:" + to_string(credit_history)<<endl;
                }
            }
            else
            {
                OO<<credit_dop_info<<endl;
            }
            break;
            case 5:
            getline(II,credit_info);
            credit_dop_info = credit_info;
            credit_history_pos = credit_info.find(":")+1;
            credit_info = credit_info.substr(credit_history_pos);
            if (which_one_keeper == i-1)
            {
                credit_history = stoi(credit_info);
                if (credit_history<5)
                {
                    credit_history ++;
                    OO<<"Credit_History_Fourth_Shopkeeper:" + to_string(credit_history)<<endl;
                }
                else
                {
                    OO<<"Credit_History_Fourth_Shopkeeper:" + to_string(credit_history)<<endl;
                }
            }
            else
            {
                OO<<credit_dop_info<<endl;
            }
            break;
            case 6:
            getline(II,credit_info);
            credit_dop_info = credit_info;
            credit_history_pos = credit_info.find(":")+1;
            credit_info = credit_info.substr(credit_history_pos);
            if (which_one_keeper == i-1)
            {
                credit_history = stoi(credit_info);
                if (credit_history<5)
                {
                    credit_history ++;
                    OO<<"Credit_History_Fifth_Shopkeeper:" + to_string(credit_history)<<endl;
                }
                else
                {
                    OO<<"Credit_History_Fifth_Shopkeeper:" + to_string(credit_history)<<endl;
                }
            }
            else
            {
                OO<<credit_dop_info<<endl;
            }
            break;
            case 7:
            credit_info = "";
            break;
            }
    }
    II.close();
    OO.close();
    remove("Inventory.txt");
    rename("User_Inventory.txt","Inventory.txt");
}

void Shopkeeper::Buy_Sell(int kolvo, Shopkeeper *Keeper, int whichKeeper, int whichProduct){
    FillInfo();
    string info="m", name, secondname, saletime, specialization, product1, product2, product3, countP1, countP2, countP3, price1, price2, price3, maska;
    ofstream Ofile1, Ofile3;
    ifstream Ifile1;
    Ifile1.open("Inventory.txt");
    int your_gold, gold_pos, total_price_int, credit_history_pos, credit_history;
    float total_price_float;
    string gold_info, credit_history_info;
    getline(Ifile1,gold_info);
    gold_pos = gold_info.find(":") + 1;
    gold_info = gold_info.substr(gold_pos);
    your_gold = stoi(gold_info);
    Ifile1.close();
    switch (whichProduct)
    {
    case 1:
        Keeper->countP1 = Keeper->countP1 - kolvo;
        total_price_float = Keeper->price1 * kolvo;
        total_price_int = (int)total_price_float;
        your_gold = your_gold - total_price_int;
        Credit_Info(credit_history,whichKeeper,your_gold);
        break;
    case 2:
        Keeper->countP2 = Keeper->countP2 - kolvo;
        total_price_float = Keeper->price2 * kolvo;
        total_price_int = (int)total_price_float;
        your_gold = your_gold - total_price_int;
        Credit_Info(credit_history,whichKeeper,your_gold);
        break;
    case 3:
        Keeper->countP3 = Keeper->countP3 - kolvo;
        total_price_float = Keeper->price2 * kolvo;
        total_price_int = (int)total_price_float;
        your_gold = your_gold - total_price_int;
        Credit_Info(credit_history,whichKeeper,your_gold);
        break;
    }
    name = Keeper->name;
    secondname = Keeper->secondname;
    saletime = to_string(Keeper->SaleTime);
    specialization = Keeper->specialization;
    product1 = Keeper->product1;
    product2 = Keeper->product2;
    product3 = Keeper->product3;
    countP1 = to_string(Keeper->countP1);
    countP2 = to_string(Keeper->countP2);
    countP3 = to_string(Keeper->countP3);
    price1 = to_string(Keeper->price1);
    price2 = to_string(Keeper->price2);
    price3 = to_string(Keeper->price3);
    maska = "Name:"+name+",SecondName:"+secondname+",Saletime:"+saletime+",Speacialization:"+specialization+",NProduct1:"+product1+",NProduct2:"+product2+",NProduct3:"+product3+",CProduct1:"+countP1+",CProduct2:"+countP2+",CProduct3:"+countP3+",PProduct1:"+price1+",PProduct2:"+price2+",PProduct3:"+price3+"";
    ofstream Ofile2;
    ifstream Ifile;
    int count = 1;
    Ifile.open("Shopkeeper_Info.txt");
    Ofile2.open("Shopkeepers.txt");

    while (!Ifile.eof() && info!="")
    {
        getline(Ifile,info);
        if(count == whichKeeper){
            Ofile2<<maska<<endl;
            count++;
        }
        else if(count != whichKeeper){
            count++;
            Ofile2<<info<<endl;
        }
    }
    
    Ofile2.close();
    Ifile.close();
    remove("Shopkeeper_Info.txt");
    rename("Shopkeepers.txt","Shopkeeper_Info.txt");
}

// функции Никиты

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

// Функции Димы

// void Get_Hours(int Hours){
//     SYSTEMTIME st;
//     GetLocalTime(&st);
//         Hours = st.wHour;
//         Sleep(1000);
//         system("cls");
// }

void SHKeeper1(int Hours, float balance, float price, float CreditHystory, int ProductCount){   //ягоды

    if(FirstShopkeeper.specialization == "BerryPicker" && Hours >=0 && Hours <=6){
        cout<<"Зимой ягоды дороже, будь аккуратнее! Цена выросла на 30%!"<<endl;
        price *= 1.3;
    }
    float credit = CreditHystory * 0.1;
    if(ProductCount < 100){
        price *= 0.95;
    }
    if(FirstShopkeeper.SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Cлушай, нормальный ты мужичок, запишу тебя в свою книжку, но только карандашом."<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.01 и составляет: "<<CreditHystory<<endl;
    
}

void SHKeeper2(int Hours, float balance, float price, float CreditHystory, int ProductCount){   //рыба

    if(SecondShopkeeper.specialization == "Fisher" && Hours >=7 && Hours <=12){
        cout<<"Весной рыба дороже! Цена выросла на 25%!"<<endl;
        price *= 1.25;
    }
    if(ProductCount < 100){
        price *= 0.9;
    }
    float credit = CreditHystory * 0.1;
    if(SecondShopkeeper.SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Cлушай, нормальный ты мужичок, запишу тебя в свою книжку, но только карандашом."<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.02 и составляет: "<<CreditHystory<<endl;
}

void SHKeeper3(int Hours, float balance, float price, float CreditHystory, int ProductCount){   //стройматериалы

    if(ThirdShopkeeper.specialization == "Builder" && Hours >=13 && Hours <=18){
        cout<<"Летом на стройматериалы высокий спрос! Цена выросла на 40%!"<<endl;
        price *= 1.4;
    }
    if(ProductCount < 100){
        price *= 1.2;
    }
    float credit = CreditHystory * 0.1;
    if(ThirdShopkeeper.SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Я вижу, строитель ты, хе-хе. Уважаю таких ребят!"<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.05 и составляет: "<<CreditHystory<<endl;
}

void SHKeeper4(int Hours, float balance, float price, float CreditHystory, int ProductCount){   //мясо

    if(FourthShopkeeper.specialization == "Butcher" && Hours >=19 && Hours <=24){
        cout<<"Осенью на мясо цена выше! Цена выросла на 15%!"<<endl;
        price *= 1.15;
    }
    if(ProductCount < 100){
        price *= 0.95;
    }
    float credit = CreditHystory * 0.1;
    if(FourthShopkeeper.SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Все люди хороши, лишь бы не вегетерианцы!"<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.01 и составляет:"<<CreditHystory<<endl;
}

void SHKeeper5(int Hours, float balance, float price, float CreditHystory, int ProductCount){   //фрукты

    if(FifthShopkeeper.specialization == "FruitSeller" && Hours >=7 && Hours <=12){
        cout<<"Зимой фрукты в дефиците! Цена выросла на 75%!"<<endl;
        price *= 1.75;
    }
    if(ProductCount < 100){
        price *= 1.35;
    }
    float credit = CreditHystory * 0.1;
    if(FifthShopkeeper.SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Cлушай, нормальный ты мужичок, запишу тебя в свою книжку, но только карандашом."<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.01 и составляет:"<<CreditHystory<<endl;
}

int main(){
    FillInfo();

    int which_one_product, which_one_shopkeeper, hours;

    // Get_Hours(hours);

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
            goods_menu_of_first_shopkeeper(FirstShopkeeper);

            int first_choice;
            cin >> first_choice;
            while (first_choice != 0)
            {
                switch (first_choice)
                {
                case 1:
                {
                    which_one_product = 1;
                    which_one_shopkeeper = 1;
                    cout << "У меня в наличии " << FirstShopkeeper.countP1 << " " << FirstShopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FirstShopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        first_choice = 1;
                    }
                    else
                    {
                        // SHKeeper1(hours,)
                        FirstShopkeeper.Buy_Sell(how_many,&FirstShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        first_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    which_one_product = 2;
                    which_one_shopkeeper = 1;
                    cout << "У меня в наличии " << FirstShopkeeper.countP2 << " " << FirstShopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FirstShopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        first_choice = 2;
                    }
                    else
                    {
                        FirstShopkeeper.Buy_Sell(how_many,&FirstShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        first_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    which_one_product = 3;
                    which_one_shopkeeper = 1;
                    cout << "У меня в наличии " << FirstShopkeeper.countP3 << " " << FirstShopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FirstShopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        first_choice = 3;
                    }
                    else
                    {
                        FirstShopkeeper.Buy_Sell(how_many,&FirstShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        first_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_first_shopkeeper(FirstShopkeeper);
                    cin >> first_choice;
                    break;
                }
            }
            break;
        }
        case 2:
        {
            goods_menu_of_second_shopkeeper(SecondShopkeeper);

            int second_choice;
            cin >> second_choice;
            while (second_choice != 0)
            {
                switch (second_choice)
                {
                case 1:
                {
                    which_one_product = 1;
                    which_one_shopkeeper = 2;
                    cout << "У меня в наличии " << SecondShopkeeper.countP1 << " " << SecondShopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > SecondShopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        second_choice = 1;
                    }
                    else
                    {
                        SecondShopkeeper.Buy_Sell(how_many,&SecondShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        second_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    which_one_product = 2;
                    which_one_shopkeeper = 2;
                    cout << "У меня в наличии " << SecondShopkeeper.countP2 << " " << SecondShopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > SecondShopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        second_choice = 2;
                    }
                    else
                    {
                        SecondShopkeeper.Buy_Sell(how_many,&SecondShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        second_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    which_one_product = 3;
                    which_one_shopkeeper = 2;
                    cout << "У меня в наличии " << SecondShopkeeper.countP3 << " " << SecondShopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > SecondShopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        second_choice = 3;
                    }
                    else
                    {
                        SecondShopkeeper.Buy_Sell(how_many,&SecondShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        second_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_second_shopkeeper(SecondShopkeeper);
                    cin >> second_choice;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            goods_menu_of_third_shopkeeper(ThirdShopkeeper);

            int third_choice;
            cin >> third_choice;
            while (third_choice != 0)
            {
                switch (third_choice)
                {
                case 1:
                {
                    which_one_product = 1;
                    which_one_shopkeeper = 3;
                    cout << "У меня в наличии " << ThirdShopkeeper.countP1 << " " << ThirdShopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > ThirdShopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        third_choice = 1;
                    }
                    else
                    {
                        ThirdShopkeeper.Buy_Sell(how_many,&ThirdShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        third_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    which_one_product = 2;
                    which_one_shopkeeper = 3;
                    cout << "У меня в наличии " << ThirdShopkeeper.countP2 << " " << ThirdShopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > ThirdShopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        third_choice = 2;
                    }
                    else
                    {
                        ThirdShopkeeper.Buy_Sell(how_many,&ThirdShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        third_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    which_one_product = 3;
                    which_one_shopkeeper = 3;
                    cout << "У меня в наличии " << ThirdShopkeeper.countP3 << " " << ThirdShopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > ThirdShopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        third_choice = 3;
                    }
                    else
                    {
                        ThirdShopkeeper.Buy_Sell(how_many,&ThirdShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        third_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_third_shopkeeper(ThirdShopkeeper);
                    cin >> third_choice;
                    break;
                }
            }
            break;
        }
        case 4:
        {
            goods_menu_of_fourth_shopkeeper(FourthShopkeeper);

            int fourth_choice;
            cin >> fourth_choice;
            while (fourth_choice != 0)
            {
                switch (fourth_choice)
                {
                case 1:
                {
                    which_one_product = 1;
                    which_one_shopkeeper = 4;
                    cout << "У меня в наличии " << FourthShopkeeper.countP1 << " " << FourthShopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FourthShopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fourth_choice = 1;
                    }
                    else
                    {
                        FourthShopkeeper.Buy_Sell(how_many,&FourthShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        fourth_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    which_one_product = 2;
                    which_one_shopkeeper = 4;
                    cout << "У меня в наличии " << FourthShopkeeper.countP2 << " " << FourthShopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FourthShopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fourth_choice = 2;
                    }
                    else
                    {
                        FourthShopkeeper.Buy_Sell(how_many,&FourthShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        fourth_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    which_one_product = 3;
                    which_one_shopkeeper = 4;
                    cout << "У меня в наличии " << FourthShopkeeper.countP3 << " " << FourthShopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FourthShopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fourth_choice = 3;
                    }
                    else
                    {
                        FourthShopkeeper.Buy_Sell(how_many,&FourthShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        fourth_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_fourth_shopkeeper(FourthShopkeeper);
                    cin >> fourth_choice;
                    break;
                }
            }
            break;
        }
        case 5:
        {
            goods_menu_of_fifth_shopkeeper(FifthShopkeeper);

            int fifth_choice;
            cin >> fifth_choice;
            while (fifth_choice != 0)
            {
                switch (fifth_choice)
                {
                case 1:
                {
                    which_one_product = 1;
                    which_one_shopkeeper = 5;
                    cout << "У меня в наличии " << FifthShopkeeper.countP1 << " " << FifthShopkeeper.product1 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FifthShopkeeper.countP1) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fifth_choice = 1;
                    }
                    else
                    {
                        FifthShopkeeper.Buy_Sell(how_many,&FifthShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        fifth_choice = 0;
                    }
                    break;
                }
                case 2:
                {
                    which_one_product = 2;
                    which_one_shopkeeper = 5;
                    cout << "У меня в наличии " << FifthShopkeeper.countP2 << " " << FifthShopkeeper.product2 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FifthShopkeeper.countP2) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fifth_choice = 2;
                    }
                    else
                    {
                        FifthShopkeeper.Buy_Sell(how_many,&FifthShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        fifth_choice = 0;
                    }
                    break;
                }
                case 3:
                {
                    which_one_product = 3;
                    which_one_shopkeeper = 5;
                    cout << "У меня в наличии " << FifthShopkeeper.countP3 << " " << FifthShopkeeper.product3 << endl;
                    cout << "Сколько тебе нужно? "; int how_many; cin >> how_many;
                    if (how_many < 0 || how_many > FifthShopkeeper.countP3) {
                        cout << "Охох, странный ты какой-то." << endl;
                        fifth_choice = 3;
                    }
                    else
                    {
                        FifthShopkeeper.Buy_Sell(how_many,&FifthShopkeeper,which_one_shopkeeper,which_one_product);
                        goods_menu();
                        fifth_choice = 0;
                    }
                    break;
                }
                default:
                    cout << "Некорректный вариант. Подумай еще." << endl;
                    goods_menu_of_fifth_shopkeeper(FifthShopkeeper);
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