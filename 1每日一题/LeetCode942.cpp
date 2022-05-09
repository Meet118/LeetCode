class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans(n + 1);
        int a = 0, b = n;
        for (int i = 0; i <= n; i ++ ) {
            if (s[i] == 'I')    
                ans[i] = a ++ ;
            else
                ans[i] = b -- ;
        }
        return ans;
    }
};
