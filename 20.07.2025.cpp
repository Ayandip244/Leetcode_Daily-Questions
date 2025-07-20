class Solution {
public:
    struct Node {
        map<string, Node*> c;
        bool del = 0;
    }*root = new Node;

    unordered_map<string, vector<Node*>> mp;

    string dfs(Node* n) {
        if (n->c.empty()) return "";
        string s = "(";
        for (auto& [k, v] : n->c) s += k + dfs(v);
        s += ")";
        mp[s].push_back(n);
        return s;
    }

    void get(Node* n, vector<string>& p, vector<vector<string>>& res) {
        for (auto& [k, v] : n->c) {
            if (v->del) continue;
            p.push_back(k);
            res.push_back(p);
            get(v, p, res);
            p.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            Node* cur = root;
            for (auto& d : path)
                cur = cur->c[d] ?: cur->c[d] = new Node;
        }
        dfs(root);
        for (auto& [_, v] : mp)
            if (v.size() > 1) for (auto* n : v) n->del = 1;
        vector<vector<string>> res;
        vector<string> tmp;
        get(root, tmp, res);
        return res;
    }
};
