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
        ListNode* dummy = new ListNode(0); 
        ListNode* temp = dummy; 
        while(l1!=nullptr ||l2!=nullptr){
            int d=carry;
            if(l1!=nullptr){
                d+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                d+=l2->val;
                l2=l2->next;
            }
            carry=d/10;
            d=d%10;
            temp->next=new ListNode(d);
            temp=temp->next;
            
        }
       
        if (carry > 0) { 
            temp->next = new ListNode(carry);
        }
        return dummy->next;
        
    }
};