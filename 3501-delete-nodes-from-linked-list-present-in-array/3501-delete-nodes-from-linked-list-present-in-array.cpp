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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==nullptr){
            return head;
        }
        unordered_set<int> numsrec(nums.begin(),nums.end());
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr=head;
       
        while(curr!=nullptr){
           if(numsrec.count(curr->val)){
            prev->next=curr->next;
            curr=curr->next;
           }else{
            prev=curr;
            curr=curr->next;
           }
            
            
        }
        return dummy->next;
    }
};