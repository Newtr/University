#include <iostream>
#include <string>

using namespace std;

struct Teachers{
    string FIO;
    int age;
    float salary;
} MyTeachers[3];

void FillStruct(){
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            MyTeachers[i].FIO="Anatoliy Karpov";
            MyTeachers[i].age=35;
            MyTeachers[i].salary=32.45;
            break;
        case 1:
            MyTeachers[i].FIO="Kiril Potapov";
            MyTeachers[i].age=47;
            MyTeachers[i].salary=42.56;
            break;
        case 2:
            MyTeachers[i].FIO="Bogdan Felipov";
            MyTeachers[i].age=25;
            MyTeachers[i].salary=27.97;
            break;
        }
    }
}

void SortByAge(){
    FillStruct();
    int smallest_age;
    for (int i = 0; i < 3; i++)
    {
        smallest_age = i;
        for (int j = i+1; j < 3; j++)
        {
            if (MyTeachers[j].age<MyTeachers[smallest_age].age)
            {
                smallest_age=j;
            }
            
        }
        swap(MyTeachers[smallest_age], MyTeachers[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"ФИО: "+MyTeachers[i].FIO<<endl<<"Возраст: "<<MyTeachers[i].age<<endl<<"Зарплата: $"<<MyTeachers[i].salary<<endl;
        cout<<endl;
    }
    
}

void SortBySalary(){
    FillStruct();
    int smallest_salary;
    for (int i = 0; i < 3; i++)
    {
        smallest_salary = i;
        for (int j = i+1; j < 3; j++)
        {
            if (MyTeachers[j].salary<MyTeachers[smallest_salary].salary)
            {
                smallest_salary=j;
            }
            
        }
        swap(MyTeachers[smallest_salary], MyTeachers[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<"ФИО: "+MyTeachers[i].FIO<<endl<<"Возраст: "<<MyTeachers[i].age<<endl<<"Зарплата: $"<<MyTeachers[i].salary<<endl;
        cout<<endl;
    } 
}

/* void SortByFIO(){
    FillStruct();
    int smallest_FIO;
    string Vot1 , vot2;
    for (int i = 0; i < 3; i++)
    {
        smallest_FIO=i;
        Vot1 = MyTeachers[i].FIO[0];
        Vot1+=MyTeachers[i].FIO[1];     
        Vot1+=MyTeachers[i].FIO[2];     
        for (int j = j+1; j < 3; j++)
        {
            vot2 = MyTeachers[j].FIO[0];
            vot2 = MyTeachers[j].FIO[1];
            vot2 = MyTeachers[j].FIO[2];
            if (vot2<Vot1)
            {
                smallest_FIO=i;
            }
            swap(MyTeachers[smallest_FIO], MyTeachers[i]);
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        cout<<MyTeachers[i].FIO[0]<<MyTeachers[i].FIO[1]<<MyTeachers[i].FIO[2]<<endl;
    } 
} */

int main(){
    int mychoose;
    cout<<"Сортировка по:\n"<<"1)Возрасту\n"<<"2)Зарплате\n";
    cin>>mychoose;
    switch (mychoose)
    {
    case 1:
        SortByAge();
        break;
    case 2:
        SortBySalary();
        break;
    }
    return 0;
}