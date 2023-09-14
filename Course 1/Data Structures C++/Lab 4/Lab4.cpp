#include <iostream>
#include <string>
#include <ctime>
using namespace std;


struct Teacher 
{
    string Name;
    int Age;
    unsigned long int zip;
} teacher[5];
struct WorkExperience
{
    short int Day;
    short int Month;
    short int Year;
} date[5];
/* unsigned long int ZipInfo[5]; */
enum Numbers{
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
};
void FillStruct(){
    for (int i = 0; i < 5; i++)
    {
        switch (i)
        {
        case 0:
            teacher[i].Name = "Vasil";
            teacher[i].Age = 35;
            date[i].Day = 12;
            date[i].Month = 11;
            date[i].Year = 1997;
            break;
        case 1:
            teacher[i].Name = "Nikita";
            teacher[i].Age = 22;
            date[i].Day = 21;
            date[i].Month = 10;
            date[i].Year = 2000;
            break;
        case 2:
            teacher[i].Name = "Fedor";
            teacher[i].Age = 48;
            date[i].Day = 30;
            date[i].Month = 12;
            date[i].Year = 1987;
            break;
        case 3:
            teacher[i].Name = "Andrey";
            teacher[i].Age = 21;
            date[i].Day = 27;
            date[i].Month = 5;
            date[i].Year = 1990;
            break;
        case 4:
            teacher[i].Name = "Pavel";
            teacher[i].Age = 31;
            date[i].Day = 23;
            date[i].Month = 4;
            date[i].Year = 1994;
            break;
        }
    }
    
}
void FillZips(){
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        teacher[i].zip = rand() % 9999999+1000000;
        /* ZipInfo[i]=teacher[i].zip; */
    }
    cout<<endl;
    cout<<"Here all teacher's Zips: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<teacher[i].zip<<endl;
    }
    
}
int main(){
    unsigned long int UserChoose;
    FillStruct();
    FillZips();
    cout<<"Copy one of this zip's to see the information: ";     cin>>UserChoose;
    if (UserChoose == teacher[0].zip)
    {
        UserChoose = FIRST;
    }
    else if (UserChoose == teacher[1].zip)
    {
        UserChoose = SECOND;
    }
    else if (UserChoose == teacher[2].zip)
    {
        UserChoose = THIRD;
    }
    else if (UserChoose == teacher[3].zip)
    {
        UserChoose = FOURTH;
    }
    else if (UserChoose == teacher[4].zip)
    {
        UserChoose = FIFTH;
    }
    switch (UserChoose)
    {
    case FIRST:
        cout<<"Name: "<<teacher[FIRST].Name<<endl;
        cout<<"Age: "<<teacher[FIRST].Age<<endl;
        cout<<"Date of Birth "<<date[FIRST].Day<<"."<<date[FIRST].Month<<"."<<date[FIRST].Year<<endl;
        cout<<"Zip: "<<teacher[FIRST].zip;
        break;
    case SECOND:
        cout<<"Name: "<<teacher[SECOND].Name<<endl;
        cout<<"Age: "<<teacher[SECOND].Age<<endl;
        cout<<"Date of Birth "<<date[SECOND].Day<<"."<<date[SECOND].Month<<"."<<date[SECOND].Year<<endl;
        cout<<"Zip: "<<teacher[SECOND].zip;
        break;
    case THIRD:
        cout<<"Name: "<<teacher[THIRD].Name<<endl;
        cout<<"Age: "<<teacher[THIRD].Age<<endl;
        cout<<"Date of Birth "<<date[THIRD].Day<<"."<<date[THIRD].Month<<"."<<date[THIRD].Year<<endl;
        cout<<"Zip: "<<teacher[THIRD].zip;
        break;
    case FOURTH:
        cout<<"Name: "<<teacher[FOURTH].Name<<endl;
        cout<<"Age: "<<teacher[FOURTH].Age<<endl;
        cout<<"Date of Birth "<<date[FOURTH].Day<<".0"<<date[FOURTH].Month<<"."<<date[FOURTH].Year<<endl;
        cout<<"Zip: "<<teacher[FOURTH].zip;
        break;
    case FIFTH:
        cout<<"Name: "<<teacher[FIFTH].Name<<endl;
        cout<<"Age: "<<teacher[FIFTH].Age<<endl;
        cout<<"Date of Birth "<<date[FIFTH].Day<<".0"<<date[FIFTH].Month<<"."<<date[FIFTH].Year<<endl;
        cout<<"Zip: "<<teacher[FIFTH].zip;
        break;
    default:
    cout<<"No Info!!!!!";
        break;
    }
    return 0;
}