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
	vector<vector<int>>v;
	if(root==NULL)
	{
		return v;
	}
	queue<Node*>q;
	q.push(root);
	while(q.size()!=0)
	{
		vector<int>vec;
		int x=q.size();
		for(int i=0;i<x;i++)
		{
			Node*curr=q.front();
			q.pop();
			vec.push_back(curr->data);
			if(curr->left!=NULL)
			{
				vec.push_back(curr->left);
			}
			if(curr->right!=NULL)
			{
				vec.push_back(curr->right);
			}
		}
	}
	v.push_back(vec);
	reverse(v.begin(),v.end());
}
int main()
{
	Node*root=takeinput();
	print(root);
}