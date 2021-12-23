class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long ans = 0;
        int n = p.size();
        long long t = 1;
        for (int i = 0; i < n; i ++ ) {
            if (i && p[i] == p[i - 1] - 1) t ++ ;
            else t = 1;
            ans += t;
        }
        return ans;
    }
};

