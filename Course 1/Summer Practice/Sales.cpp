#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
//#include <windows.h>

using namespace std;

struct Shopkeeper{
    string name;
    string secondname;
    int SaleTime;
    string specialization;
    string product1, product2, product3;
    float price1, price2, price3;

    float Buy_Sell();
};

Shopkeeper* Keeper1 = new Shopkeeper;
Shopkeeper* Keeper2 = new Shopkeeper;
Shopkeeper* Keeper3 = new Shopkeeper;
Shopkeeper* Keeper4 = new Shopkeeper;
Shopkeeper* Keeper5 = new Shopkeeper;

void Get_Hours(int Hours){
//    SYSTEMTIME st;
//    while(true){
//    GetLocalTime(&st);
//        Hours = st.wHour;
//       Sleep(1000);
//        system("cls");
//    }
}

void SHKeeper1(int Hours, float balance, float price, float CreditHystory, int ProductCount){

    if(Keeper1->specialization == "BerryPicker" && Hours >=0 && Hours <=6){
        cout<<"Зимой ягоды дороже, будь аккуратнее! Цена выросла на 30%!"<<endl;
        price *= 1.3;
    }
    float credit = CreditHystory * 0.1;
    if(ProductCount < 100){
        price *= 0.95;
    }
    if(Keeper1->SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Cлушай, нормальный ты мужичок, запишу тебя в свою книжку, но только карандашом."<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.01 и составляет: "<<CreditHystory<<endl;
    
}

void SHKeeper2(int Hours, float balance, float price, float CreditHystory, int ProductCount){

    if(Keeper2->specialization == "Fisher" && Hours >=7 && Hours <=12){
        cout<<"Весной рыба дороже! Цена выросла на 25%!"<<endl;
        price *= 1.25;
    }
    if(ProductCount < 100){
        price *= 0.9;
    }
    float credit = CreditHystory * 0.1;
    if(Keeper2->SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Cлушай, нормальный ты мужичок, запишу тебя в свою книжку, но только карандашом."<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.02 и составляет: "<<CreditHystory<<endl;
}

void SHKeeper3(int Hours, float balance, float price, float CreditHystory, int ProductCount){

    if(Keeper3->specialization == "Builder" && Hours >=13 && Hours <=18){
        cout<<"Летом на стройматериалы высокий спрос! Цена выросла на 40%!"<<endl;
        price *= 1.4;
    }
    if(ProductCount < 100){
        price *= 1.2;
    }
    float credit = CreditHystory * 0.1;
    if(Keeper3->SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Я вижу, строитель ты, хе-хе. Уважаю таких ребят!"<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.05 и составляет: "<<CreditHystory<<endl;
}

void SHKeeper4(int Hours, float balance, float price, float CreditHystory, int ProductCount){

    if(Keeper4->specialization == "Butcher" && Hours >=19 && Hours <=24){
        cout<<"Осенью на мясо цена выше! Цена выросла на 15%!"<<endl;
        price *= 1.15;
    }
    if(ProductCount < 100){
        price *= 0.95;
    }
    float credit = CreditHystory * 0.1;
    if(Keeper4->SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Все люди хороши, лишь бы не вегетерианцы!"<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.01 и составляет:"<<CreditHystory<<endl;
}

void SHKeeper5(int Hours, float balance, float price, float CreditHystory, int ProductCount){  

    if(Keeper5->specialization == "FruitSeller" && Hours >=7 && Hours <=12){
        cout<<"Зимой фрукты в дефиците! Цена выросла на 75%!"<<endl;
        price *= 1.75;
    }
    if(ProductCount < 100){
        price *= 1.35;
    }
    float credit = CreditHystory * 0.1;
    if(Keeper5->SaleTime == Hours){
        cout<<"Вы пришли в удачный момент, сейчас действует скидка 20%!";
        price *= (0.8-credit);
    }
    balance -= price;
    cout<<"Cлушай, нормальный ты мужичок, запишу тебя в свою книжку, но только карандашом."<<endl;
    CreditHystory += 1;
    cout<<"Ваш рейтинг у данного продавца повышен на 0.01 и составляет:"<<CreditHystory<<endl;
}

int main(){
    // Передаваемые переменные из внешнего файлы
    int Hours = 0;
    float balance = 50;
    float price = 13.4;
    float CreditHystory = 0.000;
    int ProductCount = 57; //max 100
    string specialization = "BeryyPicker";
    
    Get_Hours(Hours);
    
    SHKeeper1(Hours, balance, price, CreditHystory, ProductCount);
    
    return 0;
}