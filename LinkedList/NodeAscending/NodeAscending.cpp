#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

int append(Node **headRef, int newData); //adds new node at the end of the list
int node_print_data(Node *ptr); // prints data of node in binary
int sort_ascend(Node *ptr); // sorts data in ascending order
int del_duplicate(Node *ptr); //delete duplicate data from the list
int dec_to_bin(int num); 

int main()
{
	Node *head = NULL;
	int length;
	int userData;
	cout << "Enter length of the list you want to create" << endl;
	cin >> length;

	cout << "Enter data to be stored" << endl;
	for(int i = 0; i < length; i++)
	{
		cin >> userData;
		append(&head, userData);
	}
	cout << endl;
	sort_ascend(head);
	node_print_data(head);

    return 0;
}

int append(Node **headRef, int newData)
{
	Node *newNode = new Node(); //creating new node
	Node *temp = *headRef;		//temp ptr
	newNode->data = newData;   //assigning data
	newNode->next = NULL;	   //append new node at the end of the list, it will point at null 

	if(*headRef == NULL) //it will check at the head address, if its empty save address of new node at head ptr
	{
		*headRef = newNode;
		return 0;
	}

	while(temp->next != NULL) //traverse at the last node 
	{
		temp = temp->next;
	}

	temp->next = newNode; //appending new node to the list 
	return 0;
}

int node_print_data(Node *ptr)
{
	int count = 0;
	if(ptr == NULL) //check if list is empty
	{
		cout << "NULL" << endl; 
	}

	cout << "Data in list" << endl;
	while(ptr != NULL) //count until last node
	{
		count++;
		cout << ptr->data << " = ";
		dec_to_bin(ptr->data);
		cout << endl;
		ptr = ptr->next; 
	}
	return 0;
}

int sort_ascend(Node *ptr)
{
	Node *current = ptr; //track of current node
	Node *index = NULL;	 //track of diff node to compare with
	int temp;

	if(ptr == NULL)
	{
		cout << "The list is empty" << endl;
		return 0;
	}
	else
	{
		while(current != NULL) //until last node of the list
		{
			index = current->next;//comparision will start from current node and node next to it;
			while(index != NULL)
			{
				if(index->data < current->data)//if current node data is greater than the other node we are comparing with, do swap 
				{
					temp = index->data;
					index->data = current->data;
					current->data = temp;
				}
				index = index->next; //move to next node //exit if last node is reached
			}
			current = current->next;//change current node after each full comparision
		}
		del_duplicate(ptr);
		return 0;
	}
}

int del_duplicate(Node *ptr)
{
	Node *current = ptr; //keep track of current node
	Node *adjNode = NULL; // next node

	if(ptr == NULL) // no node
	{
		cout << "The list is empty" << endl;
		return 0;
	}
	else
	{
		while(current != NULL) //until last node of the list
		{
			adjNode = current->next;//assigning next node
			if(adjNode == NULL)// if there is only one node in the list then next will be null and no comparison
			{
				return 0;
			}

			if(current->data == adjNode->data)//compare data
			{
				current->next = adjNode->next;
				delete adjNode;
			}
			else
			{
				current = current->next;//move to next node //if current points to null exit while loop
			}
		}
	}
}

int dec_to_bin(int num)
{
    if (num == 0)
    {
        return 0;
    }

    dec_to_bin(num / 2); // recursion is used.
    cout << (num % 2);
}

