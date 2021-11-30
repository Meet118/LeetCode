class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_set<int> se;
        se.insert(0);
        se.insert(firstPerson);
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int m = meetings.size();
        for (int i = 0; i < m;) {
            int j = i + 1;
            while (j < m && meetings[i][2] == meetings[j][2]) j ++ ;
            queue<int> q;
            unordered_set<int> s;
            unordered_map<int, vector<int>> mp;
            for (int k = i; k < j; k ++ ) {
                int x = meetings[k][0], y = meetings[k][1];
                mp[x].push_back(y);
                mp[y].push_back(x);
                if (se.count(x) && !s.count(x)) {
                    s.insert(x);
                    q.push(x);
                }
                if (se.count(y) && !s.count(y)) {
                    s.insert(y);
                    q.push(y);
                }
            }
            while (q.size()) {
                auto t = q.front();
                q.pop();
                for (int x : mp[t]) {
                    se.insert(x);
                    if (!s.count(x)) {
                        q.push(x);
                        s.insert(x);
                    }
                }
            }
            i = j;
        }
        
        vector<int> ans;
        for (auto i : se)
            ans.push_back(i);
        return ans;
    }
};

