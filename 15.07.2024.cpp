class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> vis;
        for (auto& d : descriptions) {
            int p = d[0], c = d[1], left = d[2];
            if (!m.count(p)) m[p] = new TreeNode(p);
            if (!m.count(c)) m[c] = new TreeNode(c);
            if (left)
                m[p]->left = m[c];
            else
                m[p]->right = m[c];
            vis.insert(c);
        }
        for (auto& [v, node] : m) {
            if (!vis.count(v)) return node;
        }
        return nullptr;
    }
};
