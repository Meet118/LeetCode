typedef pair<int, int> PII;

#define x first
#define y second

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        vector<PII> p[26];
        for (int i = 0; i < n; i ++ )
            p[words[i][0] - 'a'].push_back({i, 0});
        int ans = 0;
        for (auto c : s) {
            vector<PII> bk;
            for (auto& a : p[c - 'a']) {
                if (a.y + 1 == words[a.x].size()) ans ++ ;
                else {
                    bk.push_back({a.x, a.y + 1});
                }
            }
            p[c - 'a'].clear();
            for (auto& a : bk)
                p[words[a.x][a.y] - 'a'].push_back(a);
        }

        return ans;
    }
};
