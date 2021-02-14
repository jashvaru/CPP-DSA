#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next; // next is a pointer to class
};

int traverse(Node *ptr);

int main()
{
	//Creating three null pointer of Data type Node
	Node *head = NULL;
	Node *second = NULL;
	Node *third = NULL;

	//Alocating three nodes into the heap
	head = new Node(); //new keyword works like this new int()   //creating a 3 object dynamically on heap memory for node class
	second = new Node();
	third = new Node();

	cout << "address of head node" << &head << endl;
	cout << "address of second node" << &second << endl;
	cout << "address of third node" << &third << endl;

	//Assigning data and linking the nodes
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	traverse(head);

    return 0;
}

int traverse(Node *ptr)
{
	while(ptr != NULL)
	{
		cout << "Data in " << ptr->data << endl; //print the data field of the node until NULL is detected
		ptr = ptr->next; 
	}
	return 0;
}



