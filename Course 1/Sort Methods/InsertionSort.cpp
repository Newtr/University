#include <iostream>

using namespace std; 

void InsertionSort(int data[], int lenD)
{
int key = 0;
int i = 0;
for(int j = 1;j<lenD;j++){
    key = data[j];
    i = j-1;
    while(i>=0 && data[i]>key){
    data[i+1] = data[i];
    i = i-1;
    data[i+1]=key;
    }
}
}

int main(){
    const int SIZE = 12;
    int Arr[SIZE] = {1,56,78,13,34,50,74,22,38,12,39,5};
    for (int i = 0; i < 12; i++)
    {
        cout<<Arr[i]<<" | ";
    }
    cout<<endl;
    InsertionSort(Arr,SIZE);
    for (int i = 0; i < 12; i++)
    {
        cout<<Arr[i]<<" | ";
    }
    return 0; 
}