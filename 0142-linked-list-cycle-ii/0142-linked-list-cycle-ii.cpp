/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;  
    ListNode* fast = head;  
    bool ans=false;
while(fast!=nullptr && fast->next!=nullptr)
{
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
        ans=true;
        break;
    }
}  
if(ans==true){
slow=head;
while(slow!=fast){
   
    fast=fast->next;
    slow=slow->next;

}
return slow;
}   
return NULL;   
    }
};