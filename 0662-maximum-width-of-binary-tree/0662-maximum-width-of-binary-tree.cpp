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
void helper(TreeNode * root,long long & maxi){
    if(root==nullptr){
        return;
    }
    queue<pair <TreeNode*,long long>>q;
    q.push({root,0});
    while(q.size()>0){
        long long ll;
        long long rr;
        int ss=q.size();
        ll = q.front().second;
        for(int i=0;i<ss;i++){
            long long index=q.front().second -ll;
            TreeNode* node=q.front().first;
            if(i==ss-1){
                rr = q.front().second;  
            }
          
            if(node->left!=nullptr){
                q.push({node->left,2*index+1});
            }
             if(node->right!=nullptr){
                q.push({node->right,2*index+2});
            }
            q.pop();
        }
        maxi=max(maxi,rr-ll+1);
    }
}

    int widthOfBinaryTree(TreeNode* root) {
        long long maxwid=0;
        if (root==nullptr){
            return 0;
        }
        helper(root,maxwid);
        return int(maxwid);
        
    }
};