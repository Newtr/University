#include <iostream>
#include <deque>
#include <ctime>


using namespace std;

deque <int> form1;
deque <int> form2;
deque <int> Tod;

void FillForm1(){
    for (int i = 0; i < 10; i++)
    {
        form1.push_front(rand()%20);
    }
    cout<<endl;
}

void FillForm2(){
    for (int j = 0; j < 10; j++)
    {
        form2.push_front(rand()%20);
    }
    
}

void OneByOne (deque <int> Kuda, deque <int> first, deque <int> second){
    int count=0;
    int size = first.size() + second.size();
    while (count!=size)
    {
        if (count%2==0)
        {
            Kuda.push_front(first.front());
            cout<<"1) "<<first.front()<<endl;
            first.pop_front();
        }
        else if (count%2!=0)
        {
            Kuda.push_front(second.front());
            cout<<"2) "<<second.front()<<endl;
            second.pop_front();
        }
        count++;
    }
    cout<<"------------------------------------\n";
    while (!Kuda.empty())
    {
        cout<<Kuda.front()<<"\t";
        Kuda.pop_front();
    }
    
}

int main(){
    srand(time(NULL));
    FillForm1();
    FillForm2();
    OneByOne(Tod,form1,form2);
    return 0;
}