#include <iostream>
#include<string>

using namespace std;

int myChoose;

int vybor(){
    cout<<"Выберите действие :"<<endl
    <<"(1) Сменить преподавателя группы "<<endl
    <<"(2) Уволить преподавателя"<<endl
    <<"(3) Добавить нового преподавателя "<<endl
    <<"(0) Выйти из меню"<<endl
    <<"Ваш выбор: ";
    cin>> myChoose;
    return myChoose;
}
int main(){
    int groopa;
    string TekusPrepod, ZamenaPrepod, prepod,datus;
    vybor();
    while (myChoose!=0)
    {
        switch (myChoose)
        {
        case 1:
            cout<<"Введите номер группы: "; cin>>groopa;
            cout<<"Введите Фамилию текущего преподавателя группы: "; cin>>TekusPrepod;
            cout<<"Введите Фамилию нового преподавателя группы: "; cin>>ZamenaPrepod;
            cout<<"Для группы номер "<<groopa<<" текущий преподаватель "<<TekusPrepod<<" заменен на "<<ZamenaPrepod<<endl;
            vybor();
            break;
        case 2:
            cout<<"Введите Фамилию преподавателя на увольнение: "; cin>>prepod;
            cout<<"Введите дату увольнения "; cin>>datus;
            cout<<"Преподаватель "<< prepod<<" будет уволен. Дата увольнения: "<< datus<<endl;
            vybor();
        break;
        case 3:
            cout<<"Введите Фамилию преподавателя: "; cin>>prepod;
            cout<<endl<<"Преподаватель "<<prepod<<" внесён в базу данных"<<endl;
            vybor();
        break;

        default:
        cout<<"Пожалуйста корректно введите предложение "<<endl;
        vybor();
            break;
        }
    }
    
    return 0;
}
