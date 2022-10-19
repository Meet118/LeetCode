class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int a = 0, b = 0;
        for (int i : students) 
            if (i == 0) a ++ ;
            else b ++ ;
        int ans = sandwiches.size();
        for (int i = 0; i < sandwiches.size(); i ++ , ans -- ) {
            if (sandwiches[i] == 0) {
                if (a > 0) a -- ;
                else break;
            }
            else {
                if (b > 0) b -- ;
                else break;
            }
        }
        return ans;
    }
};
