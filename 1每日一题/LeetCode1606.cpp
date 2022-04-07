typedef pair<int, int> PII;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        set<int> se;
        for (int i = 0; i < k; i ++ ) {
            se.insert(i);
        }
        vector<int> cnt(k);
        for (int i = 0; i < arrival.size(); i ++ ) {
            while (heap.size() && heap.top().first <= arrival[i]) {
                se.insert(heap.top().second);
                heap.pop();
            }
            if (se.size() == 0) continue;
            auto p = se.lower_bound(i % k);
            if (p == se.end())
                p = se.begin();
            heap.push({arrival[i] + load[i], *p});
            cnt[*p] ++ ;
            se.erase(p);
        }
        int maxp = 0;
        for (int i = 0; i < k; i ++ )
            maxp = max(maxp, cnt[i]);
        vector<int> ans;
        for (int i = 0; i < k; i ++ )
            if (cnt[i] == maxp)
                ans.push_back(i);
        return ans;
    }
};
