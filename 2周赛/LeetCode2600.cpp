class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> x;
        for (int i = 0; i < numOnes; i ++ ) x.push_back(1);
        for (int i = 0; i < numZeros; i ++ ) x.push_back(0);
        for (int i = 0; i < numNegOnes; i ++ ) x.push_back(-1);
        int ans = 0;
        for (int i = 0; i < x.size() && i < k; i ++ ) ans += x[i];
        return ans;
    }
};

