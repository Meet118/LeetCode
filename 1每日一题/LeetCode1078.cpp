class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> a;
        for (int i = 0; i < text.size();) {
            int j = i + 1;
            while (j < text.size() && text[j] != ' ') j ++ ;
            a.push_back(text.substr(i, j - i));
            i = j + 1;
        }

        vector<string> ans;
        for (int i = 0; i + 2 < a.size(); i ++ ) {
            if (a[i] == first && a[i + 1] == second)
                ans.push_back(a[i + 2]);
        }

        return ans;
    }
};
