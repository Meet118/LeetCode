class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = INT_MAX;
        while (l < r) {
            int mid = (long long)l + r >> 1;
            if (check(mid, houses, heaters)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool check(int x, vector<int>& houses, vector<int>& heaters) {
        for (int i = 0, j = 0; i < houses.size(); i ++ ) {
            while (j < heaters.size() && abs(heaters[j] - houses[i]) > x)
                j ++ ;
            if (j == heaters.size())
                return false;
        }
        return true;
    }
};
