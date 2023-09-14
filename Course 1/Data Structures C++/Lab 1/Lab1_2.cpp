#include <iostream>
using namespace std;

enum class Fruits{
    APPLE,
    BANANA,
    KIWI,
};
enum class Vegetables{
    CARROT,
    TOMATOS,
    CUCUMBER,
};

int main(){
    int vyborFruit, vyborVegetable;
    Fruits fr;
    Vegetables vg;
    cout<<"Выберите фрукт: "<<endl<<"Яблоко - 1 "<<endl<<"Банан - 2 "<<endl<<"Киви - 3 "<<endl; cin>>vyborFruit;
    cout<<"*************************************************"<<endl;
    cout<<"Выберите Овощ: "<<endl<<"Морковь - 1 "<<endl<<"Помидор - 2 "<<endl<<"Огурец - 3 "<<endl; cin>>vyborVegetable;
    cout<<"*************************************************"<<endl;
    cout<<"В итоге вы выбрали: "<<endl;
    switch (vyborFruit)
    {
    case 1:
        fr = Fruits::APPLE;
        cout<<"Яблоко"<<endl;
        break;
    case 2:
        fr = Fruits::BANANA;
        cout<<"Банан"<<endl;
        break;
    case 3:
        fr = Fruits::KIWI;
        cout<<"Киви"<<endl;
        break;
    default:
    cout<<"ВЫ НЕ ВЫБРАЛИ НИ ОДИН ИЗ ФРУКТОВ!!!!!";
        break;
    }
    switch (vyborVegetable)
    {
    case 1:
        vg = Vegetables::CARROT;
        cout<<"Морковь"<<endl;
        break;
    case 2:
        vg = Vegetables::TOMATOS;
        cout<<"Помидор"<<endl;
        break;
    case 3:
        vg = Vegetables::CUCUMBER;
        cout<<"Огурец"<<endl;
        break;
    default:
    cout<<"ВЫ НЕ ВЫБРАЛИ НИ ОДИН ИЗ ОВОЩЕЙ!!!!!";
        break;
    }
    return 0;
}