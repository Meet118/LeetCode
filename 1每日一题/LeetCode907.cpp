class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        int ans = 0;
        stack<int> stk;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i ++ ) {
            l[i] = -1;
            while (stk.size() && arr[stk.top()] > arr[i]) stk.pop();
            if (stk.size()) l[i] = stk.top();
            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for (int i = n - 1; i >= 0; i -- ) {
            r[i] = n;
            while (stk.size() && arr[stk.top()] >= arr[i]) stk.pop();
            if (stk.size()) r[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; i ++ )
            ans = (ans + (long long)(r[i] - i) * (i - l[i]) * arr[i] % mod) % mod;
        return ans;
    }
};
