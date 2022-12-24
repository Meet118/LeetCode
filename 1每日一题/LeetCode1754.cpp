class Solution {
public:
    string largestMerge(string word1, string word2) {
        string s;
        int n = word1.size(), m = word2.size();
        for (int i = 0, j = 0; i < n || j < m;) {
            if (i < n && j < m) {
                if (word1[i] > word2[j]) {
                    s += word1[i ++ ];
                } else if (word1[i] < word2[j]) {
                    s += word2[j ++ ];
                } else {
                    int x = i, y = j;
                    while (x < n && y < m && word1[x] == word2[y]) x ++ , y ++ ;
                    if (word1[x] > word2[y]) {
                        s += word1[i ++ ];
                    } else {
                        s += word2[j ++ ];
                    }
                }
            } else if (i < n) {
                s += word1[i ++ ];
            } else if (j < m) {
                s += word2[j ++ ];
            }
        }
        return s;
    }
};
