class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length(), cost = 0, ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            if (s.charAt(right) != t.charAt(right)) {
                cost += Math.abs(s.charAt(right) - t.charAt(right));
                while (cost > maxCost) {
                    cost -= Math.abs(s.charAt(left) - t.charAt(left));
                    left++;
                }
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}