#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	Node *prev;
};

int push_ending(Node **headRef, int newData);
int push_begining(Node **headRef, int newData);
int traversal(Node *headPtr);


int main()
{
	Node *head = NULL;
	push_ending(&head, 1);
	push_ending(&head, 2);
	push_ending(&head, 3);
	traversal(head);
	push_begining(&head, 8);
	push_begining(&head, 9);
	traversal(head);

    return 0;
}

int push_ending(Node **headRef, int newData)
{
	Node *newNode = new Node(); //create new node
	Node *temp = *headRef;
	newNode->data = newData; //add data
	newNode->next = NULL;	//as it is last node in the list next field will be null

	if(*headRef == NULL)
	{
		newNode->prev = NULL; //for 1st node in the list prev field will be null
		*headRef = newNode;
		return 0;
	}

	while(temp->next != NULL) //traverse till last node
	{
		temp = temp->next;
	}

	temp->next = newNode; //connect new node with the last node of list
	newNode->prev = temp; //connect prev field too 	
}

int push_begining(Node **headRef, int newData)
{
	Node *newNode = new Node(); //create new node
	Node *temp = *headRef;
	newNode->data = newData;//add data
	newNode->prev = NULL; //as it is first node in the list prev field will be null

	if(*headRef == NULL)
	{
		newNode->next = NULL; //for 1st node in the list next field will be null
		*headRef = newNode;
	}
	else
	{
		temp->prev = newNode; //connect new node with first node of the list
		newNode->next = temp; 
		*headRef = newNode; //making newly added node as head
	}
	return 0;
}

void insert_after(Node *prevPtr, int newData)
{
	
}

int traversal(Node *temp)
{
	Node *last;

	if(temp == NULL)
	{
		cout << "List is empty" << endl;
		return 0;
	}

	cout << "Forward traversing" << endl;
	while(temp != NULL)
	{
		cout << temp->data << " ";
		last = temp;
		temp = temp->next;
	}
	cout << endl;

	cout << "Reverse traversing" << endl;
	while(last != NULL)
	{
			cout << last->data << " ";
			last = last->prev;
	}
	cout << endl;
}


