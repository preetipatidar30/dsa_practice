/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       if(root==nullptr) return 0;
       queue <TreeNode*> q;
       q.push(root);
       int maxsum=INT_MIN;
       int level=0;
       int currlevel=0;
       int levelf=-1;
       while(!q.empty()){
        int s=q.size();
        int sum=0;
        currlevel+=1;
        for(int i=0;i<s;i++){
             if(q.front()->left!=nullptr){
                q.push(q.front()->left);
            }
            if(q.front()->right!=nullptr){
                q.push(q.front()->right);
            }
            sum+=q.front()->val;
            q.pop();
        }
        if(maxsum<sum){
            maxsum=sum;
            levelf=currlevel;
        }
       }
       return levelf;
        
    }
};