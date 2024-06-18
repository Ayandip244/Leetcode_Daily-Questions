class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0, cur = 0;
        map<int, int> m;
        for (int i = 0; i < difficulty.size(); ++i) {
            m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
        }
        for (auto &a : m) {
            a.second = max(a.second, cur);
            cur = a.second;
        }
        for (int i = 0; i < worker.size(); ++i) {
            auto it = m.upper_bound(worker[i]);
            if (it != m.begin()) {
                res += (--it)->second;
            }
        }
        return res;
    }
};