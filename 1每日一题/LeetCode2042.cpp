class Solution {
public:
    bool areNumbersAscending(string s) {
        int la = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (!isdigit(s[i])) continue;
            int j = i;
            while (j < s.size() && isdigit(s[j])) j ++ ;
            string t = s.substr(i, j - i);
            int num = stoi(t);
            if (num <= la) return false;
            la = num;
            i = j;
        }
        return true;
    }
};
