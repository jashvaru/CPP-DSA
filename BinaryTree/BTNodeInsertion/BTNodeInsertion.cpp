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
Node *deleteNode(Node *rootNode, int delData);
int deleteDeepest(Node *root, Node *delNode);


int main()
{
    Node *root = newNode(1);
    insertNode(root, 2);
    insertNode(root, 3);
    inorder(root);
    cout << endl;

    Node *trial = root->right;
    root = deleteNode(root,2);
    inorder(root);
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

int insertNode(Node *tempNode, int newData)
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

//deleted node will be replace by the right most and deepest node!
Node *deleteNode(Node *rootNode, int delData)
{
	if(rootNode == NULL)
	{
        return NULL; 
	} 
  
    if(rootNode->left == NULL && rootNode->right == NULL) //is tree have only one node
    { 
        if(rootNode->data == delData) //and del data matches rootNode node return NULL
        {
            return NULL; 
        } 
        else
        {
            return rootNode;//if does not matches return the node itself
        }
    }

    queue<Node*> q;
    q.push(rootNode);

    Node *temp; //to store the rightmost and deepest node
    Node *keyNode = NULL; // to store address of node to be deleted

    while(!q.empty())
    {
    	temp = q.front();
    	q.pop();

    	if(temp->data == delData)
    	{
    		keyNode = temp;
    	}

    	if(temp->left)
    	{
            q.push(temp->left); 
    	} 
  
        if(temp->right)
        {
            q.push(temp->right); 
        } 
    }

    if(keyNode != NULL)
    {
    	int x = temp->data; // save data of right most node
    	deleteDeepest(rootNode, temp);// delete and make the parent's node right pointer NULL
    	keyNode->data = x;
    }

    return rootNode;
}

int deleteDeepest(Node *root, Node *delNode)
{
	queue<Node*> q;
	q.push(root);

	Node *temp;

	while(!q.empty())
	{
		temp = q.front();
		q.pop();

		if(temp == delNode)
		{
			temp = NULL;
			delete(delNode);
			return 0;
		}

		if(temp->right)
		{
			if(temp->right == delNode)
			{
				temp->right = NULL;
				delete(delNode);
				return 0;
			}
			else
			{
				q.push(temp->right);
			}
		}

		if(temp->left)
		{
			if(temp->left == delNode)
			{
				temp->left = NULL;
				delete(delNode);
				return 0;
			}
			else
			{
				q.push(temp->left);
			}
		}
	}
}
