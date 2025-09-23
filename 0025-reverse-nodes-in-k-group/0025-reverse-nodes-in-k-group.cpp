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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode*temp=head;
        while(cnt<k){
            if(temp==nullptr){
                return head;
            }
            temp=temp->next;
            cnt++;

        }
        ListNode* prevNode=reverseKGroup(temp,k);
        temp=head;
        cnt=0;
        while(cnt<k){
            ListNode*nextNode=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=nextNode;
            cnt++;
        }
        return prevNode;
    }
};