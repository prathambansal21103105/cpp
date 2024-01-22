#include"Node.cpp"
class Stack{
    Node*head;
    int size;
    public:
    Stack(){
        head=NULL;
        size=0;
    }
    void push(int n){
        size+=1;
        if(head==NULL){
            Node*newNode=new Node(n);    
            head=newNode;
        }
        else{
            Node*newNode=new Node(n);
            newNode->next=head;
            head=newNode;
        }
    }
    int top(){
        if(size==0){
            return -1;
        }
        return head->data;
    }
    int pop(){
        if(size==0){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        size-=1;
        int return1=head->data;
        head=head->next;
        return return1;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
};