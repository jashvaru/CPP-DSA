/*
A Binary Heap is a Binary Tree with following properties.
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as
left as possible). This property of Binary Heap makes them suitable to be stored in an array.
2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present
in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int *data1, int *data2);

class minHeap
{
	public:
		int *harr;
		int capacity;
		int heapSize;
		minHeap(int capacity);

		int parent(int i) { return ((i-1)/2); } //give the parent node index using child node index
		int left(int i) { return ((i*2) + 1);} //gives left and right child inde from parent node
		int right(int i) { return ((i*2) + 2);}

		void insert_key(int key);
		void delete_key(int i);

		void decrease_key(int i, int newVal);
		int extract_min();
		void min_heapify(int i);
};

minHeap::minHeap(int cap) //constructor that creates an empty array of required size
{
	heapSize = 0;
	capacity = cap;
	harr = new int[cap];
}

void minHeap::insert_key(int key) //insert new value at the end of heap and then take it one level higher if it is less then parent node in a subtree
{
	if(heapSize == capacity)
	{
		cout << "Overflow could not insert key" << endl;
		return;
	}
	heapSize++; // current elements in the heap
	int i = heapSize - 1;
	harr[i] = key; //adding new value toh the last position

	while(i != 0 && harr[parent(i)] > harr[i])
	{
		swap(&harr[i], &harr[parent(i)]);
		i = parent(i);
	}
	return;
}

void minHeap::decrease_key(int i, int newVal) //change a value at given index and also follow rules for min heap
{
	harr[i] = newVal;
	while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

int minHeap::extract_min() //returns and deletes the top most node and also rearragnge the heap as per rules
{
	if(heapSize <= 0)
	{
        return INT_MAX;
	}
    if(heapSize == 1)
    {
        heapSize--;
        return harr[0];
    }

	int root = harr[0];
	harr[0] = harr[heapSize-1];
	heapSize--;
	min_heapify(0);

	return root;
}

void minHeap::min_heapify(int i) //check each sub tree as per rules of min heap
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heapSize && harr[l] < harr[i])
	{
		smallest = l;
	}
	if(r < heapSize && harr[r] < harr[smallest])
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		min_heapify(smallest);
	}
}

void minHeap::delete_key(int i)
{
	decrease_key(i, INT_MIN);
	extract_min();
}

void swap(int *data1, int *data2)
{
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}


int main()
{
   minHeap heap(10);
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


