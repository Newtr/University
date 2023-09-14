#include <iostream>
#include <ctime>

using namespace std; 

int Binar(int arr[], int left, int right, int key){
    int midd = 0;
    while (1)
    {
		midd = (left + right) / 2;
		if (key < arr[midd])       
			right = midd - 1;      
		else if (key > arr[midd])  
			left = midd + 1;	   
		else                       
			return midd;           

		if (left > right)          
			return -1;
    }
    

}

int main(){
    const int SIZE = 20;
    int Arr[SIZE];
    int key, index;
    for (int i = 0; i < 20; i++) 
	{
		Arr[i] = i + 1;
		cout << Arr[i] << " | ";
	}
	cout << "\n\nВведите любое число: ";
	cin >> key;
	index = Binar(Arr, 0, SIZE, key);
	if (index >= 0)
		cout << "Указанное число находится в ячейке с индексом: " << index << "\n\n";
	else
		cout << "В массиве нет такого числа!\n\n";

    return 0;
}

/* int main()
{
	int MyArray[]{ 1, 2, 4, 6, 7, 89, 123, 231, 1000, 1235 };

	int x = 0; 
	int a = 0; 
	int b = 9; 
    cout<<"Enter number: ";
	int WhatFind; 
    cin>>WhatFind;
	bool found; 
	for (found = false; (MyArray[a] < WhatFind) && (MyArray[b] > WhatFind) && !found; )
	{
		x = a + ((WhatFind - MyArray[a]) * (b - a)) / (MyArray[b] - MyArray[a]);
		if (MyArray[x] < WhatFind)
			a = x + 1;
		else if (MyArray[x] > WhatFind)
			b = x - 1;
		else
			found = true;
	}
	if (MyArray[a] == WhatFind)
		cout << WhatFind << " founded in element " << a << endl;
	else if (MyArray[b] == WhatFind)
		cout << WhatFind << " founded in element " << b << endl;
	else
		cout << "Sorry. Not found" << endl;
	return 0;
} */
