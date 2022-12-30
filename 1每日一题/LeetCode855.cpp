class ExamRoom {
public:
    int n;
    set<int> se;

    ExamRoom(int _n) {
        n = _n;
    }
    
    int seat() {
        int ans = 0;
        if (se.size()) {
            int d = *se.begin();
            for (auto i = se.begin(); i != se.end(); i ++ ) {
                auto j = i;
                j ++ ;
                if (j != se.end()) {
                    int dist = (*j - *i) / 2;
                    if (dist > d) {
                        d = dist;
                        ans = *i + dist;
                    }
                }
                else {
                    int dist = n - *i - 1;
                    if (dist > d) {
                        d = dist;
                        ans = n - 1;
                    }
                }
            }
        }
        se.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        se.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
