class Solution {
public:
    int e[10][4], A, B, C, D;
    vector<int> dp, vis;

    int id(int a, int b, int c, int d) {
        return ((a * (B + 1) + b) * (C + 1) + c) * (D + 1) + d;
    }

    int solve(int a, int b, int c, int d) {
        if (!a && !b && !c && !d) return 0;
        int x = id(a, b, c, d);
        if (vis[x]) return dp[x];
        vis[x] = 1;
        dp[x] = INT_MAX;
        for (int i = 2; i <= 9; i++) {
            int na = max(0, a - e[i][0]);
            int nb = max(0, b - e[i][1]);
            int nc = max(0, c - e[i][2]);
            int nd = max(0, d - e[i][3]);
            if (na == a && nb == b && nc == c && nd == d) continue;
            int t = solve(na, nb, nc, nd);
            if (t != INT_MAX) dp[x] = min(dp[x], t + 1);
        }
        return dp[x];
    }

    string build(int a, int b, int c, int d, int len) {
        string s;
        while (len--) {
            for (int i = 1; i <= 9; i++) {
                int na = max(0, a - e[i][0]);
                int nb = max(0, b - e[i][1]);
                int nc = max(0, c - e[i][2]);
                int nd = max(0, d - e[i][3]);
                if (solve(na, nb, nc, nd) <= len) {
                    s += char('0' + i);
                    a = na;
                    b = nb;
                    c = nc;
                    d = nd;
                    break;
                }
            }
        }
        return s;
    }

    string smallestNumber(string num, long long t) {
        e[2][0] = 1;
        e[3][1] = 1;
        e[4][0] = 2;
        e[5][2] = 1;
        e[6][0] = e[6][1] = 1;
        e[7][3] = 1;
        e[8][0] = 3;
        e[9][1] = 2;

        int a = 0, b = 0, c = 0, d = 0;
        while (t % 2 == 0) t /= 2, a++;
        while (t % 3 == 0) t /= 3, b++;
        while (t % 5 == 0) t /= 5, c++;
        while (t % 7 == 0) t /= 7, d++;
        if (t != 1) return "-1";

        A = a;
        B = b;
        C = c;
        D = d;

        int n = (A + 1) * (B + 1) * (C + 1) * (D + 1);
        dp.assign(n, 0);
        vis.assign(n, 0);

        int need = solve(a, b, c, d);
        int m = num.size();

        bool ok = true;
        int x = a, y = b, z = c, w = d;
        for (char ch : num) {
            int d = ch - '0';
            if (!d) {
                ok = false;
                break;
            }
            x = max(0, x - e[d][0]);
            y = max(0, y - e[d][1]);
            z = max(0, z - e[d][2]);
            w = max(0, w - e[d][3]);
        }
        if (ok && !x && !y && !z && !w) return num;

        int first0 = m;
        for (int i = 0; i < m; i++)
            if (num[i] == '0') {
                first0 = i;
                break;
            }

        vector<array<int, 4>> pre(m + 1);
        for (int i = 0; i < m; i++) {
            int d = i < first0 ? num[i] - '0' : 1;
            pre[i + 1] = pre[i];
            for (int j = 0; j < 4; j++) pre[i + 1][j] += e[d][j];
        }

        for (int pos = min(m - 1, first0); pos >= 0; pos--) {
            int ra = max(0, a - pre[pos][0]);
            int rb = max(0, b - pre[pos][1]);
            int rc = max(0, c - pre[pos][2]);
            int rd = max(0, d - pre[pos][3]);

            for (int dig = num[pos] - '0' + 1; dig <= 9; dig++) {
                int na = max(0, ra - e[dig][0]);
                int nb = max(0, rb - e[dig][1]);
                int nc = max(0, rc - e[dig][2]);
                int nd = max(0, rd - e[dig][3]);
                if (solve(na, nb, nc, nd) <= m - pos - 1)
                    return num.substr(0, pos) + char('0' + dig) +
                           build(na, nb, nc, nd, m - pos - 1);
            }
        }

        return build(a, b, c, d, max(m + 1, need));
    }
};
