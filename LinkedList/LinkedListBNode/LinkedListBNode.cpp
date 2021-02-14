#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

int traverse(Node *ptr);
int reverse(Node *ptr);
Node *push_begining(Node **headAddress,int newData);

int main()
{
	Node *head = NULL;
	push_begining(&head,1);
	push_begining(&head, 10);
	push_begining(&head, 45);
	push_begining(&head, 66);
	push_begining(&head, 78);
	traverse(head);
	reverse(head);
}

Node *push_begining(Node **headAddress,int newData)//every new node will be pushed at the beginning of the linked list
{
	//At address of headptr we have stored a pointer to the node
	Node *newNode = new Node();
	newNode->data = newData;
	newNode->next = *headAddress;//as headptr contains ptr of 1st node we store it in next field of new node so they can be linked together
	*headAddress = newNode; //and making newly created node as head node
}

int traverse(Node *ptr)
{
	if(ptr == NULL)
	{
		cout << "NULL" << endl; 
	}

	while(ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->next; 
	}
	cout << endl;
	return 0;
}

int reverse(Node *ptr)
{
	if(ptr == NULL)//going towards the last node
	{
		return 0;
	}

	reverse(ptr->next);//printing data while tracing back using recusive function
	cout << ptr->data << " ";
}









