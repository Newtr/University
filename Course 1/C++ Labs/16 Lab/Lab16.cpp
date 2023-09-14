#include <iostream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void FillRandom(int (&arr)[1000]){
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        arr[i]=rand()%10000;
    }
    
}

void nechet(int (&arrA)[1000], int (&arrB)[1000], int (&arrC)[1000]){
    int i=0,b=0;
    while(b!=1000){
        if (arrA[b]%2==0)
        {
            arrC[i]=arrA[b];
            i++;
            b++;
        }
        else{
            b++;
        }
    }
    b=b;
    while(i!=1000){
    if (arrB[b]%2==0)
        {
            arrC[i]=arrB[b];
            i++;
            b++;
        }
        else{
            b++;
        }
    }
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}


void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR){
int i = 0;
int j = 0;
while(i<lenL||j<lenR){
    if (i<lenL & j<lenR){
    if(L[i]<=R[j]){
        merged[i+j] = L[i];
        i++;
    }
    else{
        merged[i+j] = R[j];
        j++;
    }
    }
    else if(i<lenL){
    merged[i+j] = L[i];
    i++;
    }
    else if(j<lenR){
    merged[i+j] = R[j];
    j++;
    }
}
}

void mergeSort(int data[], int lenD)
{
if(lenD>1){
    int middle = lenD/2;
    int rem = lenD-middle;
    int* L = new int[middle];
    int* R = new int[rem];
    for(int i=0;i<lenD;i++){
    if(i<middle){
        L[i] = data[i];
    }
    else{
        R[i-middle] = data[i];
    }
    }
    mergeSort(L,middle);
    mergeSort(R,rem);
    merge(data, lenD, L, middle, R, rem);
}
}

void hoarasort(int* a, int first, int last)
{

int i = first, j = last;
double tmp, x = a[(first + last) / 2];

do {
  while (a[i] < x)
    i++;
  while (a[j] > x)
    j--;

  if (i <= j) 
  {
    if (i < j)
    {
      tmp=a[i];
      a[i]=a[j];
      a[j]=tmp;
    }
    i++;
    j--;
  }
} while (i <= j);

if (i < last)
  hoarasort(a, i, last);
if (first < j)
  hoarasort(a, first,j);
}


void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; 
  int done = 0; 
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)    
      maxChild = root * 2;    
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; 
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else 
      done = 1; 
  }
}

void heapSort(int *numbers, int array_size) 
{
  for (int i = (array_size / 2); i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}

int main(){
    clock_t startTime = clock();
    int arrA[1000],arrB[1000],arrC[1000];
    FillRandom(arrA);
    FillRandom(arrB);
    nechet(arrA,arrB,arrC);
    for (int i = 0; i < 1000; i++)
    {
        cout<<arrC[i]<<endl;
    }
    cout<<"<--------------------------------------------------------------------------------------------------------->"<<endl;
    // BubbleSort(arrC,1000); //lab 16
    // mergeSort(arrC,1000);  //lab 16-17
    // hoarasort(arrC,0,1000);  //lab 17
    //  heapSort(arrC,1000);  // lab 17
    clock_t endTime = clock();
    for (int i = 0; i < 1000; i++)
    {
        cout<<arrC[i]<<endl;
    }
  clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC*1000;
  cout << "Elapsed time: " << duration << " ms" << endl;
    return 0;
}