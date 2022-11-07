class Solution {
public:
    vector<string> get_vec(string s, int start, int end) {
        vector<string> res;
        if (s[end] != '0') {
            for (int i = start + 1; i <= end; i ++ ) {
                if (i - start >= 1 && end - i + 1 >= 1)
                    res.push_back(s.substr(start, i - start) + '.' + s.substr(i, end - i + 1));
                else
                    break;
                if (s[start] == '0' && s[start + 1] == '0' || s[start] == '0') break;
            }
        }
        if (s[start] != '0' || s[start] == '0' && start == end) {
            res.push_back(s.substr(start, end - start + 1));
        }
        return res;
    }

    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1, s.size() - 2);
        int n = s.size();
        for (int i = 0; i < n - 1; i ++ ) {
            vector<string> a = get_vec(s, 0, i);
            vector<string> b = get_vec(s, i + 1, n - 1);
            for (auto i : a)
                for (auto j : b) {
                    ans.push_back('(' + i + ", " + j + ')');
                }
        }
        return ans;
    }
};
