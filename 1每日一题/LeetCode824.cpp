class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> se {'a', 'e', 'i', 'o', 'u'};
        string ans;
        int idx = 1;
        for (int i = 0, j = 0; i < sentence.size(); ) {
            j = i;
            while (j < sentence.size() && sentence[j] != ' ') j ++ ;
            string s = sentence.substr(i, j - i);
            char c = tolower(s[0]);
            if (se.count(c)) 
                ans += s + "ma";
            else 
                ans += s.substr(1, s.size() - 1) + s[0] + "ma";
            ans += string(idx, 'a') + ' ';
            idx ++ ;
            i = j + 1;
        }
        ans.pop_back();
        return ans;
    }
};
