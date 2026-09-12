class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> nextIdx(n, n);
        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n - 1, r = intervals[i][1];
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (intervals[mid][0] > r) {
                    nextIdx[i] = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        struct Node {
            long long score = -1;
            vector<int> idxs;
        };
        vector<vector<Node>> memo(n + 1, vector<Node>(5));
        auto solve = [&](auto& self, int i, int k) -> Node {
            if (k == 0 || i >= n) return Node();
            if (memo[i][k].score != -1) return memo[i][k];
            Node skip = self(self, i + 1, k);
            Node temp = self(self, nextIdx[i], k - 1);
            Node take;
            take.score = temp.score + intervals[i][2];
            take.idxs = temp.idxs;
            take.idxs.push_back(intervals[i][3]);
            sort(take.idxs.begin(), take.idxs.end());
            if (skip.score > take.score) {
                memo[i][k] = skip;
            } else if (skip.score < take.score) {
                memo[i][k] = take;
            } else {
                memo[i][k] = (skip.idxs < take.idxs) ? skip : take;
            }
            return memo[i][k];
        };
        return solve(solve, 0, 4).idxs;
    }
};
