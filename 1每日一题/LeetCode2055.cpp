class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        s = ' ' + s;
        vector<int> sc(n + 1), l(n + 1), r(n + 1);
        int a = 0, b = n + 1;
        for (int i = 1; i <= n; i ++ ) {
            sc[i] = sc[i - 1];
            l[i] = a;
            r[n + 1 - i] = b;
            if (s[i] == '*')
                sc[i] ++ ;
            if (s[i] == '|') {
                a = i;
                l[i] = r[i] = i;
            }
            if (s[n + 1 - i] == '|') {
                b = n + 1 - i;
                l[n + 1 - i] = r[n + 1 - i] = n + 1 - i;
            }
        }
        vector<int> ans;
        for (auto i : queries) {
            int rs = r[i[0] + 1];
            int ls = l[i[1] + 1];
            int sum = sc[ls] - sc[rs - 1];
            if (sum < 0) sum = 0;
            ans.push_back(sum);
        }
        return ans;
    }
};
