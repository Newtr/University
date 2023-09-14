#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int vybor;
int Vyz(){
    cout<<"Выберите действие: (1) Выбрать куда полететь (2) Удаление информации по городу (3) Поиск данных (0) Выход ";
    cin>> vybor;
}

struct DateTime{
    unsigned short Day : 5;
    unsigned short Month : 4;
    unsigned short Year : 7;
};

DateTime d[3];

struct Information
{
    string numReis;
    string time;
    int price;
};

union PeopleSize{
    int kol;
} kolvo[3];

struct somo
{
    int newPrice;
} NovyPrice[3];
Information info[3];

enum Goroda {
    MINSK,
    BREST,
    GRODNO
};

Goroda gr;

class Gorod{
public:
Goroda GetState()
{
    return gg;
}
void Setstate(Goroda gg)
{
    this->gg=gg;
}
private:
Goroda gg;
};
Gorod dva;

void Zapolnenie(){
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            info[i].numReis="2F65";
            info[i].time="9 AM";
            info[i].price=15;
            kolvo[i].kol=150;
            d[i].Day=10;
            d[i].Month=10;
            d[i].Year=15;
        break;
        case 1:
            info[i].numReis="5T12";
            info[i].time="3 PM";
            info[i].price=30;
            kolvo[i].kol=80;
            d[i].Day=21;
            d[i].Month=11;
            d[i].Year=16;
        break;
        case 2:
            info[i].numReis="7Y98";
            info[i].time="11 PM";
            info[i].price=40;
            kolvo[i].kol=270;
            d[i].Day=31;
            d[i].Month=12;
            d[i].Year=17;
        break;
        }
    }
    
}

void Poisk(){
    int vyb;
    int rais;
    int mesta;
    int i=0;
    bool PP=false;
    cout<<"Что вы хотите узнать: "<<endl;
    cout<<"(1)Номера рейсов "<<endl;
    cout<<"(2)Время рейсов "<<endl;
    cout<<"(3)Цену рейсов "<<endl;
    cout<<"(4)Количество мест в самолете "<<endl;
    cout<<"(5)Даты рейсов "<<endl;
    cin>>vyb;
    switch (vyb)
    {
    case 1:
    cout<<"Номера рейсов:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case MINSK:
            cout<<"Минск: "<<info[i].numReis<<endl;
            break;
        case BREST:
            cout<<"Брест: "<<info[i].numReis<<endl;
            break;
        case GRODNO:
            cout<<"Гродно: "<<info[i].numReis<<endl;
            break;
        }
    }
    break;
    case 2:
    cout<<"Время рейсов:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case MINSK:
            cout<<"Минск: "<<info[i].time<<endl;
            break;
        case BREST:
            cout<<"Брест: "<<info[i].time<<endl;
            break;
        case GRODNO:
            cout<<"Гродно: "<<info[i].time<<endl;
            break;
        }
    }
    break;
    case 3:
    cout<<"Введите желательную сумму рейса: ";
    cin>>rais;
        while (i!=6)
        {
            if (rais+i==info[MINSK].price)
        {
            cout<<"Вашей цене удовлетворяет следующий город: "<<"Минск"<<endl;
            PP=true;
            break;
        }
            if (rais+i==info[BREST].price)
        {
            cout<<"Вашей цене удовлетворяет следующий город: "<<"Брест"<<endl;
            PP=true;
            break;
        }
            if (rais+i==info[GRODNO].price)
        {
            cout<<"Вашей цене удовлетворяет следующий город: "<<"Гродно"<<endl;
            PP=true;
            break;
        }
        i++;
        PP=true;
        }   
        if (PP==true)
        {
        i=-5;
        while (i!=1)
        {
            if (rais+i==info[MINSK].price)
        {
            cout<<"Вашей цене удовлетворяет следующий город: "<<"Минск"<<endl;
            break;
        }
            if (rais+i==info[BREST].price)
        {
            cout<<"Вашей цене удовлетворяет следующий город: "<<"Брест"<<endl;
            break;
        }
            if (rais+i==info[GRODNO].price)
        {
            cout<<"Вашей цене удовлетворяет следующий город: "<<"Гродно"<<endl;
            break;
        }
        i++;
        }
        }
    break;
    case 4:
    cout<<"Введите количество мест в самолете: ";
    cin>>mesta;
        while (i!=21)
        {
            if (mesta+i==kolvo[MINSK].kol)
        {
            cout<<"Примерно столько же человек в самолете на : "<<"Минск"<<endl;
            PP=true;
            break;
        }
        if (mesta+i==kolvo[BREST].kol)
        {
            cout<<"Примерно столько же человек в самолете на : "<<"Брест"<<endl;
            PP=true;
            break;
        }
        if (mesta+i==kolvo[GRODNO].kol)
        {
            cout<<"Примерно столько же человек в самолете на : "<<"Гродно"<<endl;
            PP=true;
            break;
        }
        i++;
        PP=true;
        }   
        if (PP==true)
        i=-20;
        {
        while (i!=1)
        {
            if (mesta+i==kolvo[MINSK].kol)
        {
            cout<<"Примерно столько же человек в самолете на: "<<"Минск"<<endl;
            break;
        }
            if (mesta+i==kolvo[BREST].kol)
        {
            cout<<"Примерно столько же человек в самолете на: "<<"Брест"<<endl;
            break;
        }
            if (mesta+i==kolvo[GRODNO].kol)
        {
            cout<<"Примерно столько же человек в самолете на: "<<"Гродно"<<endl;
            break;
        }
        i++;
        }
        }
    break;
    case 5:
    cout<<"Даты рейсов:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case MINSK:
            cout<<"Минск: "<<d[i].Day<<"."<<d[i].Month<<"."<<"20"<<d[i].Year<<endl;
            break;
        case BREST:
            cout<<"Брест: "<<d[i].Day<<"."<<d[i].Month<<"."<<"20"<<d[i].Year<<endl;
            break;
        case GRODNO:
            cout<<"Гродно: "<<d[i].Day<<"."<<d[i].Month<<"."<<"20"<<d[i].Year<<endl;
            break;
        }
    }
    break;
    }
}

void udal(){
    int vyb;
    cout<<"Что вы хотите удалить: "<<endl;
    cout<<"(1)Номера рейсов "<<endl;
    cout<<"(2)Время рейсов "<<endl;
    cout<<"(3)Цены рейсов "<<endl;
    cout<<"(4)Количество мест в самолете "<<endl;
    cout<<"(5)Даты рейсов "<<endl;
    cin>>vyb;
    switch (vyb)
    {
    case 1:
    cout<<"Номера рейсов были обнуленны:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        info[i].numReis=' ';
        cout<<info[i].numReis<<endl;
    }
    break;
    case 2:
    cout<<"Время рейсов были обнуленны:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        info[i].time=' ';
        cout<<info[i].time<<endl;
    }
    break;
    case 3:
    cout<<"Цены рейсов были обнуленны:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        info[i].price=' ';
        cout<<info[i].price<<endl;
    }
    break;
    case 4:
    cout<<"Места в самолете были обнуленны:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        kolvo[i].kol=0;
    }
    break;
    case 5:
    cout<<"Даты рейсов были обнуленны:"<<endl;
    for (int i = 0; i < 3; i++)
    {
        d[i].Day=0;
        d[i].Month=0;
        d[i].Year=0;
        cout<<d[i].Day<<"."<<d[i].Month<<"."<<"00"<<d[i].Year<<endl;
    }
    break;
    }
}
int main() {
    int BB;
    char vb;
    Zapolnenie();
/*     for (int i = 0; i < 3; i++)
    {
        cout<<"№"<<i+1<<endl;
        cout<<"Номер рейса = "<<info[i].numReis<<endl;
        cout<<"Время рейса = "<<info[i].time<<endl;
        cout<<"Цена рейса = "<<info[i].price<<endl;
        cout<<"Количество мест = "<<info[i].kolvo<<endl;
        cout<<"Дата рейса = "<<d[i].Day<<"."<<d[i].Month<<"."<<"20"<<d[i].Year<<endl;
    } */
    
    Vyz();
    while(vybor!=0){
    switch (vybor)
    {
    case 1:
        /* dva.Setstate(Goroda::MINSK) */
        cout<<"В какой город вы хотите полететь? (0)Минкс (1)Брест (2)Гродно "; cin>>BB;
        switch (BB)
        {
        case Goroda::MINSK:
        cout<<"Город = Минск"<<endl;
        cout<<"Номер рейса = "<<info[MINSK].numReis<<endl;
        cout<<"Время рейса = "<<info[MINSK].time<<endl;
        cout<<"Цена рейса = "<<info[MINSK].price<<"$"<<endl;
        cout<<"Количество мест = "<<kolvo[MINSK].kol<<endl;
        cout<<"Дата рейса = "<<d[MINSK].Day<<"."<<d[MINSK].Month<<"."<<"20"<<d[MINSK].Year<<endl;
        break;
        case Goroda::BREST:
        cout<<"Город = Брест"<<endl;
        cout<<"Номер рейса = "<<info[BREST].numReis<<endl;
        cout<<"Время рейса = "<<info[BREST].time<<endl;
        cout<<"Цена рейса = "<<info[BREST].price<<"$"<<endl;
        cout<<"Количество мест = "<< kolvo[BREST].kol<<endl;
        cout<<"Дата рейса = "<<d[BREST].Day<<"."<<d[BREST].Month<<"."<<"20"<<d[BREST].Year<<endl;
        break;
        case Goroda::GRODNO:
        cout<<"Город = Гродно"<<endl;
        cout<<"Номер рейса = "<<info[GRODNO].numReis<<endl;
        cout<<"Время рейса = "<<info[GRODNO].time<<endl;
        cout<<"Цена рейса = "<<info[GRODNO].price<<"$"<<endl;
        cout<<"Количество мест = "<< kolvo[GRODNO].kol<<endl;
        cout<<"Дата рейса = "<<d[GRODNO].Day<<"."<<d[GRODNO].Month<<"."<<"20"<<d[GRODNO].Year<<endl;
        break;
        }
        Vyz();
    break;
    case 2:
        udal();
        Vyz();
    break;
    case 3:
        Poisk();
        Vyz();
    break;
    default:
    cout<<"!!!!!!";
        break;
    }
    }
    return 0;
}