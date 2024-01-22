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
Node*merge(Node*head1,Node*head2){
    Node*fh=NULL;
    Node*ft=NULL;
    int data1=0;
    Node*newNode=new Node(data1);
    while(head1!=NULL and head2!=NULL){
        if(head1->data<head2->data){
            Node*newNode=new Node(data1);
            newNode->data=head1->data;
            if(fh==NULL){
                fh=newNode;
                ft=newNode;
            }
            ft->next=newNode;
            ft=ft->next;
            head1=head1->next;
        }
        else{
            Node*newNode=new Node(data1);
            newNode->data=head2->data;
            if(fh==NULL){
                fh=newNode;
                ft=newNode;
            }
            ft->next=newNode;
            ft=ft->next;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        Node*newNode=new Node(data1);
        newNode->data=head1->data;
        if(fh==NULL){
            fh=newNode;
            ft=newNode;
        }
        ft->next=newNode;
        ft=ft->next;
        head1=head1->next;
    }
    while(head2!=NULL){
        Node*newNode=new Node(data1);
        newNode->data=head2->data;
        if(fh==NULL){
            fh=newNode;
            ft=newNode;
        }
        ft->next=newNode;
        ft=ft->next;
        head2=head2->next;
    }
    return fh;
}
int length(Node*head){
    int count=0;
    if(head==NULL){
        return 0;
    }
    Node*temp=head;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    return count;
}
// Node* insert_Node(Node*head,Node*temp,int i,int data){
//     if(i==0){
//         Node*newNode=new Node(data);
//         newNode->next=head;
//         return newNode;
//     }
//     else if(i>=2 and temp==NULL){
//         return head;
//     }
//     else if(i-1==0 and temp==NULL){
//         return head;
//     }
//     else if(i-1==0 and temp!=NULL){
//         Node*newNode=new Node(data);
//         Node*prefix=temp;
//         Node*suffix=temp->next;
//         prefix->next=newNode;
//         newNode->next=suffix;
//         return head;
//     }
//     else{
//         Node*temp1=temp->next;
//         Node*ans=insert_Node(head,temp1,i-1,data);
//         return ans;
//     }
// }
// Node* insertNode(Node*head,int i,int data){
//     Node*newNode=new Node(data);
//     int count=0;
//     Node* temp=head;
//     if(i==0){
//         newNode -> next=head;
//         head=newNode;
//         return head;
//     }
//     while(count<i-1 and temp!=NULL){
//         temp=temp -> next;
//         count+=1;
//     }
//     if(temp!=NULL or temp->next==NULL){
//         newNode-> next=temp -> next;
//         temp -> next=newNode;
//     }
//     return head;
// }
// Node* deleteNode(Node*head,int i){
//     Node*temp=head;
//     Node*temp1=head;
//     int count=0;
//     if(head==NULL){
//         return head;
//     }
//     if(i==0){
//         temp=temp->next;
//         delete head;
//         return temp;
//     }
//     while(count<i-1 and temp!=NULL){
//         temp=temp -> next;
//         count+=1;
//     }
//     if(temp!=NULL){
//         Node*temp2=temp->next; //i
//         temp->next=temp->next->next;  //i+1
//         delete temp2;
//     }
//     return head;
// }
Node* delete_NodeRec(Node*head,Node*temp,int i){
    if(i==0 and head!=NULL){
        Node*extra=head->next;
        delete head;
        return extra;
    }
    else if(i==0 and head==NULL){
        return head;
    }
    else if(i==1 and temp!=NULL){
        Node*preffix=temp;
        Node*suffix=temp->next->next;
        delete temp->next;
        prefix->next=suffix;
        return head;
    }
    else if(i>1 and (temp==NULL or temp->NULL)){
        return head;
    }
    else{
        Node*temp1=temp->next;
        return delete_NodeRec(head,temp1,i-1);
    }
}
Node* takeInput(){  //O(n2)
    int data;
    cin>>data;
    Node*head=NULL;
    while(data!=-1){
        Node*newNode=new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node*temp=head;
            while(temp -> next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    return head;
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
    Node* head=takeInput_Better();
    // int i;
    // cin>>i;
    // int data;
    // cin>>data;
    // head=insertNode(head,i,data);
    // print(head);
    // head=deleteNode(head,i);
    // length=length(head);
    // print(head);
    // cout<<endl;
    // length=length(head);
    // cout<<length<<endl;
    // int data; 
    // cin>>data;
    // int i;
    // cin>>i;
    // head=insert_Node(head,head,i,data);
    // print(head);
    // int i;
    // cin>>i;
    return 0;
}