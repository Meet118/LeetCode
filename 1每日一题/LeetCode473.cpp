class Solution {
public:
    vector<int> nums;
    int n;
    vector<int> st;

    bool dfs(int start, int cur, int sum, int cnt) {
        if (cnt == 3) return true;
        if (cur == sum) return dfs(0, 0, sum, cnt + 1);
        for (int i = start; i < n; i ++ ) {
            if (st[i]) continue;
            if (cur + nums[i] <= sum) {
                st[i] = true;
                if (dfs(i + 1, cur + nums[i], sum, cnt))
                    return true;
                st[i] = false;
            }
            if (!cur || cur + nums[i] == sum) return false;
            while (i + 1 < n && nums[i] == nums[i + 1])
                i ++ ;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        nums = matchsticks;
        n = nums.size();
        st.resize(n);
        if (n == 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum % 4 != 0) return false;
        sum /= 4;
        return dfs(0, 0, sum, 0);
    }
};
