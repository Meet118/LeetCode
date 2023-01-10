class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> a(26), b(26);
        for (auto c : word1) a[c - 'a'] ++ ;
        for (auto c : word2) b[c - 'a'] ++ ;
        int n1 = 0, n2 = 0;
        for (int i = 0; i < 26; i ++ ) {
            if (a[i] > 0) n1 ++ ;
            if (b[i] > 0) n2 ++ ;
        }
        for (int i = 0; i < 26; i ++ )
            if (a[i] > 0)
                for (int j = 0; j < 26; j ++ )
                    if (b[j] > 0) {
                        if (i == j) { //字符相等时，不同字符的数目要相等
                            if (n1 == n2) return true;
                        }
                        else {
                        	// 否则模拟最后的结果
                            int c1 = n1, c2 = n2;
                            if (a[i] - 1 == 0) c1 -- ;
                            if (a[j] == 0) c1 ++ ;
                            if (b[j] - 1 == 0) c2 -- ;
                            if (b[i] == 0) c2 ++ ;
                            if (c1 == c2)
                                return true;
                        }
                    }
        return false;
    }
};

