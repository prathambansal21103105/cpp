template<typename T>
#include"Node.cpp"
class QueueUsingLL{
    Node*head;
    Node*tail;
    int size;
    public:
    QueueUsingLL(){
        head=NULL;
        tail=NULL;
        size=0;
    }   
    void enqueue(T element){
        Node*newNode=new Node(element);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            size+=1;
            return;
        }
        tail->next=newNode;
        tail=tail->next;
        size+=1;
    }
    bool isEmpty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        return size;
    }
    T dequeue(){
        if(size==0){
            cout<<"Queue is empty !"<<endl;
            return 0;
        }
        T return1=head->data;
        Node*extra=head->next;
        size-=1;
        head->next=NULL;
        delete head;
        head=extra;
        return return1;
    }
    T front(){
        if(isEmpty()){
            return 0;
        }
        else{
            return head->data;
        }
    }
}