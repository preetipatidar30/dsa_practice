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
int findheight(TreeNode* root){
    if(root==NULL){
            return 0;
        }
    int lh=findheight(root->right);
    int rh=findheight(root->left);
    if(lh==-1||rh==-1){
        return -1;
    }
    int diff=abs(lh-rh);
    if(diff<=1){
        return max(lh,rh)+1;
    }else{
        return -1;
    }

}

   bool isBalanced(TreeNode*root){
        return findheight(root)!=-1;
        
    }
};