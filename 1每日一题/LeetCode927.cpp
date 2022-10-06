class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> p(6); //记录三段1的位置
        int sum = 0;
        for (int i : arr) sum += i;
        if (sum == 0) return {0, 2}; //全是0
        if (sum % 3) return {-1, -1}; //将1分段
        sum /= 3;
        for (int i = 0, j = 0, s = 0; i < arr.size(); i ++ ) {
            s += arr[i];
            if (arr[i] == 1 && (s % sum == 1 || s % sum == 0)) {
                p[j ++ ] = i;
                if (sum == 1)
                    p[j ++ ] = i;
            }
        }
        int z = 0; //0的个数
        for (int i = arr.size() - 1; i >= 0; i -- , z ++ )
            if (arr[i] == 1)
                break;

        if (p[1] + z >= p[2] || p[3] + z >= p[4]) return {-1, -1};
        if (!check(arr, p[0], p[1] + z, p[2], p[3] + z)) return {-1, -1};
        if (!check(arr, p[0], p[1] + z, p[4], p[5] + z)) return {-1, -1};
        return {p[1] + z, p[3] + z + 1};
    }

    bool check(vector<int> arr, int a, int b, int c, int d) {
        for (int i = a, j = c; i <= b; i ++ , j ++ ) {
            if (arr[i] != arr[j]) return false;
        }
        return true;
    }
};
