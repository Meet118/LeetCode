class DetectSquares {
public:
    map<pair<int, int>, int> mp;
    map<int, set<pair<int, int>>> g;
    
    DetectSquares() {
        
    }
    
    void add(vector<int> p) {
        mp[{p[0], p[1]}] ++ ;
        g[p[1]].insert({p[0], p[1]});
    }
    
    int cnt = 0;
    int count(vector<int> p) {
        cnt ++ ;
        int x = p[0], y = p[1];
        int ans = 0;
        
        for (auto k : g[y])  {
            int i = k.first;
            if (i != x && mp[{i, y}] > 0) {
                int r = abs(x - i);
                
                if (mp[{i, y + r}] > 0 && mp[{x, y + r}] > 0)
                    ans += mp[{i, y}] * mp[{i, y + r}] * mp[{x, y + r}];
                if (mp[{i, y - r}] > 0 && mp[{x, y - r}] > 0)
                    ans += mp[{i, y}] * mp[{i, y - r}] * mp[{x, y - r}];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
