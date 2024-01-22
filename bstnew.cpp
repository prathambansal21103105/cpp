#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

class BST{
    public:
    Node *root;
    BST(){
        root=NULL;
    }
    Node* insert(int data1, Node* root){
        if(root==NULL){
            Node* newnode= new Node;
            newnode->data=data1;
            root=newnode;
            return root;
        }
        if(data1<=root->data){
            root->left=insert(data1,root->left);
        }
        if(data1>root->data){
            root->right=insert(data1,root->right);
        }
        return root;
    }
    Node* delete1(int data1, Node* root){
        if(root==NULL){
            return root;
        }
        else if(root->data==data1){
            if(root->left==NULL and root->right==NULL){
                return NULL;
            }   
            else if(root->left==NULL and root->right!=NULL){
                return root->right;
            }
            else if(root->right==NULL and root->left!=NULL){
                return root->left;
            }
            else{
                Node* newnode=root->left;
                while(newnode->right!=NULL){
                    newnode=newnode->right;
                }
                root->data=newnode->data;
                root->left=delete1(newnode->data,root->left);
                return root;
            }
        }
        else if(data1<root->data){
            root->left=delete1(data1,root->left);
            return root;
        }
        else if(data1>root->data){
            root->right=delete1(data1,root->right);
            return root;
        }
        else{
            return root;
        }
    }
    bool search(Node*root, int data1){
        if(root==NULL){
            return false;
        }
        else if(root->data==data1){
            return true;
        }
        else if(root->data<data1){
            return search(root->right,data1);
        }
        else{
            return search(root->left,data1);
        }
    }
    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        if(root->left!=NULL){
            preorder(root->left);
        }
        if(root->right!=NULL){
            preorder(root->right);
        }
    }
    void postorder(Node* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            postorder(root->left);
        }
        if(root->right!=NULL){
            postorder(root->right);
        }
        cout<<root->data<<" ";
    }
    void inorder(Node*root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            inorder(root->left);
        }
        cout<<root->data<<" ";
        if(root->right!=NULL){
            inorder(root->right);
        }
    }
    void add(int data1){
        root=insert(data1, root);
    }
    void remove(int data1){
        root=delete1(data1, root);
    }
    void in(){
        inorder(root);
        cout<<endl;
    }
    void pre(){
        preorder(root);
        cout<<endl;
    }
    void post(){
        postorder(root);
        cout<<endl;
    }
    void check(int data1){
        if(search(root,data1)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
};

int main()
{
    BST* b=new BST();
    b->add(1);
    b->add(0);
    b->add(2);
    b->add(3);
    b->add(-1);
    b->check(3);
    b->check(2);
    b->check(13);
    b->in();
    b->pre();
    b->post();
    b->remove(1);
    b->in();
    b->pre();
    b->post();

    return 0;
}