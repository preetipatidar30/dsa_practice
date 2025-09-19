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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(lists[i]!=nullptr){
                ans.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            temp->next=new ListNode(ans[i]);
            temp=temp->next;
        }
        return dummy->next;
    }
};