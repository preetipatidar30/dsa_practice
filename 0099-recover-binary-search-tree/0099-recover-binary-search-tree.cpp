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
TreeNode* prev=nullptr;
TreeNode* ft=nullptr;
TreeNode* sd=nullptr;
void inorder(TreeNode* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    if(prev!=nullptr && root->val <prev->val){
        if(ft==nullptr){
            ft=prev;
        }
        sd=root;
    }
    prev=root;
    inorder(root->right);

}
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=ft->val;
        ft->val=sd->val;
        sd->val=temp;
        
    }
};