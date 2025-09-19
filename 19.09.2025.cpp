class Spreadsheet {
private:
    unordered_map<string, int> d;
public:
    Spreadsheet(int rows) {}
    void setCell(string cell, int value) {
        d[cell] = value;
    }
    void resetCell(string cell) {
        d.erase(cell);
    }
    int getValue(string formula) {
        int ans = 0;
        stringstream ss(formula.substr(1));
        string cell;
        while (getline(ss, cell, '+')) {
            if (isdigit(cell[0])) {
                ans += stoi(cell);
            } else {
                ans += d.count(cell) ? d[cell] : 0;
            }
        }
        return ans;
    }
};
