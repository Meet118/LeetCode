class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> se;
        for (auto s : emails) {
            int pos = s.find('@');
            string t;
            for (int i = 0; i < pos; i ++ ) {
                if (s[i] == '+')
                    break;
                if (s[i] != '.')
                    t += s[i];
            }
            se.insert(t + s.substr(pos));
        }
        return se.size();
    }
};

