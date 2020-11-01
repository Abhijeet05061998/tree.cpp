#include<bits/stdc++.h>
using namespace std;

class Node{
public:

	int data;
	Node*left;
	Node*right;

	Node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

Node*takeinput()
{
	int rootdata;
	cout<<"Enter the rootdata :"<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	Node*root=new Node(rootdata);
	queue<Node*>pendingnode;
	pendingnode.push(root);

	while(pendingnode.size()!=0)
	{
		Node*frontElement=pendingnode.front();
		pendingnode.pop();
		int leftchild;
		cout<<"Enter the left child of "<<frontElement->data<<":"<<endl;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			Node*child=new Node(leftchild);
			frontElement->left=child;
			pendingnode.push(child);
		}
		int rightchild;
		cout<<"Enter the right child of "<<frontElement->data<<":"<<endl;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			Node*child=new Node(rightchild);
			frontElement->right=child;
			pendingnode.push(child);
		}
	}
	return root;
}
void print(Node*root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL)
	{
         cout<<"L"<<root->left->data;
	}
	if(root->right!=NULL)
	{
		cout<<"R"<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}

int inorder(Node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int preorder(Node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int postorder(Node*root)
{
	if(root==NULL)
	{
		return 0;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}


int main()
{
	Node*root=takeinput();
	//print(root);
	cout<<"inorder Traversal:";
	inorder(root);
	cout<<endl;
	cout<<"preorder Traversal:";
	preorder(root);
	cout<<endl;
	cout<<"postorder Traversal :";
	postorder(root);
}
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1