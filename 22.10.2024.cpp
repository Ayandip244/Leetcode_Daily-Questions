class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> arr;
        queue<TreeNode*> q{{root}};
        while (!q.empty()) {
            long long t = 0;
            for (int n = q.size(); n; --n) {
                root = q.front();
                q.pop();
                t += root->val;
                if (root->left) {
                    q.push(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                }
            }
            arr.push_back(t);
        }
        if (arr.size() < k) {
            return -1;
        }
        sort(arr.rbegin(), arr.rend());
        return arr[k - 1];
    }
};
