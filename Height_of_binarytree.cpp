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
		return;
	}
	queue<Node*>q;
	q.push(root);
	q.push(NULL);

	while(q.size()!=0)
	{
		Node*curr=q.front();
		q.pop();
		if(cuur==NULL)
		{
			cout<<endl;
			q.push(NULL)
			continue;
		}
		cout<<curr->data;
		if(curr->left!=NULL)
		{
			q.push(curr->left);
		}
		if(curr->right!=NULL)
		{
			q.push(curr->right);
		}
	}
}

void height(Node*root)
{
	if(root==NULL)
	{
		return;
	}
	int l=height(root->left);
	int r=height(root->right);
	if(l>r)
	{
		return l+1;
	}
	else
	{
		return r+1;
	}

}

int main()
{
	Node*root=takeinput();
	print(root);
	cout<<height(root);
}