#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
struct Teachers {
    string FIO;
    int age;
    unsigned long int zip;
    float salary;
};
Teachers *MyTeacher = new Teachers[2];

int UserChoose, JoCHoose;

int vybor(){
    cout<<"Выберите действие :"<<endl
    <<"(1) Частичное удаление "<<endl
    <<"(2) Полное удаление"<<endl
    <<"(0) Выйти из меню"<<endl
    <<"Ваш выбор: ";
    cin>> JoCHoose;
    return JoCHoose;
}

void FillStruct(){
    ofstream File;
    File.open("D:\\Data Base\\Lr6\\MyFile.txt");
    int n = sizeof(MyTeacher);
    for (int i = 0; i < n; i++)
    {
        switch (i)
        {
        case 0:
            MyTeacher[i].FIO = "Vladimir Anatoliev Karpov";
            MyTeacher[i].age = 35;
            MyTeacher[i].zip = 756983;
            MyTeacher[i].salary = 37.87;
            File<<"Name: "<<MyTeacher[i].FIO<<endl;
            File<<"Age: "<<MyTeacher[i].age<<endl;
            File<<"Zip: "<<MyTeacher[i].zip<<endl;
            File<<"Salary: "<<MyTeacher[i].salary<<endl<<endl;
            break;
        case 1:
            MyTeacher[i].FIO = "Nikita Gleshko Sergeev";
            MyTeacher[i].age = 43;
            MyTeacher[i].zip = 761290;
            MyTeacher[i].salary = 47.12;
            File<<"Name: "<<MyTeacher[i].FIO<<endl;
            File<<"Age: "<<MyTeacher[i].age<<endl;
            File<<"Zip: "<<MyTeacher[i].zip<<endl;
            File<<"Salary: "<<MyTeacher[i].salary<<endl;
            break;
        }
    }
    File.close();
}

void ReadFromFile(){
    string info;
    ifstream File;
    int n=0;
    File.open("D:\\Data Base\\Lr6\\MyFile.txt");
    while (!File.eof())
    {
        getline(File,info);
        if (info[0]=='N')
        {
            info.erase(0,6);
            MyTeacher[n].FIO=info;
        }
        else if(info[0]=='A')
        {
            info.erase(0,5);
            MyTeacher[n].age=stoi(info);
        }
        else if (info[0]=='Z')
        {
            info.erase(0,5);
            MyTeacher[n].salary=stoi(info);
        }
        else if(info[0]=='S')
        {
            info.erase(0,8);
            MyTeacher[n].salary=stof(info);
        }
        else if(info=="")
        {
            n++;
        }
    }
    File.close();
}

void DeletePart(int a, bool b=false, bool c=true){  //Vladimir = true Nikita = false
    ReadFromFile();
    ofstream File;
    File.open("D:\\Data Base\\Lr6\\MyFile.txt");
    if (b == true){
    switch (a)
    {
    case 1:
    for (int i = 0; i < 2; i++)
    {
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl<<endl;
    }
        break;
    case 2:
    for (int i = 0; i < 2; i++)
    {
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl<<endl;
    }
        break;
    case 3:
    for (int i = 0; i < 2; i++)
    {
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl<<endl;
    }
        break;
    case 4:
    for (int i = 0; i < 2; i++)
    {
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl<<endl;
    }
        break;
    }
    }
    else {
    int Y;
    if (c == true)
    Y=0;
    else
    Y=1;
    switch (a)
    {
    case 1:
    for (int i = 0; i < 2; i++)
    {
        if(i==Y){
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
        else{
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
    }
        break;
    case 2:
    for (int i = 0; i < 2; i++)
    {
        if(i==Y){
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
        else{
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
    }
        break;
    case 3:
    for (int i = 0; i < 2; i++)
    {
        if(i==Y){
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
        else{
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
    }
        break;
    case 4:
    for (int i = 0; i < 2; i++)
    {
        if(i==Y){
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        }
        else{
        File<<"Name: "<<MyTeacher[i].FIO<<endl;
        File<<"Age: "<<MyTeacher[i].age<<endl;
        File<<"Zip: "<<MyTeacher[i].zip<<endl;
        File<<"Salary: "<<MyTeacher[i].salary<<endl;
        }
    }
        break;
    }
    }
    File.close();
}

void DeleteAll(bool who){   //Vladimir = true Nikita = false
    ReadFromFile();
    ofstream File;
    File.open("D:\\Data Base\\Lr6\\MyFile.txt");
    if (who==true){
        File<<"Name: "<<MyTeacher[1].FIO<<endl;
        File<<"Age: "<<MyTeacher[1].age<<endl;
        File<<"Zip: "<<MyTeacher[1].zip<<endl;
        File<<"Salary: "<<MyTeacher[1].salary<<endl;
    }
    else{
        File<<"Name: "<<MyTeacher[0].FIO<<endl;
        File<<"Age: "<<MyTeacher[0].age<<endl;
        File<<"Zip: "<<MyTeacher[0].zip<<endl;
        File<<"Salary: "<<MyTeacher[0].salary<<endl;
    }
    File.close();
}

int main(){
    bool everyone;
    bool VladOrNik;
    bool NowVladOrNik;
    int YY,BB;
    int Nowchoose;
    FillStruct();
    cout<<"File was created successfully!"<<endl;
    ReadFromFile();
    vybor();
    while (JoCHoose!=0)
    {
        switch (JoCHoose)
        {
        case 1:
        cout<<"Вы хотите удалить что-то одно у всех или у конкретного пользователя?"<<endl;
        cout<<"Для всех - 1"<<"\t"<<"Для конкретного пользователя - 2"<<endl;
        cin>>YY;
        if(YY==1){
        everyone=true;
        cout<<"Что именно вы хотите удалить: (1)Имя\t(2)Возраст\t(3)Индекс\t(4)Зарплату: ";
        cin>>UserChoose;
        }
        else{
        everyone=false;
        cout<<"Для кого вы хотите удалить: (1)Владимир или (2)Никита: ";
        cin>>BB;
        if(BB==1)
        VladOrNik=true;
        else if(BB==2)
        VladOrNik=false;
        cout<<"Что именно вы хотите удалить: (1)Имя\t(2)Возраст\t(3)Индекс\t(4)Зарплату: ";
        cin>>UserChoose;
        }
        DeletePart(UserChoose, everyone, VladOrNik);
        vybor();
        break;
        case 2:
        cout<<"Вы хотите удалить всю информацию по: (1)Владимир (2)Никита: ";
        cin>>YY;
        if(YY==1)
        NowVladOrNik=true;
        else if(YY==2)
        NowVladOrNik=false;
        DeleteAll(NowVladOrNik);
        vybor();
        break;
        }
    }
/*  cout<<"Вы хотите удалить что-то одно у всех или у конкретного пользователя?"<<endl;
    cout<<"Для всех - 1"<<"\t"<<"Для конкретного пользователя - 2"<<endl;
    cin>>YY;
    if(YY==1){
    everyone=true;
    cout<<"Что именно вы хотите удалить: (1)Имя\t(2)Возраст\t(3)Индекс\t(4)Зарплату: ";
    cin>>UserChoose;
    }
    else{
    everyone=false;
    cout<<"Для кого вы хотите удалить: (1)Владимир или (2)Никита: ";
    cin>>BB;
    if(BB==1)
    VladOrNik=true;
    else if(BB==2)
    VladOrNik=false;
    cout<<"Что именно вы хотите удалить: (1)Имя\t(2)Возраст\t(3)Индекс\t(4)Зарплату: ";
    cin>>UserChoose;
    }
    DeletePart(UserChoose, everyone, VladOrNik);
    cout<<"Вы хотите удалить всю информацию по: (1)Владимир (2)Никита: ";
    cin>>YY;
    if(YY==1)
    NowVladOrNik=true;
    else if(YY==2)
    NowVladOrNik=false;
    DeleteAll(NowVladOrNik); */
    return 0;
}