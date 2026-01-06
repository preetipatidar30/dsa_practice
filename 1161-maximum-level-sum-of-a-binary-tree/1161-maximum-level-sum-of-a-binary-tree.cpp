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
       queue<TreeNode*> q1;
       if(root!=nullptr){
        q1.push(root);
       }
       int maxsum=INT_MIN;
       int level=0;
       int maxlevel=0;
       while(!q1.empty()){
        int sum=0;
        level++;
        int n=q1.size();
        for(int i=0;i<n;i++){
            TreeNode* node=q1.front();
            sum+=node->val;
            if(node->left!=nullptr){
                q1.push(node->left);

            }
            if(node->right!=nullptr){
                q1.push(node->right);
            }
            q1.pop();
        }
        if(sum>maxsum){
            maxsum=sum;
            maxlevel=level;
        }
       }
       return maxlevel;

    }
};