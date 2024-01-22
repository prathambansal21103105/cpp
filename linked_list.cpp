#include<iostream>
using namespace std;
#include"Node.cpp"
void print(Node*head){
    Node*temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    if(temp!=NULL){
        print(temp);
    }
}
int main(){
    // Statically
    Node n1(1);
    Node*head=&n1; //creating this pointer to store address of the head
    Node*temp=head;
    Node n2(2);
    n1.next=&n2;
    Node n3(3);
    n2.next=&n3;
    Node n4(4);
    n3.next=&n4;
    Node n5(5);
    n4.next=&n5;
    print(temp);
    cout<<endl;
    cout<<head->data<<endl;

    // n1.next=&n2;

    // cout<<n1.data<<" "<<n2.data<<endl;
    // cout<<head -> data<<endl;
    
    // //Dynamic
    // Node*n3=new Node(10);
    // Node*head1=n3;

    // Node*n4=new Node(20);
    // n3->next=n4;
    
    return 0;
}