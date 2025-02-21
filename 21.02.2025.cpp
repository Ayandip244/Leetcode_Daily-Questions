class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);

    }
    
    bool find(int target) {
        return s.contains(target);
    }
    private:
    unordered_set<int> s;

    void dfs(TreeNode* root) {
        s.insert(root->val);
        if (root->left) {
            root->left->val = root->val * 2 + 1;
            dfs(root->left);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            dfs(root->right);
        }
    };
};
