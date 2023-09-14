#include<iostream>
#include<climits>
using namespace std;

void swap(int *x, int *y);


class MinHeap
{
	int *harr; 
	int capacity; 
	int heap_size; 
public:
	MinHeap(int capacity);

	void MinHeapify(int );

	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	int extractMin();

	void decreaseKey(int i, int new_val);

	int getMin() { return harr[0]; }

	void deleteKey(int i);

	void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}


void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}


int MinHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}



void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}


void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}



int main()
{
    MinHeap h(10);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
	return 0;
}









/* #include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int idx)
{
    if (idx >= n)
        return;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max;
    if (l < n && arr[l] > arr[idx])
        max = l;
    else
        max = idx;
    if (r < n && arr[r] > arr[max])
        max = r;

    if (max != idx) {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}
 
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
 
void mergeHeaps(int merged[], int a[], int b[],
                int n, int m)
{

    for (int i = 0; i < n; i++)
        merged[i] = a[i];
    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];
 

    buildMaxHeap(merged, n + m);
}
 

int main()
{
    int a[] = { 10, 5, 6, 2 };
    int b[] = { 12, 7, 9 };
 
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
 
    int merged[m + n];
    mergeHeaps(merged, a, b, n, m);
 
    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";
 
    return 0;
} */