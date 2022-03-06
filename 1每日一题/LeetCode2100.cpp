class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> l(n), r(n);
        int c = 1;
        l[0] = r[n - 1] = 1;
        for (int i = 1; i < n; i ++ ) {
            if (security[i] <= security[i - 1])
                c ++ ;
            else
                c = 1;
            l[i] = c;
        }
        c = 1;
        for (int i = n - 2; i >= 0; i -- ) {
            if (security[i] <= security[i + 1])
                c ++ ;
            else
                c = 1;
            r[i] = c;
        }
        vector<int> ans;
        for (int i = time; i + time < n; i ++ ) {
            if (l[i] > time && r[i] > time)
                ans.push_back(i);
        }
        return ans;
    }
};
