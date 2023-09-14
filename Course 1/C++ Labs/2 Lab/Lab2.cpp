#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;
int schet(char str[]){
    int kolvo=0;
    char glas[]= {'a','e','i','y','u','o'};
    for (int i=0; i < strlen(str); i++)
                for (int j=0; j< strlen(glas); j++)
                {
                        if (str[i]==glas[j])
                        {
                                kolvo++;
                                break;
                        }
                }
        /* printf("k=%d\n",kolvo); */
    return kolvo;
}
int main(){
    int max=0;
    char stroka1_1[]={"stroka"};
    char stroka1_2[]={"stroka no bolshe"};
    char stroka1_3[]={"samaja bolshaja stroka s glasnymi"};
    char* stroki[]={stroka1_1,stroka1_2,stroka1_3};
    ofstream file1;
    file1.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 3\\File1.txt");
    file1 << stroka1_1 <<endl<< stroka1_2 <<endl<< stroka1_3 <<endl;
    file1.close();
    for (int i = 0; i < 2; i++)
    {
        if (schet(stroki[i])<schet(stroki[i+1]))
        {
            max=i+1;
        }
        else {
            max=i;
        }
    };
    /* cout<<"Max = "<<max<<endl;
    cout<<"VOT ETA STROKA ---->>>>>>"<<stroki[max]; */
    ofstream file2;
    file2.open("C:\\Users\\Newtr\\OneDrive\\Desktop\\C++ Saves\\Lr 3\\File2.txt");
    if(!file2.is_open()){
        cout<<"ERROR FILE IS NOT FOUND";
    }
    else{
        for (int i = 0; i < 2 && i!=max; i++)
        {
            file2 << stroki[i]<<endl;
        }
        
    }
    file2<<"Номер самой большой строки = "<<max+1<<" ("<<stroki[max]<<") ";
    file2.close();
    return 0;
}