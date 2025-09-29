/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
 if(root==nullptr){
    return nullptr;
 }
 if(root==p ||root==q){
    return root;
 }
 TreeNode*leftl= lowestCommonAncestor(root->left,p,q);
 TreeNode*rightl= lowestCommonAncestor(root->right,p,q);
 if(leftl&&rightl){
    return root;
 }else if(leftl!=nullptr){
    return leftl;
 }else{
    return rightl;
 }
        
    }
};