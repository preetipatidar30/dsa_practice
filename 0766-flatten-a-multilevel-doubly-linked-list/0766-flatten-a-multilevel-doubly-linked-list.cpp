/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        Node *curr=head;
        while(curr!=nullptr){
            if(curr->child!=nullptr){
                Node* nextn=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=nullptr;
                while(curr->next!=nullptr){
                    curr=curr->next;
                }
                if(nextn!=nullptr){
                    curr->next=nextn;
                    nextn->prev=curr;
                }


            }
            curr=curr->next;
        }
        return head;
        
    }
};