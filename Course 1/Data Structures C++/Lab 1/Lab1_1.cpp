#include <iostream>
using namespace std;

    enum Drinks{
        COLA,
        SPRITE,
        FANTA,
        PEPSI,
    };

void chooseDrink(Drinks drink){
    if (drink == COLA)
    cout<<"Вы выбрали Колу";
    else if (drink == SPRITE)
    cout<<"Вы выбрали Cпрайт";
    else if (drink == FANTA)
    cout<<"Вы выбрали Фанту";
    else if (drink == PEPSI)
    cout<<"Вы выбрали Пепси";
    else
    cout<<"Вы ничего не выбрали";
}

int main(){
    chooseDrink(PEPSI);
    return 0;
}