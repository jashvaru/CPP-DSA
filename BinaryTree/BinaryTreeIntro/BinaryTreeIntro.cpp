#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *right;
	Node *left;
};

Node *newNode(int newData);
int inorder(Node *tempNode);
int treeSize(Node *rootNode);
int addAllElmn(Node* rootNode);


int main()
{
	Node *root = newNode(1);
	/* following is the tree after above statement  
  
        1 
  	   / \ 
     NULL NULL  
	*/

	root->left = newNode(2);
	root->right = newNode(3);
	/* 2 and 3 become left and right children of 1 
         1 
        / \ 
       2   3 
      / \ / \ 
    NULL NULL NULL NULL 
	*/

	root->left->left = newNode(4);
	/* 4 becomes left child of 2 
           1 
    	/    \ 
      2         3 
     / \       / \ 
    4  NULL   NULL NULL 
   / \ 
NULL NULL 
*/
	root->left->right = newNode(5);
	inorder(root);
	cout << "Size of tree is " << treeSize(root) << endl;
	cout << "Sum of all elements is " << addAllElmn(root);

    return 0;
}

Node *newNode(int newData) //create new node with null childs
{
	Node *node = new Node();
	node->data = newData;

	node->left = NULL;
	node->right = NULL;

	return node;
}

int inorder(Node *tempNode)//format leftNode data, rootNode data & right Node data
{
	if(tempNode == NULL)
	{
		return 0;
	}

	inorder(tempNode->left);

	cout << tempNode->data << endl;

	inorder(tempNode->right);
}

int treeSize(Node *rootNode)  
{  
    if(rootNode == NULL)
    {
        return 0;  
    }  
    else
    {
        return(treeSize(rootNode->left) + 1 + treeSize(rootNode->right));  
    }
} 

int addAllElmn(Node* rootNode) 
{ 
    if(rootNode == NULL)
    {
        return 0; 
    } 
    else
    {
	    return (rootNode->data + addAllElmn(rootNode->left) + addAllElmn(rootNode->right)); 
    }
} 
