#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

int push_ending(Node **lastRef, int newData);
int traverse(Node *lastNode);
int check(Node *ptr);

int main()
{
	Node *last = NULL;
	push_ending(&last, 1);
	push_ending(&last, 2);
	push_ending(&last, 5);
	traverse(last);
	check(last);
    return 0;
}

int push_ending(Node **lastRef, int newData)
{
	Node *newNode = new Node();
	newNode->data = newData;
	Node *lastNode = *lastRef;

	if(*lastRef == NULL)
	{
		newNode->next = newNode;
		*lastRef = newNode;
		return 0;
	}

	newNode->next = lastNode->next;
	lastNode->next = newNode;
	*lastRef = newNode;
	return 0;
}

int traverse(Node *lastNode)
{
	Node *temp = lastNode->next;

	do
	{
		cout << temp->data << " ";
		temp = temp->next;
	}while(temp != lastNode->next);
	cout << endl;
	return 0;
}

int check(Node *ptr)
{
	Node *temp = ptr;

	while(true)
	{
		temp = temp->next;
		if(temp->next == NULL)
		{
			cout << "it is not circular" << endl;
			break;
		}
		else if(temp->next == ptr)
		{
			cout << "It is circular" << endl;
			break;
		}
	}
	return 0;
}
