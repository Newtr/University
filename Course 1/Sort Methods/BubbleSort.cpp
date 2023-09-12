#include <iostream>

using namespace std;

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}


int main(){
    const int SIZE = 11;
    int Arr[SIZE] = {4,67,89,223,33,45,12,3,6,9,1};
    for (int i = 0; i < 11; i++)
    {
        cout<<Arr[i]<<" | ";
    }
    cout<<endl;
    BubbleSort(Arr,SIZE);
    for (int i = 0; i < 11; i++)
    {
        cout<<Arr[i]<<" | ";
    }
    return 0;
}