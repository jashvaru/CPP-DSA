#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
	public:
		int data;
		Node *left;
		Node *right;
};

Node *newNode(int newData);
int inorder(Node *rootNode);
int insertNode(Node *rootNode, int newData);
Node *convertToBST(Node *rootNode);
int storeInorder(Node *tempNode , vector<int> &v);
Node *BST_insert_node(Node *temp, int nodeData);


int main()
{
    Node *root = newNode(99);
    insertNode(root, 8);
    insertNode(root, 45);
    insertNode(root, 32);
    insertNode(root, 69);
    insertNode(root, 1);
    insertNode(root, 200);
    insertNode(root, 100);
    cout << "BT inorder Output" << endl;
    inorder(root);
    cout << endl;

	cout << "BST inorder Output" << endl;
    Node *rootBST = convertToBST(root);
    inorder(rootBST);
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

int inorder(Node *rootNode)//format leftNode data, rootNode data & right Node data
{
	if(rootNode == NULL)
	{
		return 0;
	}
	inorder(rootNode->left);
	cout << rootNode->data << " ";
	inorder(rootNode->right);
}

int insertNode(Node *rootNode, int newData)
{
	queue<Node*> q;
	q.push(rootNode);

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

Node *BST_insert_node(Node *temp, int nodeData)
{
	if(temp == NULL)
	{
		return newNode(nodeData);
	}

	if(nodeData < temp->data)
	{
		temp->left = BST_insert_node(temp->left, nodeData);
	}
	else if(nodeData > temp->data)
	{
		temp->right = BST_insert_node(temp->right, nodeData);
	}
	return temp;
}

Node *convertToBST(Node *rootNode)
{
	vector<int> vec;
	storeInorder(rootNode, vec);

	Node *tempBST = newNode(vec.at(0));
	for(int i = 1; i < vec.size(); i++)
	{
		BST_insert_node(tempBST, vec.at(i));
	}

	return tempBST;
}

int storeInorder(Node *tempNode , vector<int> &v)//format leftNode data, rootNode data & right Node data
{
	if(tempNode == NULL)
	{
		return 0;
	}

	storeInorder(tempNode->left, v);
	v.push_back(tempNode->data);
	storeInorder(tempNode->right, v);
}