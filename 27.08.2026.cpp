class Solution{
public:
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int n = s.size();
        string ans = "";
        for (int pos = 0; pos < n; pos++)
        {
            for (int i = 0; i < 26; i++)
            {
                freq[i] = 0;
            }
            for (char c : s)
            {
                freq[c - 'a']++;
            }
            string prefix = target.substr(0, pos);
            bool ok = true;
            for (char c : prefix)
            {
                if (freq[c - 'a'] == 0)
                {
                    ok = false;
                    break;
                }
                freq[c - 'a']--;
            }
            if (!ok)
            {
                continue;
            }
            for (int c = target[pos] - 'a' + 1; c < 26; c++)
            {
                if (freq[c] > 0)
                {
                    string res = prefix;
                    res.push_back(char('a' + c));
                    freq[c]--;
                    for (int k = 0; k < 26; k++)
                    {
                        res.append(freq[k], char('a' + k));
                    }
                    if (res > target)
                    {
                        ans = ans.empty() ? res : min(ans, res);
                    }
                }
            }
        }
        return ans;
    }
};
