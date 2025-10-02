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
   TreeNode* bst(vector<int>& preorder, int & i, int bound){
    if(i>=preorder.size() || preorder[i]>= bound){
        return nullptr;
    }
TreeNode* root= new TreeNode(preorder[i]);
i++;
root->left=bst(preorder,i,root->val);
root->right=bst(preorder,i,bound);
return root;
     
   }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        int i=0;
        return bst(preorder,i,INT_MAX);

    }
     
    
};