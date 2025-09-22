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
       ListNode* dummy= new ListNode(-1);
       ListNode* temp=dummy;
       ListNode*t1=l1;
       ListNode* t2=l2;
       while(t1!=nullptr||t2!=nullptr) {
        int d=carry;
        if(t1!=nullptr){
            d+=t1->val;
            t1=t1->next;
        }
        if(t2!=nullptr){
            d+=t2->val;
            t2=t2->next;
        }
        carry=d/10;
        int dd=d%10;
        ListNode* newnode=new ListNode(dd);
        temp->next=newnode;
        temp=temp->next;
       }
       if(carry!=0){
        ListNode* newnode=new ListNode(carry);
        temp->next=newnode;
       }
        return dummy->next;
    }
};