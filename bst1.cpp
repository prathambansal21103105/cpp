class BST {
    BinaryTreeNode<int>* root;
   private:
    void print1(BinaryTreeNode<int>*node){
        if(node==NULL){
            return;
        }
        else{
            cout<<node->data<<":";
            if(node->left!=NULL){
                cout<<"L:"<<node->left->data<<",";
            }
            if(node->right!=NULL){
                cout<<"R:"<<node->right->data;
            }
            cout<<endl;
            if(node->left!=NULL){
                print1(node->left);
            }
            if(node->right!=NULL){
                print1(node->right);
            }
        }
    }
    int find(BinaryTreeNode<int>*node){
        if(node->left==NULL){
            int ans=node->data;
            return ans;
        }
        else{
            int ans=find(node->left);
            return ans;
        }
    }
    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>*node){
        if(node==NULL){
            return NULL;
        }
        if(data>node->data){
            node->right=deleteData(data,node->right);
        }
        else if(data<node->data){
            node->left=deleteData(data,node->left);
        }
        else{
            if(node->left==NULL and node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>*temp=node->right;
                node->right==NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                BinaryTreeNode<int>*temp=node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode=node->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
                int rightMin=minNode->data;
                node->data=rightMin;
                node->right=deleteData(rightMin,node->right);
                return node;
            }
        }
    }
    BinaryTreeNode<int>* insert1(int data,BinaryTreeNode<int>*node) { 
        if(node==NULL){
            BinaryTreeNode<int>*newnode=new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(node->data<data){
            if(node->right==NULL){
                node->right=insert1(data,node->right);
            }
            else{
                node->right=insert1(data,node->right);
            }
        }
        else{
            if(node->left==NULL){
                node->left=insert1(data,node->left);
            }
            else{
                node->left=insert1(data,node->left);
            }
        }
        return node;
    }
    bool hasData1(int data,BinaryTreeNode<int>*node){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        else if(data<node->data){
            return hasData1(data,node->left);
        }
        else{
            return hasData1(data,node->right);
        }
    } 
   public:
    BST() { 
        root=NULL;
    }
    ~BST(){
        delete root;
    }


    void remove(int data) { 
        root=deleteData(data,root);
    }
    void print() { 
        print1(root);
    }
    void insert(int data) { 
        root=insert1(data,root);
    }
    bool search(int data) {

        return hasData1(data,root);
    }
    
};