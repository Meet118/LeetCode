class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.size() > s2.size()) return areSentencesSimilar(s2, s1);
        stringstream ssin1(s1), ssin2(s2);
        vector<string> a, b;
        string s;
        while (ssin1 >> s) a.push_back(s);
        while (ssin2 >> s) b.push_back(s);
        int i = 0, j = a.size() - 1;
        for (int k = 0; k < b.size() && i < a.size(); k ++ ) {
            if (a[i] == b[k]) i ++ ;
            else break;
        }
        for (int k = b.size() - 1; k >= 0 && j >= 0; k -- ) {
            if (a[j] == b[k]) j -- ;
            else break;
        }
        return i > j;
    }
};
