class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0, n = words.size();
        for (int i = 0; i < n; i ++ )
            if (check(s, words[i])) ans ++ , cout << words[i] << endl;
        return ans;
    }

    bool check(string a, string b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) return false;
            int x = 1, y = 1;
            while (i + 1 < a.size() && a[i] == a[i + 1]) i ++ , x ++ ;
            while (j + 1 < b.size() && b[j] == b[j + 1]) j ++ , y ++ ;
            if (!(x == y || x >= 3 && x > y)) return false;
            i ++ , j ++ ;
        }
        return i == a.size() && j == b.size();
    }
};
