class Solution {
    struct TrieNode {
        int children[26];
        int length;
        int idx;
        
        TrieNode() {
            fill(begin(children), end(children), -1);
            length = 1e9;
            idx = 1e9;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<TrieNode> trie;
        trie.emplace_back();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            const string& w = wordsContainer[i]; 
            int node = 0; // Start at root
            int len = w.length();
            if (trie[node].length > len) {
                trie[node].length = len;
                trie[node].idx = i;
            }
            for (int k = len - 1; k >= 0; --k) {
                int c = w[k] - 'a';
                if (trie[node].children[c] == -1) {
                    trie[node].children[c] = trie.size();
                    trie.emplace_back();
                }
                node = trie[node].children[c];
                if (trie[node].length > len) {
                    trie[node].length = len;
                    trie[node].idx = i;
                }
            }
        }

        int n = wordsQuery.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            const string& w = wordsQuery[i];
            int node = 0;
            
            for (int k = (int)w.length() - 1; k >= 0; --k) {
                int c = w[k] - 'a';
                if (trie[node].children[c] == -1) {
                    break;
                }
                node = trie[node].children[c];
            }
            ans[i] = trie[node].idx;
        }
        return ans;
    }
};
