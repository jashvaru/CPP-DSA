/*The Dot(.) operator is used to normally access members of a structure or union. 
The Arrow(->) operator exists to access the members of the structure or the unions using pointers.*/

#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

int append(Node **headRef, int newData); //adds new node at the end of the list
int node_count(Node *ptr); //displays elements and count nodes
int search_data(Node *ptr, int data); //displays at which node data is stored
int delete_node(Node **headRef, int delData); //delete the node at which the specific data is stored

int main()
{
	Node *head = NULL;

	node_count(head);

	append(&head, 10);
	append(&head, 11);
	append(&head, 12);
	append(&head, 13);
	append(&head, 14);

	node_count(head);
	search_data(head, 13);
	delete_node(&head, 10);
	node_count(head);
	delete_node(&head, 15);
	delete_node(&head, 14);
	node_count(head);
	search_data(head,14);
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

int node_count(Node *ptr)
{
	int count = 0;
	if(ptr == NULL) //check if list is empty
	{
		cout << "The list is empty" << endl; 
		return 0;
	}

	cout << "Data in the list is as follows" << endl;
	while(ptr != NULL) //count until last node
	{
		count++;
		cout << ptr->data << endl;
		ptr = ptr->next; 
	}
	cout <<"node Count = " << count << endl;
	cout << endl;
	return 0;
}

int search_data(Node *ptr, int data)
{
	int count = 0;
	while(ptr != NULL)
	{
		count++;
		if(ptr->data == data)
		{
			cout << "data = " << data << " is at node " << count << endl; //if data matches then print node number
			cout << endl;
			return 0;
		}
		ptr = ptr->next;
	}
	cout << "data = " << data << " not fount 404 error" << endl;
	cout << endl;
	return 0;
}

int delete_node(Node **headRef, int delData)
{
	Node *temp = *headRef;
	Node *prev; 

	if(temp != NULL && temp->data == delData) //if 
	{
		*headRef = temp->next;
		delete temp;//deleting node
		return 0;
	}

	while(temp != NULL)
	{
		if(temp->data == delData)
		{
			prev->next = temp->next; //connecting the node before and the node after of the node that is deleted
			delete temp;
			return 0;
		}
		else
		{
			prev = temp;//keeping the track of previous node
			temp = temp->next;
		}
	}

	cout << "data = " << delData << " not found 404 error" << endl;
	cout << endl;
	return 0;
}


