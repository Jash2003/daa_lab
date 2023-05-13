#include<iostream>
using namespace std;
struct Node{
 	int data;
	Node *left,*right;
};

Node* insert(Node *root,int data){
	Node *newnode=new Node;
	if(root==NULL){
	    newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		root=newnode;
		return root;
 }
	if(data<=root->data)
		root->left=insert(root->left,data);
	else
	 	root->right=insert(root->right,data);
	return root;
}

Node* constructBST(int arr[],int n){
	 if(n==0)
	 	return NULL;
	 Node *root=NULL;
	 for(int i=0;i<n;i++)
	 	root=insert(root,arr[i]);
	 return root;
}

void inorder(Node *root){
	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
}
}
void preorder(Node *root){
	if(root){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
}
}
void postorder(Node *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
}
}

	int main(){
		 cout<<"Enter N: ";
		 int n;
		 cin>>n;
		 int arr[n];
		 cout<<"Enter: "<<endl;
		 for(int i=0;i<n;i++)
		 	cin>>arr[i];
		 Node *root=constructBST(arr,n);
		 cout<<"Inorder traversal is: "<<endl;
		 inorder(root);
		 cout<<endl;
		 cout<<"postorder traversal is: "<<endl;
		 postorder(root);
		 cout<<endl;
		 cout<<"preorder traversal is: "<<endl;
		 preorder(root);
		 return 0;
}
