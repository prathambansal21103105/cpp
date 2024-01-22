#include<iostream>
#include<queue>
using namespace std;
#include"binary_tree_node_class.cpp"

void printTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

void inorder(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int numNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}
int minimum(BinaryTreeNode<int>*root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>*root){
    if(root==NULL){
        return true;
    }
    int leftMax=maximum(root->left);
    int rightMin=minimum(root->right);
    bool output=(root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
BinaryTreeNode<int>*takeInput1(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild=takeInput1();
    BinaryTreeNode<int>*rightChild=takeInput1();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

BinaryTreeNode<int>*takeInputLevelWise(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}
int height(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}
class IsBSTReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};
IsBSTReturn isBST2(BinaryTreeNode<int>*root){
    if(root==NULL){
        IsBSTReturn output;
        output.isBST=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput=isBST2(root->left);
    IsBSTReturn rightOutput=isBST2(root->right);
    int minimum=min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum=max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool isBSTFinal=(root->data > leftOutput.maximum) && (root->data<=rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;
    IsBSTReturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isBST=isBSTFinal;
    return output;
}
pair<int,int>heightDiameter(BinaryTreeNode<int>*root){
    if(root==NULL){
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftAns=heightDiameter(root->left);
    pair<int,int>rightAns=heightDiameter(root->right);
    int ld=leftAns.second;
    int lh=leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;
    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first=height;
    p.second=diameter;
    return p;
}
bool isBST3(BinaryTreeNode<int>*root,int min=INT_MIN,int max=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data<min || root->data>max){
        return false;
    }
    bool isLeftOk=isBST3(root->left,min,root->data-1);
    bool isRightOk=isBST3(root->right,root->data,max);
    return isLeftOk && isRightOk;
}
void printDepthK(BinaryTreeNode<int> *root,int k){
    if(k==0){
        cout<<root->data<<endl;
    }
    else{
        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        while(k>0){
            int s=q.size();
            while(s>0){
                BinaryTreeNode<int>*f=q.front();
                if(f->left!=NULL){
                    q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
                q.pop();
                s-=1;
            }
            while(!q.empty()){
                cout<<q.front()->data<<" ";
                q.pop();
            }
            cout<<endl;
            k-=1;
        }
    }
}
BinaryTreeNode<int>* findTarget(BinaryTreeNode<int>*root,int node){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    else{
        BinaryTreeNode<int>*l1=NULL;
        BinaryTreeNode<int>*l2=NULL;
        BinaryTreeNode<int>*targetNode=NULL;
        if(root->left!=NULL){
            l1=findTarget(root->left,node);
        }
        if(root->right!=NULL){
            l2=findTarget(root->right,node);
        }
        if(l1!=NULL){
            targetNode=l1;
        }
        else{
            targetNode=l2;
        }
        return targetNode;
    }
}
void findPath(BinaryTreeNode<int>*root,vector<int>&v,vector<vector<int> >&b,int target){
    if(root->data==target){
        v.push_back(root->data);
        b.push_back(v);
    }
    if(root->left!=NULL){
        v.push_back(root->data);
        findPath(root->left,v,b,target);
        v.pop_back();
    }
    if(root->right!=NULL){
        v.push_back(root->data);
        findPath(root->right,v,b,target);
        v.pop_back();
    }
}
int height1(BinaryTreeNode<int>*root,int p){
    if(root->data==p){
        return 1;
    }
    else{
        int ans=0;
        int h1=0;
        int h2=0;
        if(root->left!=NULL){
            h1=height1(root->left,p);
        }
        if(root->right!=NULL){
            h2=height1(root->right,p);
        }
        ans=max(h1,h2);
        if(ans!=0){
            ans+=1;
        }
        return ans;
    }
}
bool parentnode(BinaryTreeNode<int>*root,int p,int q){
    if(root==NULL){
        return false;
    }
    if(root->left!=NULL and root->right!=NULL){
    if((root->left->data==p and root->right->data==q) or (root->left->data==q and root->right->data==p) ){
        return true;
    }
    bool check1=false;
        bool check2=false;
        if(root->left!=NULL){
            check1=parentnode(root->left,p,q);
        }
        if(root->right!=NULL){
            check2=parentnode(root->right,p,q);
        }
        return false or check1 or check2;
    }
    else{
        bool check1=false;
        bool check2=false;
        if(root->left!=NULL){
            check1=parentnode(root->left,p,q);
        }
        if(root->right!=NULL){
            check2=parentnode(root->right,p,q);
        }
        return false or check1 or check2;
    }
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    // BinaryTreeNode<int>*root= new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>*node1= new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>*node2= new BinaryTreeNode<int>(3);
    // root->left=node1;
    // root->right=node2;
    // BinaryTreeNode<int>*root=takeInput1();
    BinaryTreeNode<int>*root=takeInputLevelWise();
    // cout<<height1(root,5)<<endl;
    // cout<<height1(root,6)<<endl;
    // cout<<height1(root,2)<<endl;
    // cout<<height1(root,4)<<endl;
    cout<<parentnode(root,2,3)<<endl;
    // vector<vector<int> >b;
    // vector<int>v,ans;
    // findPath(root,v,b,1);
    // ans=b[0];
    // printDepthK(root,1);
    // cout<<findTarget(root,8)->data<<endl;
    // cout<<findTarget(root,9)->data<<endl;
    // printTree(root);
    // cout<<"Num of nodes:"<<numNodes(root)<<endl;
    // inorder(root);
    // cout<<endl;
    // pair<int,int>p=heightDiameter(root);
    // cout<<"Height: "<<p.first<<endl;
    // cout<<"Diameter: "<<p.second<<endl;
    // cout<<isBST3(root)<<endl;
    delete root;
}