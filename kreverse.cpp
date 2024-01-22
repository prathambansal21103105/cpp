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
void print1(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
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
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head==NULL or head->next==NULL){
        return head;
    }
    if(k==0){
        return head;
    }
    if(k==1){
        return head;
    }
    int count=1;
    Node*temp=head;
    Node*head1=head;
    Node*headnext=head;
    while(temp!=NULL and count<=k){
        if(k==count){
            headnext=temp->next;
            temp->next=NULL;
            head1=reverseLinkedListRec(head1);
            print1(head1);
            temp=headnext;
            count=0;
            temp=temp->next;
        }
        else{
            temp=temp->next;
            count+=1;
        }
    }
    cout<<endl;
    return NULL;
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}