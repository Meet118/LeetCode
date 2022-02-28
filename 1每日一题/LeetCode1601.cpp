class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        for (int i = 0; i < (1 << m); i ++ ) {
            vector<int> a(n);
            int t = 0;
            int x = i;
            //lowbit计算二进制中1的个数
            while (x) {
                x -= x & (-x);
                t ++ ;
            }
            if (t < ans)
                continue;
            for (int j = 0; j < m; j ++ ) {
                if ((i >> j) & 1) {
                    a[requests[j][0]] ++ ;
                    a[requests[j][1]] -- ;
                }
            }
            bool f = true;
            for (auto v : a) {
                if (v != 0) {
                    f = false;
                    break;
                }
            }
            if (f)
                ans = max(ans, t);
        }
        return ans;
    }
};
