//用二进制记录单词
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> a;
        for (auto s : words) {
            int t = 0;
            for (auto c : s) {
                t |= (1 << (c - 'a'));
            }
            a.push_back(t);
        }
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; i ++ )
            for (int j = i + 1; j < n; j ++ )
                if ((a[i] & a[j]) == 0)
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
        return ans;
    }
};