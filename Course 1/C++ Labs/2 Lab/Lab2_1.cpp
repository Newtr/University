#include<iostream>
#include<fstream>
#include<string>
#include <cstring>
#include <algorithm>
using namespace std;
void vsiat(string str){
    cout<<str.at(0)<<str.at(1)<<str.at(2);
}
int main(){
    string text;
    cout<<"Введите строку "<<endl; 
    getline(cin,text);
    ofstream ThisFile("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 3\\ThisFile.txt");
    ThisFile<<text;
    ThisFile.close();
    ifstream file("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 3\\ThisFile.txt");
    if (!file.is_open())
    {
        cout<<"Error file not found";
    }
    else{
        getline(file,text);
        cout<<text<<endl;
        vsiat(text);
    }
    file.close();
    return 0;
}