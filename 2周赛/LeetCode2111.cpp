class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        
        for (int i = 0; i < k; i ++ ) {
            vector<int> a;
            int st = i;
            while (st < n) {
                a.push_back(arr[st]);
                st += k;
            }
            int cnt = longup(a);
            ans += a.size() - cnt;
        }
        return ans;
    }
    
    int longup(vector<int> &a) {
        vector<int> b;
        for (int x : a) {
            if (b.empty() || x >= b.back()) b.push_back(x);
            else {
                int t = upper_bound(b.begin(), b.end(), x) - b.begin();
                b[t] = x;
            }
        }
        return b.size();
    }
};

