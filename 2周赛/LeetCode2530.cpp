class Solution {
public:
    typedef long long ll;
    
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll> q;
        int n = nums.size();
        for (int i = 0; i < n; i ++ ) {
            q.push(nums[i]);
        }
        ll ans = 0;
        while (k) {
            auto t = q.top();
            q.pop();
            ans += t;
            q.push((t + 2) / 3);
            k -- ;
        }
        return ans;
    }
};

