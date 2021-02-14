#include <iostream>
#include <queue>

using namespace std;

class Node
{
	public:
		int data;
		Node *left;
		Node *right;
};

Node *newNode(int newData);
int inorder(Node *tempNode);
int insertNode(Node *tempNode, int newData);
int mirrorTree(Node *tempNode);

int main()
{
    Node *root = newNode(1);
    insertNode(root,2);
    insertNode(root,3);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,6);
    cout << "Tree" << endl;
    inorder(root);
    cout << endl;
    cout << "MirrorTree" << endl;
    mirrorTree(root);
    inorder(root);
    cout << endl;
    return 0;
}

Node *newNode(int newData)
{
	Node *node = new Node();
	node->data = newData;

	node->left = NULL;
	node->right = NULL;

	return node;
}

int inorder(Node *tempNode) //format leftNode data, rootNode data & right Node data
{
	if(tempNode == NULL)
	{
		return 0;
	}
	
	inorder(tempNode->left);
	cout << tempNode->data << endl;
	inorder(tempNode->right);
}

int insertNode(Node *tempNode, int newData) // search if there is leftmost child empty on the same level and insert newNode, if not check right and insert new node
{
	queue<Node*> q;
	q.push(tempNode);

	while(!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if(!temp->left)
		{
			temp->left = newNode(newData);
			break;
		}
		else
		{
			q.push(temp->left);
		}

		if(!temp->right)
		{
			temp->right = newNode(newData);
			break;
		}
		else
		{
			q.push(temp->right);
		}
	}
}

int mirrorTree(Node *tempNode) //swap the childs of each parent node
{
	if(tempNode == NULL)
	{
		return 0;
	}
	else
	{
		Node *temp = NULL;
		mirrorTree(tempNode->left);
		mirrorTree(tempNode->right);

		//swapping
		temp = tempNode->left;
		tempNode->left = tempNode->right;
		tempNode->right = temp;
	}
}