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
class BSTIterator {
public:
stack <TreeNode*> s1;
void storel(TreeNode *root){
    while(root!=nullptr){
        s1.push(root);
      root=root->left;
    }
}
    BSTIterator(TreeNode* root) {
        storel(root);
        
    }
    
    int next() {
        TreeNode* ans=s1.top();
        s1.pop();
        storel(ans->right);
        return ans->val;
        
    }
    
    bool hasNext() {
        return s1.size()>0;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */