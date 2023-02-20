class Solution {
public:
    bool isY(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n = w.size();
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) {
            string s = w[i];
            if (isY(s[0]) && isY(s.back()))
                a[i] = 1;
        }
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i ++ )
            s[i] = s[i - 1] + a[i - 1];
        vector<int> ans(q.size());
        for (int i = 0; i < q.size(); i ++ ) {
            ans[i] = s[q[i][1] + 1] - s[q[i][0]];
        }
        
        return ans;
    }
};

