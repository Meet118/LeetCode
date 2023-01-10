class Solution {
public:
    typedef pair<int, int> PII;

    struct Node {
        int l, r, ol, ne, idx;
        bool operator < (const Node &a) const { //效率低的优先级高
            if (l + r == a.l + a.r) {
                return idx < a.idx;
            }
            return l + r < a.l + a.r;
        }
    };
    
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<Node> L, R; //左右正在等待过桥的
        priority_queue<PII, vector<PII>, greater<PII>> waitL, waitR; //左右正在卸货的
        for (int i = 0; i < k; i ++ ) {
            L.push({time[i][0], time[i][2], time[i][1], time[i][3], i});
        }
        int ans = 0;
        while (n || waitR.size() || R.size()) {
            //先将卸完货的加入等待队列
            while (waitR.size() && ans >= waitR.top().first) {
                auto t = waitR.top();
                waitR.pop();
                int i = t.second;
                R.push({time[i][0], time[i][2], time[i][1], time[i][3], i});
            }
            while (waitL.size() && ans >= waitL.top().first) {
                auto t = waitL.top();
                waitL.pop();
                int i = t.second;
                L.push({time[i][0], time[i][2], time[i][1], time[i][3], i});
            }
            //优先让右边的过桥
            if (R.size()) {
                auto t = R.top();
                R.pop();
                ans += t.r;
                waitL.push({ans + t.ne, t.idx});
            }
            else if (L.size() && n) { //如果还有货要搬且有工人
                auto t = L.top();
                L.pop();
                n -- ;
                ans += t.l;
                waitR.push({ans + t.ol, t.idx});
            }
            else { //否则需要等待最先搬起/放下货的工人完成
                int x = 1e9;
                if (waitR.size()) x = min(x, waitR.top().first);
                if (waitL.size()) x = min(x, waitL.top().first);
                ans = max(ans, x);
            }
        }
        return ans;
    }
};

