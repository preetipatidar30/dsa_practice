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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode* dummyHead = new ListNode(-1); // Store the dummy head
        ListNode* temp = dummyHead;  
        ListNode * t1=list1;
        ListNode * t2=list2;
        while(t1!=nullptr &&t2!=nullptr){
            if(t1->val<t2->val){
                temp->next=t1;
                t1=t1->next;
            }else{
                 temp->next=t2;
                 t2=t2->next;
            }
            temp=temp->next;
        }
        while(t1!=nullptr){
            temp->next=t1;
                t1=t1->next;
                temp=temp->next;
        }
        while(t2!=nullptr){
            temp->next=t2;
                t2=t2->next;
                temp=temp->next;
        }
        return dummyHead->next;




    }
};