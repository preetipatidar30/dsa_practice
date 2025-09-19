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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int size=0;
      ListNode* temp=head;
      while(temp!=nullptr){
        size++;
        temp=temp->next;
      }
      if (n == size) {
            return head->next;
        }
      int a=size-n;
      int count=0;
       temp = head;
      while(count<a-1){
        temp=temp->next;
        count++;
      }
      temp->next=temp->next->next;
      return head;
    }
    
};