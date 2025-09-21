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
ListNode* reversenode(ListNode*head){
    ListNode* temp1=head;
    ListNode* prev=nullptr;
    if (head == nullptr || head->next == nullptr) {
            return head;
        }
    while(temp1!=nullptr){
        ListNode* nextn=temp1->next;
        temp1->next=prev;
        prev=temp1;
        temp1=nextn;

    }
    return prev;
}

    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        bool ans=true;
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr &&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tee=reversenode(slow);
        while(tee!=nullptr){
            if(tee->val!=temp->val){
                return false;
                break;
            }else{
                tee=tee->next;
                temp=temp->next;
            }
        }
        return true;
     
 
    }
};