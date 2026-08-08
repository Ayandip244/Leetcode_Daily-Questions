class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                dp[i] = dp[i + 1] + 1;
                j -= 1;
            } else {
                dp[i] = dp[i + 1];
            }
        }

        vector<int> res;
        int wild = 1;
        for (int i = 0; i < n && res.size() < m; i++) {
            if (word1[i] == word2[res.size()]) {
                res.push_back(i);
            } else if (wild && res.size() + wild + dp[i + 1] >= m) {
                wild -= 1;
                res.push_back(i);
            }
        }

        return res.size() == m ? res : vector<int>{};
    }
};
