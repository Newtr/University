#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

list<int> newlist={5,-6,3,7,8,-4};

    int Mychoose;

int vyz(){
    cout<<" (1)Сумма \n (2)Добавление элемента \n (3)Удаление элемента \n (4)Поиск элемента \n (5)Вывод списка \n (6)Запись в файл \n (7)Считывание из файла \n (0)Выход \n ";
    cin>>Mychoose;
    return Mychoose;
}

void Sum(){
    int NewListArray[newlist.size()];
    int count=0, sum=0;
    for (int i :newlist)
    {
        NewListArray[count]=i;
        count++;
    }
    for (int i = 0; i < (sizeof(NewListArray)/sizeof(*NewListArray)); i++)
    {
        cout<<NewListArray[i]<<"\t";
        if (NewListArray[i]<0 && NewListArray[i]%2==0)
        {
            sum+=NewListArray[i];
        }
        
    }
    if (sum==0)
    cout<<"\nNo minus elements!";
    else
    cout<<"\nSum = "<<sum;
    cout<<endl;
}  

void VyvodList(){
    int NewListArray[newlist.size()];
    int count=0;
    for (int i :newlist)
    {
        NewListArray[count]=i;
        count++;
    }
    for (int i = 0; i < (sizeof(NewListArray)/sizeof(*NewListArray)); i++)
    {
        cout<<NewListArray[i]<<"\t";
    }
    cout<<endl;
}

void DeleteElement(){
    int NewListArray[newlist.size()];
    int count=0, choose;
    list<int>::iterator it = newlist.begin();
    for (int i :newlist)
    {
        NewListArray[count]=i;
        count++;
    }
    for (int i = 0; i < (sizeof(NewListArray)/sizeof(*NewListArray)); i++)
    {
        cout<<NewListArray[i]<<"\t";
    }
    cout<<endl;
    cout<<"Enter element: ";
    cin>>choose;
    switch (choose)
    {
    case 5:
        newlist.erase(it);
        break;
    case -6:
        advance(it,1);
        newlist.erase(it);
        break;
    case 3:
        advance(it,2);
        newlist.erase(it);
        break;
    case 7:
        advance(it,3);
        newlist.erase(it);
        break;
    case 8:
        advance(it,4);
        newlist.erase(it);
        break;
    case -4:
        advance(it,5);
        newlist.erase(it);
        break;
    }
    int NewListArray2[newlist.size()];
    int count2=0;
    for (int i :newlist)
    {
        NewListArray2[count2]=i;
        count2++;
    }
    for (int i = 0; i < (sizeof(NewListArray2)/sizeof(*NewListArray2)); i++)
    {
        cout<<NewListArray2[i]<<"\t";
    }
    cout<<endl;
}

void AddElement(){
    int NewListArray[newlist.size()];
    int count=0, choose;
    for (int i :newlist)
    {
        NewListArray[count]=i;
        count++;
    }
    for (int i = 0; i < (sizeof(NewListArray)/sizeof(*NewListArray)); i++)
    {
        cout<<NewListArray[i]<<"\t";
    }
    cout<<"\nEnter element: ";
    cin>>choose;
    newlist.push_back(choose);
    int NewListArray2[newlist.size()];
    int count2=0;
    for (int i :newlist)
    {
        NewListArray2[count2]=i;
        count2++;
    }
    for (int i = 0; i < (sizeof(NewListArray2)/sizeof(*NewListArray2)); i++)
    {
        cout<<NewListArray2[i]<<"\t";
    }
    cout<<endl;
}

void Search(){
    int NewListArray[newlist.size()];
    int count=0, choose;
    bool GG=false;
    for (int i :newlist)
    {
        NewListArray[count]=i;
        count++;
    }
    for (int i = 0; i < (sizeof(NewListArray)/sizeof(*NewListArray)); i++)
    {
        cout<<NewListArray[i]<<"\t";
    }
    cout<<"\nEnter: ";
    cin>>choose;
    list<int>::iterator iter = find(newlist.begin(), newlist.end(), choose);
    /* cout<<"Iter = "<<*iter; */
    for (int i : newlist)
    {
        if (i==*iter)
        {
            GG=true;
        }
    }
    if (GG==true)
    cout<<"Такой элемент присутствует в списке!"<<endl;
    else
    cout<<"Такого элемента нет в списке!"<<endl;
GG=false;
}

void ToFile(){
    ofstream Filus;
    Filus.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 6\\File.txt");
    for (int i : newlist)
    {
        Filus<<i<<"\n";
    }
    
    Filus.close();
}

void ReadFile(){
    ifstream MyFile;
    int NewListArray[newlist.size()];
    string ss;
    int i=0;
    MyFile.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 6\\File.txt");
    while (!MyFile.eof())
    {
        getline(MyFile,ss);
        if(ss=="")
        continue;
        NewListArray[i++]=stoi(ss);
    }
    int n = (sizeof(NewListArray)/sizeof(*NewListArray));
    for (int i = 0; i < n; i++)
    {
        cout<<NewListArray[i]<<"\t";
    }
    cout<<endl;
}

int main(){
vyz();
while (Mychoose!=0)
{
    switch (Mychoose)
    {
    case 1:
        Sum();
        vyz();
        break;
    case 2:
        AddElement();
        vyz();
        break;
    case 3:
        DeleteElement();
        vyz();
        break;
    case 4:
        Search();
        vyz();
        break;
    case 5:
        VyvodList();
        vyz();
        break;
    case 6:
        ToFile();
        vyz();
        break;
    case 7:
        ReadFile();
        vyz();
        break;
    }
}
}
