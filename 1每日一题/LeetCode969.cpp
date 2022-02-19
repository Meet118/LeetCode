class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for (int i = n - 1; i > 0; i -- ) {
            int k = 0;
            for (int j = 0; j <= i; j ++ )
                if (arr[j] > arr[k])
                    k = j;
            if (k == i)
                continue;
            if (k != 0) {
                reverse(arr.begin(), arr.begin() + k + 1);
                ans.push_back(k + 1);
            }
            reverse(arr.begin(), arr.begin() + i + 1);
            ans.push_back(i + 1);
        }
        return ans;
    }
};
