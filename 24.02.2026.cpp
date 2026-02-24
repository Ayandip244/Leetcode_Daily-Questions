class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* root, int x) -> int {
            if (!root) {
                return 0;
            }
            x = x << 1 | root->val;
            if (root->left == root->right) {
                return x;
            }
            return dfs(root->left, x) + dfs(root->right, x);
        };
        return dfs(root, 0);
    }
};
