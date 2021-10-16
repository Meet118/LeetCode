typedef long long ll;
class Solution {
public:
    vector<string> ans;
    string p;

    void dfs(string& num, int u, int n, ll a, ll b, int len, int target) {
        if (u == n) {
            if (a == target)
                ans.push_back(p.substr(0, len - 1));
            return;
        }

        ll c = 0;
        for (int i = u; i < num.size(); i ++ ) {
            c = c * 10 + num[i] - '0';
            p[len ++ ] = num[i];
            //+
            p[len] = '+';
            dfs(num, i + 1, n, a + b * c, 1, len + 1, target);

            if (i < num.size() - 1) {
                //-
                p[len] = '-';
                dfs(num, i + 1, n, a + b * c, -1, len + 1, target);

                //*
                p[len] = '*';
                dfs(num, i + 1, n, a, b * c, len + 1, target);
            }
            
            if (num[u] == '0')
                break;
        }
    }

    vector<string> addOperators(string num, int target) {
        p.resize(100);
        int n = num.size();
        dfs(num, 0, n, 0, 1, 0, target);
        return ans;
    }
};