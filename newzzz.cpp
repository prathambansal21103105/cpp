#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#include"binary_tree_node_class.cpp"
void noofnodes(BinaryTreeNode<int>*node,int *count){
    if(node==NULL){
        return;
    }
    (*count)++;
    noofnodes(node->left,count);
    noofnodes(node->right,count);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root==NULL){
        return;

    }
    int *count =new int;
    *count =0;
    BinaryTreeNode<int>*temp =root;
    
    noofnodes(temp,count);
    stack<BinaryTreeNode<int>*>small;
    stack<BinaryTreeNode<int>*>large;
    temp=root;
    BinaryTreeNode<int>*temp2=root;
    while(temp!=NULL){
        small.push(temp);
        temp=temp->left;
    }
    while(temp!=NULL){
        large.push(temp);
        temp=temp->right;
    }
    int i=0;
    // cout<<*count<<endl;
    while(i<*count and large.size()!=0 and small.size()!=0){

        if(large.top()==small.top()){
            break;
        }
        if(small.top()->data+large.top()->data==s){
            cout<<small.top()->data<<" "<<large.top()->data<<endl;
            temp =small.top()->right;
            temp2 =large.top()->left;
            small.pop();
            i++;
            large.pop();
            i++;
            while(temp!=NULL){
                small.push(temp);
                temp =temp->left;
            }
            while(temp2!=NULL){
                large.push(temp2);
                temp =temp->right;
            }
        }
        else if(small.top()->data+large.top()->data>s){
            if(large.top()->data>small.top()->data ){

            
            temp =large.top()->left;
            large.pop();
            i++;
            while(temp!=NULL){
                large.push(temp);
                temp=temp->right;
            }
            }
            else if(large.top()->data<small.top()->data){
                temp=small.top()->left;
                small.pop();
                i++;
                while(temp!=NULL){
                    small.push(temp);
                    temp=temp->left;
                }
            }
            else{
                temp =large.top()->left;
                large.pop();
                i++;
                while(temp!=NULL){
                    large.push(temp->right);
                }
            }
        }
        else if(small.top()->data+large.top()->data<s){
            if(small.top()->data<large.top()->data){
            temp =small.top()->right;
            small.pop();
            i++;
            while(temp!=NULL){
                small.push(temp);
                temp=temp->left;
            }
        }
        else{
            temp =large.top()->right;
            large.pop();
            i++;
            while(temp!=NULL){
                large.push(temp);
                temp=temp->right;
            }
        }
        }
    }

}
BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    int *count=new int;
    *count =0;
    // noofnodes(root,count); 
    // cout<<*count;
    printNodesSumToS(root, s);
    delete root;
}