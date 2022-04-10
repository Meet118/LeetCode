class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> a = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> se;
        for (auto s : words) {
            string t;
            for (char c : s)
                t += a[c - 'a'];
            se.insert(t);
        }
        return se.size();
    }
};
