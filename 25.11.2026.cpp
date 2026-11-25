class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        long long base = 19, mod = 1e9 + 7;
        vector<long long> powers(n + 1, 1);
        unordered_map<long long, int> hashValues;
        auto checkUniqueness = [&](int len) {
            for (int i = 1; i <= n; i++)
                powers[i] = (powers[i - 1] * base) % mod;
            long long hash = 0;
            for (int i = 0; i < len; i++)
                hash = (hash * base + nums[i]) % mod;
            hashValues.clear();
            hashValues[hash] = 1;
            for (int i = 1; i < n - len + 1; i++) {
                hash = (hash - powers[len - 1] * nums[i - 1] % mod + mod) % mod;
                hash = (hash * base + nums[i + len - 1]) % mod;
                hashValues[hash]++;
            }
            for (auto &p : hashValues)
                if (p.second == 1)
                    return true;
            return false;
        };
        int ans = n, left = 1, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (checkUniqueness(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
