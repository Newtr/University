#include <iostream>

using namespace std;

int dicho(int f,int a,int b,int e){
    int c = (a+b)/2;
    if ((b-a)<=2*e)
    {
        return c;
    }
    else if ((f*a)*(f*c)<=0){
        return dicho(f,a,c,e);;
    }
    else if ((f*a)*(f*c)>0)
    {
        return dicho(f,c,b,e);
    }
    
}

int main(){
    int fa,fb;
    cout<<"Enter a and b: ";
    cin>>fa; cin>>fb;
    cout<<"KOREN' = "<<dicho(1,fa,fb,5)<<endl;
    return 0;
}