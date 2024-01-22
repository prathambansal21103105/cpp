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
bool isPalindrome(Node *head)
{
    //Write your code here
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count+=1;
    }
    int mid=0;
    if(count%2==0){
        mid=count/2;
        mid-=1;
    }
    else{
        mid=count/2;
    }
    if(count==1){
        return true;
    }
    int i=0;
    while(i<=mid){
        temp=head;
        int j=0;
        int a=0;
        int b=0;
        while(temp!=NULL){
            if(j==i){
                a=temp->data;
                break;
            }
            temp=temp->next;
            j+=1;
        }
        j=0;
        temp=head;
        while(temp!=NULL){
            if(j==count-1-i){
                b=temp->data;
                break;
            }
            temp=temp->next;
            j+=1;
        }
        cout<<a<<" "<<b<<endl;
        if(a!=b){
            return false;
        }
        else{
            i+=1;
            continue;
        }

    }
    return true;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}