//模拟
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string a = "";
        for (char c : s)
            if (c != '-')
                a += c;
        
        string ans = "";
        for (int i = 0; i < a.size() % k; i ++ )
            ans += toupper(a[i]);
        for (int i = a.size() % k; i < a.size();) {
            if (i)
                ans += '-';
            for (int j = 0; j < k; j ++ )
                ans += toupper(a[i ++ ]);
        }
        return ans;
    }
};