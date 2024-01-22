#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
bool helper(BinaryTreeNode<int>*root,int a){
    if(root->data==a){
        return true;
    }
    if(root==NULL){
        return false;
    }
    else{
        bool ans1=false;
        bool ans2=false;
        if(root->left!=NULL){
            ans1=helper(root->left,a);
        }
        if(root->right!=NULL){
            ans2=helper(root->right,a);
        }
        return ans1 or ans2;
    }
}
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(helper(root,a)!=true and helper(root,b)!=true){
        return -1;
    }
    if(root==NULL){
        return -1;
    }
    if(root->data==a or root->data==b){
        int check1=false;
        int check2=false;
        int check3=false;
        int check4=false;
        if(root->data==a){
            check1=helper(root->left,b);
            check2=helper(root->right,b);
        }
        else{
            check3=helper(root->left,a);
            check4=helper(root->right,a);
        }
        if(check1==true or check2==true or check3==true or check4==true){
            return root->data;
        }
    }
    bool check1=false;
    bool check2=false;
    bool check3=false;
    bool check4=false;
    if(root->left!=NULL){
        check1=helper(root->left,a);
        check2=helper(root->left,b);
    }
    if(root->right!=NULL){
        check3=helper(root->right,a);
        check4=helper(root->right,b);
    }
    if((check1 or check2) and (check3 or check4)){
        return root->data;
    }
    if((check1 and check2) or (check3 and check4)){
        if(check1==true){
            root=root->left;
            int ans=getLCA(root,a,b);
            return ans;
        }
        else{
            root=root->right;
            int ans=getLCA(root,a,b);
            return ans;
        }
    }
    return -1;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    else{
        int ans=1;
        int left=height(root->left);
        int right=height(root->right);
        int h=ans+max(left,right);
        return h;
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int h=height(root);
    cout<<h<<endl;
    // int a, b;
    // cin >> a >> b;
    // cout<<helper(root,11)<<endl;
    // cout<<helper(root,12)<<endl;
    // cout<<helper(root,13)<<endl;
    // cout<<helper(root,14)<<endl;
    // cout<<helper(root,15)<<endl;
    // cout << getLCA(root, a, b);
    delete root;
}