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