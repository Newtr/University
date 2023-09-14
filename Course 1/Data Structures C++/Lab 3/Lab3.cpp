#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

int myChoose;
string FileName;
int vybor(){
    cout<<"Выберите действие :"<<endl
    <<"(1) Создание и запись данных в файл, название которого вводится с клавиатуры "<<endl
    <<"(2) Чтение файла "<<endl
    <<"(3) Удаление содержимого в файле "<<endl
    <<"(4) Удаление файла "<<endl
    <<"(0) Выйти из меню"<<endl
    <<"Ваш выбор: ";
    cin>> myChoose;
    return myChoose;
}

void CreateFile(){
    string data1 = "Canada", data2 = "Minsk", data3 = "London";
    cout<<"Enter File name: ";
    cin>>FileName;
    FileName = FileName + ".txt";
    ofstream file;
    file.open("D:\\Data Base\\Lr3\\"+FileName);
    file<<data1<<endl<<data2<<endl<<data3<<endl;
    file.close();
}

void ReadFile(){
    cout<<"Enter File name: "; cin>>FileName;
    FileName+=".txt";
    string str;
    ifstream fileRead;
    fileRead.open("D:\\Data Base\\Lr3\\"+FileName);
    if (!fileRead.is_open())
    {
        cout<<"Error file is not exist "<<endl;
    }
    else
    {
        cout<<"File is open successfully! "<<endl;
        while (!fileRead.eof())
        {
        getline(fileRead,str);
        cout<<str<<endl;
        }
        fileRead.close();
    }
}

void DeleteDataFromFile(){
    cout<<"Enter File name: "; cin>>FileName;
    FileName+=".txt";
    ofstream DeleteInfo;
    DeleteInfo.open("D:\\Data Base\\Lr3\\"+FileName, ofstream::out | ofstream::trunc);
    cout<<"File was cleared successfully! "<<endl;
    DeleteInfo.close();
}

void DeleteFile(){
    cout<<"Enter File name: "; cin>>FileName;
    FileName+=".txt";
    string FullFileName = "D:\\Data Base\\Lr3\\"+FileName;
    char name[FullFileName.length()+1];
    for (int i = 0; i < sizeof(FullFileName); i++)
    {
        name[i]=FullFileName[i];
    }
    remove(name);
    cout<<"File was deleted successfully! "<<endl;
}
int main(){
vybor();
    while (myChoose!=0)
    {
        switch (myChoose)
        {
        case 1:
            CreateFile();
            vybor();
            break;
        case 2:
            ReadFile();
            vybor();
        break;
        case 3:
            DeleteDataFromFile();
            vybor();
        break;
        case 4:
            DeleteFile();
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