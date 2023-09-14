#include <iostream>
#include <string>
#include <fstream>
using namespace std;

float sredBall(float pred1, float pred2, float pred3){
    float sredBall;
    sredBall = (pred1+pred2+pred3)/3;
    return sredBall;
}

int vybor;

int Vyz(){
    cout<<"Выберите действие: (1) Ввод данных (2) Вывод данных (3) Поиск данных (4) Запись в файл (5) Чтение с данных (6) Удаление (0) Выход ";
    cin>> vybor;
}

struct Students
{
    string FIO;
    string klass;
    char *predmets[3]={"Math", "Fizika", "Informatika"};
    float preds[3];
    float srball[3];
};
Students a[3];
void VvodInfo(){
for (int i = 0; i < 3; i++)
    {
        cout<<"Введите ФИО "<<i+1<<" -о-го ученика "<<endl;
        cin>>a[i].FIO;
        cout<<"Введите класс ученика "<<endl;
        cin>>a[i].klass;
    for (int j = 0; j < 3; j++)
    {
        cout<<a[i].predmets[j]<<" = "; cin>>a[i].preds[j];
    }
    a[i].srball[i]=sredBall(a[i].preds[0], a[i].preds[1],a[i].preds[2]);
    cout<<"Средний балл: "<<a[i].srball[i]<<endl;
    }
}
void VyVod(){
    for (int i = 0; i < 3; i++)
    {
        cout<<"ФИО "<<i+1<<" -о-го ученика "<<a[i].FIO<<endl;
        cout<<"Класс ученика "<<a[i].klass<<endl;
    for (int j = 0; j < 3; j++)
    {
        cout<<a[i].predmets[j]<<" = "<<a[i].preds[j]<<endl;
    }
    a[i].srball[i]=sredBall(a[i].preds[0], a[i].preds[1],a[i].preds[2]);
    cout<<"Средний балл: "<<a[i].srball[i]<<endl;
    }
}

void ZapisVFile(){
ofstream Spisok;
    Spisok.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 4\\Spisok.txt");
    for (int i = 0; i < 3; i++)
    {
        Spisok<<"Second Name: "<<a[i].FIO<<endl;
        Spisok<<"Klass: "<<a[i].klass<<endl;
        for (int j = 0; j < 3; j++)
    {
        Spisok<<a[i].predmets[j]<<" = "<<a[i].preds[j]<<endl;
    }
    Spisok<<fixed;
    Spisok.precision(1);
    Spisok<<"Ball: "<<a[i].srball[i]<<endl;
    }
Spisok.close();
}
void Chtenie(){
    string str;
    int schet=0;
    /* int num; */
    ifstream proverka;
    proverka.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 4\\Spisok.txt");
    if (!proverka.is_open())
    {
        cout<<"ошибка не удалось найти нужный файл. "<<endl;
    }
    else
    {   
    cout<<"Файл открыт."<<endl;
        while(!proverka.eof()){
            getline(proverka,str);
            if (str[0] == 'S')
            {
                a[schet].FIO=str;
            }
            else if(str[0]=='K')
            {
                a[schet].klass=str;
            }
            else if(str[0]=='M')
            {
                a[schet].preds[0]=5;
            }
            else if(str[0]=='F')
            {
                a[schet].preds[1]=6;
            }
            else if(str[0]=='I')
            {
                a[schet].preds[2]=7;
            }
            else if(str[0]=='B')
            {
                a[schet].srball[0]=8;
                schet++;
            }
        }
        cout<<"Чтение проведенно успешно!"<<endl;
    }
}

void Udal(){
    string noviFIO, noviKlass;
    float noviPred = 0, novispedBall = 0;
    int moi;
    ofstream Spisos;
    Spisos.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 4\\Spisok.txt");
    ifstream Spisok;
    Spisok.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 4\\Spisok.txt");
    if (!Spisok.is_open())
    {
        cout<<"ошибка не удалось найти нужный файл. "<<endl;
    }
    else
    {   
    cout<<"Введите фамилию для удаления: "; 
    cin>>noviFIO;
    /* noviFIO = "Second Name: "+noviFIO; */
    if ("Second Name: "+noviFIO==a[0].FIO)
    {
        moi = 0;
    }
    else if("Second Name: "+noviFIO==a[1].FIO){
        moi = 1;
    }
    else if("Second Name: "+noviFIO==a[2].FIO){
        moi = 2;
    }
    }
    string str="", bb="";
    cout<<a[moi].FIO<<endl;
    getline(Spisok,str);
    if (a[moi].FIO=="Second Name: "+noviFIO)
    {
        a[moi].FIO=bb;
        Spisos<<"Second name: "<<a[moi].FIO<<endl;
        a[moi].klass=bb;
        Spisos<<"Klass: "<<a[moi].klass<<endl;
        for (int j = 0; j < 3; j++)
    {
        Spisos<<a[moi].predmets[j]<<" = "<<0<<endl;
    }
    a[moi].srball[moi]=0;
        Spisos<<"Ball: "<<a[moi].srball[moi]<<endl;
    }
    for (int i = 1; i < 3; i++)
    {   
        Spisos<<"Second name"<<a[i].FIO<<endl;
        Spisos<<"Klass "<<a[i].klass<<endl;
    for (int j = 0; j < 3; j++)
    {
        Spisos<<a[i].predmets[j]<<" = "<<a[i].preds[j]<<endl;
    }
    a[i].srball[i]=sredBall(a[i].preds[0], a[i].preds[1],a[i].preds[2]);
    Spisos<<"Ball: "<<a[i].srball[i]<<endl;
    }
    Spisos.close();
    cout<<"vot = "<<a[moi].FIO<<endl;
}

void Poisk(){
    ifstream proverka;
    proverka.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 4\\Spisok.txt");
    if (!proverka.is_open())
    {
        cout<<"ошибка не удалось найти нужный файл. "<<endl;
    }
    else
    {   
    cout<<"Файл открыт."<<endl;
    string str, uchenik;
    int strelka;
    cout<<"введите фамилию нужного ученика: "; cin>>uchenik;
    if(uchenik==a[0].FIO)
    strelka=0;
    else if(uchenik==a[1].FIO)
    strelka=1;
    else if(uchenik==a[2].FIO)
    strelka=2;

    while(!proverka.eof())
    {
    str="";
    getline(proverka,str);
    if (str=="Фамилия: "+ uchenik)
    {
        cout<<"Фамилия: "<<a[strelka].FIO<<endl;
        cout<<"Класс: "<<a[strelka].klass<<endl;
        for (int j = 0; j < 3; j++)
    {
        cout<<a[strelka].predmets[j]<<" = "<<a[strelka].preds[j]<<endl;
    }
        cout<<"Средний балл: "<<a[strelka].srball[strelka]<<endl;
    }
    }
    }
}

int main() {
    Vyz();
    while(vybor!=0){
    switch (vybor)
    {
    case 1:
        VvodInfo();
        Vyz();
        break;
    case 2:
        VyVod();
        Vyz();
        break;
    case 3:
        Poisk();
        Vyz();
        break;
    case 4:
        ZapisVFile();
        Vyz();
        break;
    case 5:
        Chtenie();
        Vyz();
        break;
    case 6:
    Udal();
    Vyz();
    break;
    
    default:
    cout<<"!!!!!!";
        break;
    }
    }
    return 0;
}
