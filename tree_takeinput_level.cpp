#include<iostream>
using namespace std;
#include"TreeNode.h"
#include<queue>

TreeNode<int>* takeInputlevelwise(){
    int rootData;
    cout<<"Enter RootData->"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no. of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int numNodes(TreeNode<int>*root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root){
    if(root->children.size()==0){
        return root->data;
    }
    int ans=0;
    ans+=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=sumOfNodes(root->children[i]);
    }
    return ans;
}

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size()==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=getLeafNodeCount(root->children[i]);
    }
    return ans;
}

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size()==0){
        return 1;
    }
    int max=0;
    int best=0;
    for(int i=0;i<root->children.size();i++){
        best=getHeight(root->children[i]);
        if(best>max){
            max=best;
        }
    }
    return max+1;
}

void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size()==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printPostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

TreeNode<int>*maxDataNode(TreeNode<int>* root){
    if(root->children.size()==0){
        return root;
    }
    int curr=root->data;
    int max=curr;
    TreeNode<int>* root1=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* best=maxDataNode(root->children[i]);
        if(best->data>max){
            root1=best;
        }
    }
    return root1;
}

TreeNode<int>* takeInput1(){
    int rootData;
    cout<<"Give RootData->"<<endl;
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    int n;
    cout<<"Give no. of Children->"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>*child=takeInput1();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    } 
}

void preorder(TreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void deleteTree(TreeNode<int>*root){
    for(int i==0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main(){
    TreeNode<int>*root=takeInputlevelwise();
    printTree(root);
    cout<<numNodes(root)<<endl;
    return 0;
}