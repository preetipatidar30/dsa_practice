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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     if(head==nullptr||head->next==nullptr||left==right){
        return head;
     }
     ListNode* dummy=new ListNode(-1);
     dummy->next = head;
     ListNode*prev=dummy;
     int count =0;
     while(count<left-1){
        prev=prev->next;
        count++;
     }
     ListNode* curr=prev->next;
     ListNode*tail=curr;
     ListNode*nextnode=nullptr;
     while(left<=right){
        ListNode*currnext=curr->next;
        curr->next=nextnode;

        
        nextnode=curr;
        curr=currnext;
                prev->next=currnext;
        left++;


     }
     prev->next = nextnode; 
     tail->next=curr;


     return dummy->next;
    }
};