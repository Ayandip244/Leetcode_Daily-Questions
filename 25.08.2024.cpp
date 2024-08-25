class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) {
                return;
            }
            dfs(root->left);
            dfs(root->right);
            ans.push_back(root->val);
        };
        dfs(root);
        return ans;
    }
};
