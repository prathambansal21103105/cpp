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
Node *skipMdeleteN(Node *head, int m, int n)
{
    if(head==NULL){
        return head;
    }
    int count=1;
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        count+=1;
    }
    if(m==0 and n!=0){
        return NULL;
    }
    if(m>=count or n==0){
        return head;
    }
    Node*prev=head;
    Node*connect=head;
    Node*temp1=head;
    int index1=0;
    int check=m+n-1;
    while(temp1!=NULL){
        if(temp1->next==NULL and index1>m-1){
            connect=NULL;
            prev->next=connect;
        }
        if(index1==m-1){
            prev=temp1;
            index1+=1;
        }
        else if(index1==m+n-1){
            connect=temp1->next;
            prev->next=connect;
            index1=0;
        }
        else{
            index1+=1;
        }
        temp1=temp1->next;
    }
    return head;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}