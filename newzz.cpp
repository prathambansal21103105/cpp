#include<iostream>
using namespace std;

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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head ==NULL or (i==0 and j==0) or i==j or(head->next=NULL) ){
        return head;
    }
    if(i==0 or j==0){
        if(i==0 and j>1){
            int count=0;
            Node *prev = head;
            while(count<j-1){
                prev=prev->next;
                count++;
            }
            Node *current1=head;
            Node *current2=prev->next;
            Node *temp =current1->next;
            current1->next=current2->next;
            current2->next =temp;
            prev->next=current1;
            return current2;

        }
        else if (j==0 and i>1){
            int count=0;
            Node *prev = head;
            while(count<i-1){
                prev=prev->next;
                count++;
            }
            Node *current1=head;
            Node *current2=prev->next;
            Node *temp =current1->next;
            current1->next=current2->next;
            current2->next =temp;
            prev->next=current1;
            return current2;
        }
        else if((i==0 and j==1)or(j==0 and i==1)){
            Node *current1 =head;
            Node*current2 =head->next;
            current1->next=current2->next;
            current2->next =current1;
            return current2;
        }
    }
    else if(i-j==1 or j-i==1){
        Node *prev=head;
        int count =0;
        int iterator = i>j?j:i;
        // cout<<iterator<<endl;
        while(count <iterator){
            prev =prev->next;
            count++;
            // cout<<count<<endl;
            // cout<<"ran"<<endl;
        }
        // cout<<"ran"<<endl;
        Node *current1=prev->next;
        Node*current2=prev->next->next;
        prev->next=current2;
        current1->next=current2->next;
        current2->next=current1;
        return head;
    }
    else{
    Node *prev1 =head;
    Node *prev2=head;
    int count1 =0;
    int count2 =0;
    while(count1<i-1){
        prev1=prev1->next;
        count1++;
        
    }
    while(count2<j-1){
        prev2=prev2->next;
        count2++;
    }
    Node * current1 =prev1->next;
    Node *current2= prev2->next;
    Node*temp = current2->next;
    current2->next =current1->next;
    current1->next = temp;
    prev1->next=current2;
    prev2->next=current1;
    return head;
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}