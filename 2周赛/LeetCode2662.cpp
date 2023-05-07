class Solution {
public:
    typedef pair<int, int> PII;
    
    int get(PII a, PII b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
    
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        vector<vector<int>> a;
        for (auto x : specialRoads) {
            if (abs(x[2] - x[0]) + abs(x[3] - x[1]) > x[4])
                a.push_back(x);
        }
        queue<PII> q;
        map<PII, int> d;
        q.push({start[0], start[1]});
        d[{start[0], start[1]}] = 0;
        PII tar = {target[0], target[1]};
        d[tar] = get(tar, {start[0], start[1]});
        while (q.size()) {
            auto t = q.front();
            q.pop();
            d[tar] = min(d[tar], d[t] + get(tar, t));
            for (auto i : a) {
                int dis = d[t] + get(t, {i[0], i[1]}) + i[4];
                PII ed = {i[2], i[3]};
                if (!d.count(ed) || d[ed] > dis) {
                    d[ed] = dis;
                    q.push(ed);
                }
            }
        }
        
        return d[tar];
    }
};

