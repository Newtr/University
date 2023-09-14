#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Teachers 
{
    string name;
    int age;
    float salary;
};
Teachers *MyTeachers = new Teachers[2];


void CreateFile(){
    string UserFileName;
    cout<<"Enter File Name: ";
    cin>>UserFileName;
    ofstream MyNewFile;
    MyNewFile.open("D:\\Data Base\\Lr5\\"+UserFileName+".txt");
    for (int i = 0; i < sizeof(MyTeachers); i++)
    {
        switch (i)
        {
        case 0:
            MyTeachers[i].name="Vladimir";
            MyTeachers[i].age=35;
            MyTeachers[i].salary=27.53;
            break;
        case 1:
            MyTeachers[i].name="Nikita";
            MyTeachers[i].age=42;
            MyTeachers[i].salary=32.67;
            break;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        MyNewFile<<"Name: "<<MyTeachers[i].name<<endl;
        MyNewFile<<"Age: "<<MyTeachers[i].age<<endl;
        MyNewFile<<"Salary: "<<MyTeachers[i].salary<<endl;
        MyNewFile<<"\n";
    }
    cout<<"the file has been successfully compiled!"<<endl;
    MyNewFile.close();
}

void ReadInfoFromFile(){
    string UserFileName;
    string info;
    cout<<"Enter File Name: ";
    cin>>UserFileName;
    ifstream MyFile;
    int n=0;
    MyFile.open("D:\\Data Base\\Lr5\\"+UserFileName+".txt");
    while (!MyFile.eof())
    {
        getline(MyFile,info);
        if (info[0]=='N')
        {
            info.erase(0,6);
            MyTeachers[n].name=info;
        }
        else if(info[0]=='A')
        {
            info.erase(0,5);
            MyTeachers[n].age=stoi(info);
        }
        else if(info[0]=='S')
        {
            info.erase(0,8);
            MyTeachers[n].salary=stof(info);
        }
        else if(info=="")
        {
            n++;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        cout<<"Name: "<<MyTeachers[i].name<<endl;
        cout<<"Age: "<<MyTeachers[i].age<<endl;
        cout<<"Salary: "<<MyTeachers[i].salary<<endl;
    }
    MyFile.close();
}
void NewMember(){
    Teachers *MyTeacherNow=new Teachers[3];
    for (int i = 0; i < 2; i++)
    {
        MyTeacherNow[i].name=MyTeachers[i].name;
        MyTeacherNow[i].age=MyTeachers[i].age;
        MyTeacherNow[i].salary=MyTeachers[i].salary;
    }
    delete []MyTeachers;
    MyTeachers=MyTeacherNow;
/*     cout<<"MAGIC!!!!!!!!!!!!!!!!!!!!";
    for (int i = 0; i < 2; i++)
    {
        cout<<MyTeacherNow[i].name;
        cout<<MyTeacherNow[i].age;
        cout<<MyTeacherNow[i].salary;
    } */
    cout<<"New Name: "<<endl; 
    cin>>MyTeacherNow[2].name;
    cout<<"New Age: "<<endl; 
    cin>>MyTeacherNow[2].age;
    cout<<"New Salary: "<<endl; 
    cin>>MyTeacherNow[2].salary;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    cout<<"Name: "<<MyTeacherNow[2].name<<endl;
    cout<<"Age: "<<MyTeacherNow[2].age<<endl;
    cout<<"Salary: "<<MyTeacherNow[2].salary<<endl;
    string UserFileName;
    cout<<"Enter File Name: ";
    cin>>UserFileName;
    cout<<endl;
    ofstream MyFile;
    MyFile.open("D:\\Data Base\\Lr5\\"+UserFileName+".txt");
    for (int i = 0; i < 3; i++)
    {
        MyFile<<"Name: "<<MyTeachers[i].name<<endl;
        MyFile<<"Age: "<<MyTeachers[i].age<<endl;
        MyFile<<"Salary: "<<MyTeachers[i].salary<<endl;
        MyFile<<"\n";
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"Name: "<<MyTeachers[i].name<<endl;
        cout<<"Age: "<<MyTeachers[i].age<<endl;
        cout<<"Salary: "<<MyTeachers[i].salary<<endl;
        cout<<"\n";
    }
    MyFile.close();
}
int main(){
/*     CreateFile();
    ReadInfoFromFile();
    NewMember(); */
    int mychoose;
    cout<<"Enter: (1)To file, (2)ReadFile, (3)New Member:";
    cin>>mychoose;
    switch (mychoose)
    {
    case 1:
        CreateFile();
        break;
    case 2:
        ReadInfoFromFile();
        break;
    case 3:
        NewMember();
        break;
    }
    return 0 ;
}