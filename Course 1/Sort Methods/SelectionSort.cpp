#include <iostream>

using namespace std;

void SelectionSort(int a[], int n) 
{
	int smallest_id;

	for (int i = 0; i < n; i++) {
		smallest_id = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[smallest_id])
				smallest_id = j;
		}
		swap(a[smallest_id], a[i]);
	}
}


int main(){ 
    const int SIZE = 10;
    int Arr[SIZE] = {4,7,8,1,23,78,12,65,9,98};
    for (int i = 0; i < 10; i++)
    {
        cout<<Arr[i]<<" | ";
    }
    SelectionSort(Arr,SIZE);
    cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<Arr[i]<<" | ";
    }
    
    return 0;
}