class Solution {
public:
    int m, n, k;
    unordered_map<int, int> mp;

    Solution(int _m, int _n) {
        m = _m, n = _n;
        k = m * n;
    }
    
    vector<int> flip() {
        int t = rand() % k;
        int x = t;
        t = mp.count(t) ? mp[t] : t;
        mp[x] = mp.count(k - 1) ? mp[k - 1] : k - 1;
        k -- ;
        return {t % m, t / m};
    }
    
    void reset() {
        k = m * n;
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
