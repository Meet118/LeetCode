class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> sl1, sl2, sr1, sr2;
        int n = nums.size();
        vector<int> l1(n), l2(n), r1(n), r2(n);
        for (int i = 0; i < n; i ++ ) {
            while (sl1.size() && nums[i] <= nums[sl1.top()]) sl1.pop();
            if (sl1.size()) l1[i] = sl1.top();
            else l1[i] = -1;
            sl1.push(i);
            while (sl2.size() && nums[i] >= nums[sl2.top()]) sl2.pop();
            if (sl2.size()) l2[i] = sl2.top();
            else l2[i] = -1;
            sl2.push(i);
        }
        for (int i = n - 1; i >= 0; i -- ) {
            while (sr1.size() && nums[i] < nums[sr1.top()]) sr1.pop();
            if (sr1.size()) r1[i] = sr1.top();
            else r1[i] = n;
            sr1.push(i);
            while (sr2.size() && nums[i] > nums[sr2.top()]) sr2.pop();
            if (sr2.size()) r2[i] = sr2.top();
            else r2[i] = n;
            sr2.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i ++ ) {
            ans -= (long long)nums[i] * (i - l1[i]) * (r1[i] - i);
            ans += (long long)nums[i] * (i - l2[i]) * (r2[i] - i);
        }
        return ans;
    }
};
