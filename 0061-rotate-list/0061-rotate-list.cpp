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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
       int size=1;
       ListNode*temp=head;
       while (temp->next != nullptr) {
            temp = temp->next;
            size++;
        }
        

       int a=k%size;
        if (a == 0) return head;  
        temp->next=head;
        int r=size-a;
     for(int i=0;i<r;i++){
        temp=temp->next;
     }
     ListNode* newhead=temp->next;
     temp->next=nullptr;
     return newhead;

    }
};