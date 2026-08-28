class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int f[26] = {}, odd = 0, mid = -1, n = s.size(), half = n / 2;
        for (char c : s) f[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (f[i] % 2) { odd++; mid = i; }
            f[i] /= 2;
        }
        if (odd > 1) return "";
        string ans(n, ' ');
        int p = 0;
        auto make = [&]() {
            if (mid != -1) ans[half] = 'a' + mid;
            for (int i = 0; i < half; i++) ans[n - 1 - i] = ans[i];
        };
        while (p < half && f[target[p] - 'a']) {
            ans[p] = target[p];
            f[target[p] - 'a']--;
            p++;
        }
        if (p == half) {
            make();
            if (ans > target) return ans;
        }
        while (true) {
            if (p < half) {
                for (int i = target[p] - 'a' + 1; i < 26; i++) {
                    if (f[i]) {
                        ans[p] = 'a' + i; 
                        f[i]--;
                        for (int j = 0, dst = p + 1; j < 26; j++) {
                            while (f[j]--) ans[dst++] = 'a' + j;
                        }
                        make();
                        return ans;
                    }
                }
            }
            if (p == 0) return "";
            f[target[--p] - 'a']++;
        }
    }
};
