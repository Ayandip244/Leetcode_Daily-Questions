int maxSatisfied(int* c, int s, int* g, int gs, int m) {
    int ans = 0;
    for (int i = 0; i < s; i++) {
        if (g[i] == 0)
            ans += c[i];
    }
    for (int i = 0; i < m; i++) {
        if (g[i] == 1)
            ans += c[i];
    }
    int left = 0, right = m;
    int temp = ans;
    while (right < s) {
        if (g[left] == 1)
            temp -= c[left];
        if (g[right] == 1)
            temp += c[right];
        left++;
        right++;
        ans = fmax(ans, temp);
    }
    return ans;
}