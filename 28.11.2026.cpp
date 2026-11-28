class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bucket(n + 1, 0);
        for (auto& it : items) bucket[it[0]]++;

        vector<long long> reach(n + 1, 0);
        for (int d = 1; d <= n; d++) {
            long long sum = 0;
            for (int m = d; m <= n; m += d) sum += bucket[m];
            reach[d] = sum - 1;
        }

        long long pmin = LLONG_MAX;
        for (auto& it : items) pmin = min(pmin, (long long)it[1]);

        vector<pair<long long, long long>> eligible;
        for (auto& it : items) {
            long long price = it[1];
            long long r = reach[it[0]];
            if (r > 0 && price < 2 * pmin) {
                eligible.push_back({price, r});
            }
        }
        sort(eligible.begin(), eligible.end());

        long long remaining = budget;
        long long total = 0;
        for (auto& [price, r] : eligible) {
            long long affordable = remaining / price;
            if (affordable == 0) break;
            long long buy = min(affordable, r);
            total += buy * 2;
            remaining -= buy * price;
        }
        total += remaining / pmin;
        return (int)total;
    }
};
