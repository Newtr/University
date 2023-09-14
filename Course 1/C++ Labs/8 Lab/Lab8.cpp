#include <iostream>
#include <queue>
using namespace std;

queue <int> MyQueue;

void FillQueue(){
    int SizeOfQueue, ValueFOrQueue;
    cout<<"Enter size of Queue: ";
    cin>>SizeOfQueue;
    for (int i = 0; i < SizeOfQueue; i++)
    {
        cin>>ValueFOrQueue;
        MyQueue.push(ValueFOrQueue);
    }
    cout<<"END!"<<endl;
}

void ShowMyQueue(){
    FillQueue();
    while (!MyQueue.empty())
    {
        cout<<MyQueue.front()<<"\t";
        MyQueue.pop();
    }
    
}

void DeleteMyQueue(){
    FillQueue();
    while (!MyQueue.empty())
    {
        MyQueue.pop();
    }
    if (MyQueue.empty())
    cout<<"MyQueue is empty!"<<endl;
    else
    cout<<"MyQueue is not empty!"<<endl;
}

void SizeOfMyQueue(){
    FillQueue();
    int SizeOfMyQUeue = MyQueue.size();
    cout<<"Size of My Queue = "<<SizeOfMyQUeue;
}

void DeleteFirstMinus(){
    FillQueue();
    int NewQueue[MyQueue.size()-1];
    int ValueOfQueue, i=0;
    bool FirstMinus = false;
    while (!MyQueue.empty())
    {
        ValueOfQueue = MyQueue.front();
        if (FirstMinus==false)
        {
        if (ValueOfQueue < 0)
        FirstMinus=true;
        else
        NewQueue[i]=ValueOfQueue;
        MyQueue.pop();
        if(FirstMinus==false)
        i++;
        else
        continue;
        }
        else{
        NewQueue[i]=ValueOfQueue;
        MyQueue.pop();
        i++;
        }
    }
    for (int i = 0; i < sizeof(NewQueue)/sizeof(*NewQueue); i++)
    {
        ValueOfQueue = NewQueue[i];
        MyQueue.push(ValueOfQueue);
    }
    while (!MyQueue.empty())
    {
        cout<<MyQueue.front()<<"\t";
        MyQueue.pop();
    }
    
}

int main(){
    // ShowMyQueue();
    // DeleteMyQueue();
    // SizeOfMyQueue();
    DeleteFirstMinus();
    return 0;
}