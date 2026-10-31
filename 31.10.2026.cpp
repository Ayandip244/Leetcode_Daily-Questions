class node {
public:
    int right, down;
    node(): right(0), down(0) {}

    node &operator = (pair<int, int> p) {
        right = p.first;
        down = p.second;
        return *this;
    }
};

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int mod = 1e9+7;
        // {right, down}
        vector<vector<node>> dp(n, vector<node>(m));
        for (int i = 0; i < n; i++) {
            if (!grid[i][0]) dp[i][0] = {1, 1};
            else {
                dp[i][0] = {1, 0};
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            if (!grid[0][j]) dp[0][j] = {1, 1};
            else {
                dp[0][j] = {0, 1};
                break;
            }
        }
    	for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (!grid[i][j]) {
                    int tmp = (dp[i-1][j].down + dp[i][j-1].right) % mod;
                    dp[i][j] = {tmp, tmp};
                } else {
                    int r = dp[i-1][j].down;
                    int d = dp[i][j-1].right;
                    dp[i][j] = {r, d};
                }
            }
        }
        return dp[n-1][m-1].down;
    }
};
