class Solution {
public:
    vector<int> constructRectangle(int area) {
    
        for (int x = sqrt(area); ; x -- ) {
            if (area % x == 0)
                return {area / x, x};
        }
        return {};
    }
};