class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> se;
        for (int x : candyType)
            se.insert(x);
        return min(se.size(), candyType.size() / 2);
    }
};