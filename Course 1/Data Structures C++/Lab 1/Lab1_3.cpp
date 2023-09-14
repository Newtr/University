#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque <int> array;
    for (int i = 1; i <= 10; i++)
    {
        array.push_front(i);
    }
    for (int j = 0; j < array.size(); j++)
    {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    int min=array[0];
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i]<min)
        {
            min=array[i];
        }
    }
    cout<<"Min = "<<min<<endl;
    array.push_front(min);
    for (int j = 0; j < array.size(); j++)
    {
        cout<<array[j]<<" ";
    }
    return 0;
}