#include <iostream>
#include <string>

using namespace std;

struct Teachers
{
    string Second_name;
    int age;
    float salary;
} MyTeacher[3];

int main(){
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            MyTeacher[0].Second_name = "Filipov";
            MyTeacher[0].age = 31;
            MyTeacher[0].salary = 32.54;
            break;
        case 1:
            MyTeacher[1].Second_name = "Gavrilov";
            MyTeacher[1].age = 34;
            MyTeacher[1].salary = 23.56;
            break;
        case 2:
            MyTeacher[2].Second_name = "Petrov";
            MyTeacher[2].age = 23;
            MyTeacher[2].salary = 21.78;
            break;
        }
    }
    string UserString;
    cout<<"Enter Second name: ";    cin>>UserString;
    size_t pos;
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            pos = MyTeacher[0].Second_name.find(UserString);
            if (pos != string::npos)
            cout << "Это первый учитель. Filipov"<< "\n";
            break;
        case 1:
            pos = MyTeacher[1].Second_name.find(UserString);
            if (pos != string::npos)
            cout << "Это второй учитель. Gavrilov"<< "\n";
            break;
        case 2:
            pos = MyTeacher[2].Second_name.find(UserString);
            if (pos != string::npos)
            cout << "Это третий учитель. Petrov"<< "\n";
            break;
        }
    }
    
}