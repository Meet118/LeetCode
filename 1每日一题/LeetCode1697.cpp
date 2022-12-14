const int N = 1e5 + 10;

class Solution {
public:
    struct Node {
        int a, b, c, d;

        bool operator < (const Node& a) const {
            return c < a.c;
        }
    };

    vector<int> p;
    vector<Node> q;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size());
        p.resize(n);
        for (int i = 0; i < n; i ++ ) {
            p[i] = i;
        }
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        for (int i = 0; i < queries.size(); i ++ ) {
            q.push_back({queries[i][0], queries[i][1], queries[i][2], i});
        }
        sort(q.begin(), q.end());
        for (int i = 0, j = 0; i < queries.size(); i ++ ) {
            while (j < edgeList.size() && edgeList[j][2] < q[i].c) {
                int a = edgeList[j][0], b = edgeList[j][1];
                j ++ ;
                p[find(a)] = p[find(b)];
            }
            ans[q[i].d] = p[find(q[i].a)] == p[find(q[i].b)];
        }
        return ans;
    }
};
