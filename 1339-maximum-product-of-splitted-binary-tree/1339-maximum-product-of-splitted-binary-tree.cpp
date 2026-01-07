class Solution {
public:
    int mod_e = 1e9 + 7;
    long long rootsum = 0;

    long long helper(TreeNode* root, long long &maxproduct) {
        if (!root) return 0;

        long long left = helper(root->left, maxproduct);
        long long right = helper(root->right, maxproduct);

        long long sum = left + right + root->val;

        // only calculate product in second DFS
        if (rootsum != 0) {
            maxproduct = max(maxproduct, sum * (rootsum - sum));
        }

        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long dummy = 0;
        rootsum = helper(root, dummy);  // first DFS → total sum

        long long maxproduct = 0;
        helper(root, maxproduct);       // second DFS → max product

        return maxproduct % mod_e;
    }
};
