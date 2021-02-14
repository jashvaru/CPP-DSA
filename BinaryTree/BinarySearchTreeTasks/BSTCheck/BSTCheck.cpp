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
int inorder(Node *rootNode);
int checkBST(Node *rootNode);
int storeInorder(Node *tempNode , vector<int> &vec);

int main()
{
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if(checkBST(root))
    {
    	cout << "It is a BST" << endl;
    }
    else
    {
    	cout << "It is a not BST" << endl;
    }
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
	cout << rootNode->data << endl;
	inorder(rootNode->right);
}

int checkBST(Node *rootNode)
{
	vector<int> vec;
	storeInorder(rootNode, vec);
	for(int i = 0; i < vec.size()-1; i++)
	{
		if(vec.at(i) > vec.at(i+1))
		{
			return 0;
		}
	}

	return 1;
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




