class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size(), m = 0;
        for (int i = 0; i < n; i ++ ) {
            m = max(arr[i], m);
            if (m == i) ans ++ ;
        }
        return ans;
    }
};
