#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
    string Name;
    float eng_mark, math_mark, phys_mark, sci_mark, art_mark;
    double average_mark;
    string status;

    void GetInfo();
    void Calculate();
    void ShowData();
};

void Student::Calculate(){
    average_mark = (eng_mark+math_mark+phys_mark+sci_mark+art_mark)/5;
    if (average_mark>8)
    {
        status = "Best";
    }
    else if (average_mark>6)
    {
        status = "Good";
    }
    else if (average_mark>5)
    {
        status = "Bad";
    }
    else 
    {
        status = "Awful";
    }
}

void Student::GetInfo(){
    cout<<"\nStudent name: ";
    cin>>Name;
    cout<<"\nEnter marks in English: ";
    cin>>eng_mark;
    cout<<"\nEnter marks in Math: ";
    cin>>math_mark;
    cout<<"\nEnter marks in Physics: ";
    cin>>phys_mark;
    cout<<"\nEnter marks in Science: ";
    cin>>sci_mark;
    cout<<"\nEnter marks in Art: ";
    cin>>art_mark;
    Calculate();
}

void Student::ShowData(){
    cout<<"Student name: "<<Name;
    cout<<"English: "<<eng_mark;
    cout<<"Math: "<<math_mark;
    cout<<"Physics: "<<phys_mark;
    cout<<"Science: "<<sci_mark;
    cout<<"Art: "<<art_mark;
    cout<<"Status of student: "<<status;
}

void CreateStudent()
{
    Student stud;
    ofstream OFile;
    OFile.open("Student.txt", ios::binary|ios::app);
    stud.GetInfo();
    OFile<<"Name: "<<stud.Name
    <<" English: "<<stud.eng_mark
    <<" Math: "<<stud.math_mark
    <<" Physics: "<<stud.phys_mark
    <<" Science: "<<stud.sci_mark
    <<" Art: "<<stud.art_mark
    <<" Status: "<<stud.status<<endl;
    OFile.close();
    cout<<"Student was created successfully!"<<endl;
}

void ShowAllInfo()
{ 
    string str;
    Student stud;
    ifstream IFile;
    IFile.open("Student.txt", ios::binary);
    if (!IFile)
    {
        cout<<"ERROR! Press any key to exit ...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"INFORMATION\n\n";
    while (!IFile.eof())
    {
        getline(IFile,str);
        cout<<str<<endl;
        if (str=="")
        {
            break;
        }
        
    }
    
    IFile.close();
    cin.ignore();
    cin.get();
}

void DeleteStudent(){
    string str, StudentName, NameInFile;
    bool NewWord=false;
    int count=6;
    ifstream IFile;
    IFile.open("Student.txt",ios::binary);
    cout<<"Enter name of student: ";
    cin>>StudentName;
    ofstream OFile;
    OFile.open("temp.txt",ios::binary|ios::app);
    while (!IFile.eof() && NewWord==false)
    {
        getline(IFile,str);
        if (str=="")
        {
            NewWord=true;
            continue;
        }
        
        while (str.at(count)!=' ')
        {
            NameInFile+=str.at(count);
            count++;
        }
        if (NameInFile==StudentName)
        {
            continue;
        }
        else if (NameInFile!=StudentName)
        {
        OFile<<str<<endl;
        NameInFile="";
        count=6;
        }
    }
    OFile.close();
    IFile.close();
    remove("Student.txt");
    rename("temp.txt","Student.txt");
    cout<<"All good!";

}

int main(){
    int UserChoose;
    do{
    cout<<"1)Create Student"<<endl;
    cout<<"2)Show All Information about students"<<endl;
    cout<<"3)Delete Student"<<endl;
    cout<<"4)Exit"<<endl;
    cout<<"Your choose : "; cin>>UserChoose;
    switch (UserChoose)
    {
    case 1:
        CreateStudent();
        break;
    case 2:
        ShowAllInfo();
        break;
    case 3:
        DeleteStudent();
        break;
    }
    }while(UserChoose!=4);
    return 0;
}
