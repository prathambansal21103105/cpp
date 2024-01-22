#include<iostream>
using namespace std;
#include"Node.cpp"
#include"Pair.cpp"
void print(Node*head){
    Node*temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    if(temp!=NULL){
        print(temp);
    }
}
Node* reverseLL_3(Node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node*smallAns=reverseLL_3(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallAns;
}
Pair reverseLL_2(Node*head){
    if(head==NULL or head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns=reverseLL_2(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}
Node*reverseLL_Better(Node*head){
    return reverseLL_2(head).head;
}
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node*newhead=reverseLinkedListRec(head->next);
    Node*temp=newhead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return newhead;
}
Node*takeInput_Better(){ //O(n)
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node*newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail -> next=newNode;
            tail=tail -> next;
        }
        cin>>data;
    }
    return head;
}
int main(){
    Node*head=takeInput_Better();
    head=reverseLL_3(head);
    // head=reverseLL_Better(head);
    // reverseLinkedListRec(Node *head)
    print(head);
    cout<<endl;
}