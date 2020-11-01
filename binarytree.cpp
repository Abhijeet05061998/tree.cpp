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
	cout<<"Enter the rootdata :";
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
		cout<<"Enter the left child of "<<frontElement->data<<":";
		cin>>leftchild;
		if(leftchild!=-1)
		{
			Node*child=new Node(leftchild);
			frontElement->left=child;
			pendingnode.push(child);
		}
		int rightchild;
		cout<<"Enter the right child of "<<frontElement->data<<":";
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
		return 0;
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

int main()
{
	Node*root=takeinput();
	print(root);
}