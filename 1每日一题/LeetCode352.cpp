//维护set
class SummaryRanges {
public:
    set<pair<int, int>> se;
    int INF = 1e9;

    SummaryRanges() {
        //插入哨兵节点
        se.insert({-INF, -INF});
        se.insert({INF, INF});
    }
    
    void addNum(int val) {
        auto r = se.lower_bound({val, 0});
        auto l = r;
        l -- ;

        int a = l->first, b = l->second, c = r->first, d = r->second;

        if (val > b + 1 && val < c - 1) {
            se.insert({val, val});
        }
        else if (val - 1 == b && val + 1 == c) {
            se.erase(l);
            se.erase(r);
            se.insert({a, d});
        }
        else if (val - 1 == b) {
            se.erase(l);
            se.insert({a, val});
        }
        else if (val + 1 == c) {
            se.erase(r);
            se.insert({val, d});
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto i : se) {
            if (i.first == INF || i.first == -INF)
                continue;
            vector<int> t;
            t.push_back(i.first);
            t.push_back(i.second);
            res.push_back(t);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

//----------------------------------------------------------------

//并查集
class SummaryRanges {
public:
    int N = 1e4 + 10;

    vector<int> p;
    map<int, int> mp;

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    SummaryRanges() {
        p.resize(N);
        for (int i = 0; i < N; i ++ )
            p[i] = i;
    }
    
    void addNum(int val) {
        val ++ ;
        if (mp.count(find(val))) return;
        if (mp.count(find(val - 1)) && mp.count(val + 1)) {
            p[val + 1] = find(val - 1);
            p[val] = find(val - 1);
            mp[find(val - 1)] = mp[val + 1];
            mp.erase(val + 1);
        }
        else if (mp.count(find(val - 1))) {
            p[val] = find(val - 1);
            mp[find(val - 1)] = val;
        }
        else if (mp.count(val + 1)) {
            p[val + 1] = val;
            mp[val] = mp[val + 1];
            mp.erase(val + 1);
        }
        else {
            mp[val] = val;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& [a, b] : mp) {
            ans.push_back({(int)a - 1, (int)b - 1});
        }
        return ans;
    }
};
