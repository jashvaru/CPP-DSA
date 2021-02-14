#include <iostream>
#include <bits/stdc++.h>

using namespace std;

swap(int *data1, int *data2)
{
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

class maxHeap
{
	public:
		int *harr;
		int capacity;
		int heapSize;
		maxHeap(int cap);

		int parent(int i) { return ((i-1)/2);}
		int left(int i) { return ((i*2)+1);}
		int right(int i) { return ((i*2)+2);}

		void insert_key(int key);
		void delete_key(int i);

		void decrease_key(int i, int newVal);
		int extract_max();
		void max_heapify(int i);

};

maxHeap::maxHeap(int cap)
{
	heapSize = 0;
	capacity = cap;
	harr = new int[capacity];
}

void maxHeap::insert_key(int key)
{
	if(heapSize == capacity)
	{
		cout << "Max limit reached" << endl;
		return;
	}

	heapSize++;
	int i = heapSize - 1;
	harr[i] = key;

	while(i != 0 && harr[i] > harr[parent(i)])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

void maxHeap::decrease_key(int i, int newVal)
{
	harr[i] = newVal;
	while(i != 0 && harr[i] > harr[parent(i)])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
}

int maxHeap::extract_max()
{
	if(heapSize <= 0)
	{
		return INT_MIN;
	}
	if(heapSize == 1)
	{
		heapSize--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heapSize - 1];
	heapSize--;
	max_heapify(0);

	return root;
}

void maxHeap::max_heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;

	if(l < heapSize && harr[l] > harr[i])
	{
		largest = l;
	}
	if(r < heapSize < harr[r] > harr[largest])
	{
		largest = r;
	}
	if(largest != i)
	{
		swap(&harr[i], &harr[largest]);
		max_heapify(largest);
	}
}

void maxHeap::delete_key(int i)
{
	decrease_key(i, INT_MAX);
	extract_max();
}

int main()
{
	maxHeap heap(10);
	heap.insert_key(10);
	heap.insert_key(100);
	heap.insert_key(120);
	heap.insert_key(73);
	heap.insert_key(99);
	heap.insert_key(15);
	heap.insert_key(2);
	heap.insert_key(34);
	heap.insert_key(69);
	heap.insert_key(19);
	cout << "Heap" << endl;
	for(int i = 0; i < heap.heapSize; i++)
	{
		cout << heap.harr[i] << endl;
	}

	heap.delete_key(8);
	cout << "Heap" << endl;
	for(int i = 0; i < heap.heapSize; i++)
	{
		cout << heap.harr[i] << endl;
	}
	return 0;
}
