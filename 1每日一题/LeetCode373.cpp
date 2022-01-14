//多路归并
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        int n = a.size(), m = b.size();
        for (int i = 0; i < m; i ++ ) heap.push({a[0] + b[i], 0, i});
        while (k -- && heap.size()) {
            auto t = heap.top();
            heap.pop();
            ans.push_back({a[t[1]], b[t[2]]});
            if (t[1] + 1 < n)
                heap.push({a[t[1] + 1] + b[t[2]], t[1] + 1, t[2]});
        }
        return ans;
    }
};

//二分
typedef long long ll;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int l = nums1[0] + nums2[0], r = nums1.back() + nums2.back();
        while (l < r) {
            ll mid = l + r + 1 >> 1;
            if (check(nums1, nums2, mid) < (ll)k) l = mid;
            else r = mid - 1;
        }
        vector<vector<int>> ans;
        for (int num : nums1) {
            for (int i = 0; i < nums2.size() && ans.size() < k; i ++ )
                if (num + nums2[i] < l)
                    ans.push_back({num, nums2[i]});
                else break;
            if (ans.size() == k)
                break;
        }

        unordered_map<int, int> mp;
        for (int x : nums2)
            mp[x] ++ ;

        for (int i = 0; i < nums1.size() && ans.size() < k; i ++ ) {
            if (mp.count(l - nums1[i]))
                for (int j = 0; j < mp[l - nums1[i]] && ans.size() < k; j ++ )
                    ans.push_back({nums1[i], l - nums1[i]});
        }
        return ans;
    }

    ll check(vector<int>& a, vector<int>& b, ll x) {
        ll cnt = 0;
        for (ll num : a) {
            if (num + b[0] >= x) break;
            int l = 0, r = b.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (num + b[mid] < x) l = mid;
                else r = mid - 1;
            }
            cnt += l + 1;
        }
        return cnt;
    }
};

