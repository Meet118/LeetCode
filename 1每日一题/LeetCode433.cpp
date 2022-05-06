class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        q.push(start);
        string gene = "ACGT";
        unordered_set<string> se;
        for (auto s : bank)
            se.insert(s);
        int n = 8;
        unordered_map<string, int> mp;
        mp[start] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (auto s : se) {
                int cnt = 0;
                for (int i = 0; i < n; i ++ )
                    if (t[i] != s[i])
                        cnt ++ ;
                if (cnt == 1 && !mp.count(s)) {
                    q.push(s);
                    mp[s] = mp[t] + 1;
                }
            }
        }
        if (!mp.count(end))
            return -1;
        return mp[end];
    }
};
