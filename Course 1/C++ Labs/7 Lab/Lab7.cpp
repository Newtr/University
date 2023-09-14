#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

stack <int> steck;

int mychoose;

int Vyz(){
    cout<<"(1)Основное задание\n(2)Очистка стека\n(3)Запись в файл\n(4)Чтение из файла\n(0)Exit\nВаш Выбор: ";
    cin>>mychoose;
    return mychoose;
}

void FillStack(){
    steck.push(12);
    steck.push(67);
    steck.push(8);
    steck.push(25);
    steck.push(94);
    steck.push(39);
}


void ClearStack(){
    FillStack();
    while (!steck.empty())
    {
        steck.pop();
    }
    if (steck.empty())
    cout<<"Stack is empty!"<<endl;
    else
    cout<<"Stack is not empty!"<<endl;
    
}

void CreateFile(){
    FillStack();
    ofstream File;
    File.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 7\\Stack Info.txt");
    while(!steck.empty())
    {
        File<<steck.top()<<endl;
        steck.pop();
    }
    File.close();
}

void ReadFromFile(){
    ifstream Filus;
    string str;
    Filus.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 7\\Stack Info.txt");
    while (!Filus.eof())
    {
        getline(Filus,str);
        if (str=="")
        break;
        steck.push(stoi(str));
    }
/*     while (!steck.empty())
    {
        cout<<steck.top()<<"\t";
        steck.pop();
    }
    cout<<endl; */
    Filus.close();
}
void CreateNewStack(){
    ReadFromFile();
    stack <int> steck1;
    stack <int> steck2;
    while (!steck.empty())
    {
        if(steck.top()>50){
            steck1.push(steck.top());
        }
        else{
            steck2.push(steck.top());
        }
        steck.pop();
    }
    while (!steck1.empty())
    {
        cout<<steck1.top()<<"\t";
        steck1.pop();
    }
    
    cout<<endl;
    while (!steck2.empty())
    {
        cout<<steck2.top()<<"\t";
        steck2.pop();
    }
    cout<<endl;
}


int main(){
    Vyz();
    while (mychoose!=0)
    {
        switch (mychoose)
        {
        case 1:
            CreateNewStack();
            Vyz();
            break;
        case 2:
            ClearStack();
            Vyz();
            break;
        case 3:
            CreateFile();
            Vyz();
            break;
        case 4:
            ReadFromFile();
            Vyz();
            break;
            break;
        default:
        cout<<"!!!!!!!!!!!!!!!!!!!!!";
            break;
        }
    }
}