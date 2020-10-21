#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data)
    {
        this->data=data;
    }
};
TreeNode<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the rootdata:"<<endl;
    cin>>rootdata;
    TreeNode<int>*root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*>pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0)
    {
        TreeNode<int>*frontElement=pendingNode.front();
        pendingNode.pop();
        cout<<"Enter the no of children of"<<" "<<frontElement->data<<endl;
        int childnum;
        cin>>childnum;
        for(int i=0;i<childnum;i++)
        {
            int childdata;
            cout<<"Enter "<<i<<"th child of"<<" "<<frontElement->data<<endl;
            cin>>childdata;
            TreeNode<int>*child=new TreeNode<int>(childdata);
            frontElement->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;
}
void printNode(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    {
        printNode(root->children[i]);
    }
}
int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
    TreeNode<int>*root=takeinput();
    printNode(root);
}