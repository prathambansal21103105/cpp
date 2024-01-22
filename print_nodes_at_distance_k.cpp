#include<queue>
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
            k-=1;
        }
        while(!q.empty()){
            cout<<q.front()->data<<endl;
            q.pop();
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
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    BinaryTreeNode<int> *targetNode=findTarget(root,node);
    printDepthK(targetNode,k);
    vector<int>v;
    vector<vector<int> >b;
    vector<int>ans;
    findPath(root,v,b,node);
    ans=b[0];
    if(k==0){
        return;
    }
    for(int i=ans.size()-2;i>=0;i--){
        BinaryTreeNode<int>*newroot=findTarget(root,ans[i]);
        if(newroot->right->data=ans[i+1]){
            newroot->right=NULL;
        }
        else{
            newroot->left=NULL;
        }
        k-=1;
        printDepthK(newroot,k);
        if(k==0){
            break;
        }
    }
    return;
}

//

#define p pair<BinaryTreeNode<int> *,char> 
void print(BinaryTreeNode<int> * root,int k, char val){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    if(val=='#'){
        print(root->left,k-1,'#');
        print(root->right,k-1,'#');
    }
    else{
        //val='l' ? print(root->right,k-1,'#') :  print(root->left,k-1,'#');
        if(val=='l'){
            print(root->right,k-1,'#');
        }
        else if(val=='r'){
            print(root->left,k-1,'#');
        }
    }   
}
void path(BinaryTreeNode<int> *root,int x,vector<p> & check){
    if(root==NULL){
        return ;
    }
    p val;
    val.first=root;
    val.second='#';
    if(root->data==x){
        check.push_back(val);
        return;
    }
    val.second='l';
    path(root->left,x,check);
    if(check.size()!=0){// cout<<root->data<<" ";
        check.push_back(val);//recursion se jab wapas aayega toh updated val push hoga i.e updated val ke second me l hoga jiska root alag hai recursion ke call ke root se hence ab yeh push hoga 
        return;
    }
    val.second='r';
    path(root->right,x,check);
    if(check.size()!=0){ //cout<<root->data<<"&"<<check.size()<<" "; 
        check.push_back(val);//recursion se wapas aayega toh updated val i.e val ke second me hoga r
        return;
    }
    return;
    
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int x, int k) {
    if(root==NULL){
        return;
    }
    vector<p> check; 
    path(root,x,check);
    int n=check.size();
    int i=0;
 //return;
    while( i<n && k>=0){//cout<<check[i].first->data<<"*";
        print(check[i].first ,k , check[i].second);
       // check.pop_back();
        k--; i++;
    }
    // Write your code herez
}