#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
    }
};
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        inorder(root->left);
    }
    cout<<root->val<<" ";
    if(root->right!=NULL){
        inorder(root->right);
    }
}
Node* func(int arr[],int st,int end){
    if(st<=end){
        int mid=(st+end)/2;
        Node* node=new Node(arr[mid]);
        node->left=func(arr,st,mid-1);
        node->right=func(arr,mid+1,end);
        return node;
    }
    else{
        return NULL;
    }
}
int main(){
    int arr[7];
    for(int i=0;i<7;i++){
        arr[i]=i+1;
    }
    Node* ans=func(arr,0,6);
    inorder(ans);
    cout<<endl;
    return 0;
}
// /**********************************************************

// 	Following is the Binary Tree Node class structure

// 	template <typename T>
// 	class BinaryTreeNode {
//     	public : 
//     	T data;
//     	BinaryTreeNode<T> *left;
//     	BinaryTreeNode<T> *right;

//     	BinaryTreeNode(T data) {
//         	this -> data = data;
//         	left = NULL;
//         	right = NULL;
//     	}
// 	};

// ***********************************************************/

// // BinaryTreeNode<int>* constructTree(int *input, int n) {
// // 	// Write your code here
// //     if(n==0){
// //         return NULL;
// //     }
// //     int mid=0;
// //     if(n%2!=0){
// //         mid=n/2;
// //     }
// //     else{
// //         mid=n/2;
// //         mid=mid-1;
// //     }
// //     BinaryTreeNode<int>*root=new BinaryTreeNode<int>(input[mid]);
// //     root->left=constructTree(input,mid);
// //     root->right=constructTree(input+mid+1,n-mid-1);
// //     return root;
// // }

// /**********************************************************

// 	Following are the Binary Tree Node class structure and the 
// 	Node class structure

// 	template <typename T>
// 	class BinaryTreeNode {
//     	public: 
//     	T data;
//     	BinaryTreeNode<T> *left;
//     	BinaryTreeNode<T> *right;

//     	BinaryTreeNode(T data) {
//         	this->data = data;
//         	left = NULL;
//         	right = NULL;
//     	}
// 	};

// 	template <typename T>
//  	class Node{
//     	public:
//     	T data;
//     	Node<T> *next;
    
//     	Node(T data) {
//         	this->data = data;
//         	this->next = NULL;
//     	}
//  	};

// ***********************************************************/
// void helper(BinaryTreeNode<int> *root,vector<int>&v){
//     if(root==NULL){
//         return;
//     }
//     if(root->left!=NULL){
//         helper(root->left,v);
//     }
//     v.push_back(root->data);
//     if(root->right!=NULL){
//         helper(root->right,v);
//     }
    
// }
// Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
// 	// Write your code here
//     vector<int>v;
//     helper(root,v);
//     if(v.size()==0){
//         return NULL;
//     }
//     Node<int>*head=new Node<int>(v[0]);
//     Node<int>*temp=head;
    
//     for(int i=1;i<v.size();i++){
//         temp->next=new Node<int>(v[i]);
//         temp=temp->next;
//     }
//     return head;
// }

