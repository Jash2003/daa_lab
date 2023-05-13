#include<iostream>
using namespace std;


class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};


int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}


int max(int a, int b)
{
	return (a > b)? a : b;
}


Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
					
	return(node);
}


Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	
	x->right = y;
	y->left = T2;


	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;


	return x;
}


Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	
	y->left = x;
	x->right = T2;

	
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	
	return y;
}


int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
	
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left),
						height(node->right));

	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	
	return node;
}


void InOrder(Node *root)
{
	if(root != NULL)
	{
		InOrder(root->left);
		cout << root->key << " ";
		InOrder(root->right);
	}
}


int main()
{
    int n;
    cout<<"Enter the number of nodes to push: "<<endl;
    cin>>n;
	Node *root = NULL;
    while(n--){
        int data;
        cout<<"Enter data: "<<endl;
        cin>>data;
        root=insert(root,data);
    }

	cout << "Inorder traversal of the constructed AVL tree is : "<<endl;
	InOrder(root);
	
	return 0;
}
