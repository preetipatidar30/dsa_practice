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
TreeNode* merge(TreeNode* root1, TreeNode* root2){
    if(root1==nullptr && root2==nullptr){
        return nullptr;
    }
    int data=0;
    if(root1!=nullptr){
        data+=root1->val;
    }
    if(root2!=nullptr){
        data+=root2->val;
    }
     TreeNode* root=new TreeNode(data);
        root->left = merge(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        root->right = merge(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    return root;
  
    
}

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1,root2);
        
        
    }
};