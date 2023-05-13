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

int heightofbst(Node *root){
	if(root==NULL)
		return 0;
	int l=heightofbst(root->left);
	int r=heightofbst(root->right);
	int max=l>r?l:r;
	return max+1;
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
		 cout<<"Height of BST is: "<<endl;
		 cout<<heightofbst(root);
		 return 0;
}
