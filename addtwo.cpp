/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=NULL;
        ListNode* temp;
        while(l1!=NULL or l2!=NULL){
            int last1=0;
            int last2=0;
            if(l1!=NULL){
                last1=l1->val;
            }
            if(l2!=NULL){
                last2=l2->val;
            }
            int ans1=last1+last2+carry;
            if(ans1>9){
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* node=new ListNode(ans1%10);
            if(head==NULL){
                head=node;
                temp=head;
            }
            else{
                temp->next=node;
                temp=temp->next;
            }
            if(l1!=NULL){
                l1=l1->next;
            }
            if(l2!=NULL){
                l2=l2->next;
            }
        }
        if(carry!=0){
            ListNode* node=new ListNode(carry);
            temp->next=node;
            temp=temp->next;
        }
        return head;
    }
};