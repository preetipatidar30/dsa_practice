/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(head==nullptr){
        return nullptr;
       }
       unordered_map<Node*,Node*> ans;
       Node*newhead=new Node(head->val);
       Node* oldtemp=head->next;
       Node* newtemp=newhead;
       ans[head]=newhead;
       while(oldtemp!=nullptr){
        Node* copynode=new Node(oldtemp->val);
        ans[oldtemp]=copynode;
        newtemp->next=copynode;
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;

       }
       oldtemp=head;
       newtemp=newhead;
       while(oldtemp!=nullptr){
        newtemp->random=ans[oldtemp->random];
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;

       }
       return newhead;

    }
};