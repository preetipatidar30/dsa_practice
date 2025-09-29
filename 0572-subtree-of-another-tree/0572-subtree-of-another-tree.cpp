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
bool issame(TreeNode* root, TreeNode* subRoot){
    if(root==nullptr && subRoot==nullptr){
        return true;
    }
    if(root==nullptr ||subRoot==nullptr){
        return false;
    }
    return (root->val==subRoot->val)&&issame(root->left,subRoot->left)&&issame(root->right,subRoot->right);
}
void isvalid(TreeNode* root, TreeNode* subRoot, bool &isval){
   if (root == nullptr || isval) return;
        if(issame(root,subRoot)){
            isval=true;
        }
        isvalid(root->left,subRoot,isval);
        isvalid(root->right,subRoot,isval);
}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool isval=false;
        isvalid(root,subRoot,isval);
        return isval;
       
    }
};