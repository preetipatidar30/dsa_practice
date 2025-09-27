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
int helper(TreeNode*root,int &dia){
    if(root==nullptr){
        return 0;
    }
    int ll=helper(root->left,dia);
    int rr=helper(root->right,dia);
  dia = max(dia, ll + rr);

        return max(ll, rr) + 1;
}

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int dia=0;
    helper(root,dia);

    
       return dia;

        
     }
};