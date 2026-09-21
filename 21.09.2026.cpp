class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0);
        for (int j = 0; j < n; j++) {
            int nj = nums[j] % k;
            vector<long long> new_cnt(k, 0);
            for (int r = 0; r < k; r++) {
                if (cnt[r] > 0) {
                    new_cnt[(r * nj) % k] += cnt[r];
                }
            }
            new_cnt[nj]++;
            cnt = new_cnt;
            for (int r = 0; r < k; r++) {
                result[r] += cnt[r];
            }
        }
        return result;
    }
};
