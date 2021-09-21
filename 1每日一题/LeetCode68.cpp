class Solution {
public: 
    vector<string> fullJustify(vector<string>& words, int m) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0, j = 0; i < n; i ++ ) {
            j = i;
            int cnt = 0;
            int sum = 0;
            vector<string> t;
            while (j < n && cnt + words[j].size() <= m) {
                t.push_back(words[j]);
                cnt += words[j].size() + 1;
                sum += words[j].size();
                j ++ ;
            }
            int words_cnt = t.size();
            int per_space = 0;
            string res = "";
            if (words_cnt > 1 && j != n) {
                per_space = (m - sum) / (words_cnt - 1);
                int pre_cnt = (m - sum) % (words_cnt - 1);
                // cout << per_space << ' ' << pre_cnt << endl;
                for (int k = 0; k < t.size(); k ++ ) {
                    res += t[k];
                    if (k + 1 < t.size()) {
                        int space_cnt = per_space;
                        if (k < pre_cnt)
                            space_cnt ++ ;
                        for (int u = 0; u < space_cnt; u ++ )
                            res += ' ';
                    }
                }
                while (res.size() < m)
                    res += ' ';
            }
            else {
                per_space = m - sum;
                for (auto k : t) {
                    res += k;
                    if (res.size() + 1 <= m)
                        res += ' ';
                }
                while (res.size() < m)
                    res += ' ';
            }

            ans.push_back(res);
            i = j - 1;
        }

        return ans;
    }
};