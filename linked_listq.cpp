#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if(head==NULL){
        return head;
    }
    if(head!=NULL){
        int count=0;
        Node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count+=1;
        }
        if(n>=count){
        return NULL;
        }
    }
    Node*head1=head;
    if(head1->next->next==NULL and n!=0){
        int data1=head1->next->data;
        delete head1->next;
        Node*newNode=new Node(data1);
        newNode->next=head1;
        head1->next=NULL;
        return newNode;   
    }
    while(n>0){
    Node*temp=head1;
    while(temp->next->next!=NULL){
        if(temp->next->next->next!=NULL){
        temp=temp->next;
        }
        else{
            break;
        }
    }
    int data1=temp->next->next->data;
    delete temp->next->next;
    temp->next->next=NULL;
    Node*newNode=new Node(data1);
    newNode->next=head1;
    head1=newNode;
    n-=1;
    }
    return head1;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

// Node *appendLastNToFirst(Node *head, int n)
// {
//     if(head == nullptr)
//         return nullptr;
    
    
//     if(n == 0){
//         return head;
//     }
//     Node * len_head = head;
//     int length = 1;
//     while(len_head->next != NULL){
//         len_head = len_head->next;
//         length++;
//     }
    
//     Node * temp = head;
//     int pos = 1;
//     while(pos<length-n){
//         temp = temp->next;
//         pos++;
//     }
//     Node * newHead = temp->next;
//     Node * newTemp = head;
//     while(newTemp->next != NULL){
//         newTemp = newTemp->next;
//     }
//     newTemp->next = head;
//     head = newHead;
//     temp->next = NULL;
//     return head;
    
        
// }