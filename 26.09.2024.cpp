class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() { 
    }
    
    bool book(int start, int end) {
       ++m[start];
        --m[end];
        int s = 0;
        for (auto& [k, v] : m) {
            s += v;
            if (s > 1) {
                --m[start];
                ++m[end];
                return false;
            }
        }
        return true; 
    }
};
