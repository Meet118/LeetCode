class Solution {
public:
    int lengthLongestPath(string input) {
        int ans = 0;
        stack<string> stk;
        int cur = 0, sum = 0;
        int i = 0;
        while (i < input.size() && input[i] != '\n') i ++ ;
        stk.push(input.substr(0, i));
        sum += i;
        if (i == input.size() && input.find('.') != -1)
            ans = input.size();
        for (int j = 0; i < input.size(); ) {
            j = i + 1;
            int k = 0;
            while (j < input.size() && input[j] == '\t')
                j ++ , k ++ ;
            bool f = false;
            while (j < input.size() && input[j] != '\n') {
                if (input[j] == '.')
                    f = true;
                j ++ ;
            }
            string s = input.substr(i + k + 1, j - i - k - 1);
            i = j;
            while (cur >= k) {
                sum -= stk.top().size();
                stk.pop();
                cur -- ;
            }
            stk.push(s);
            sum += s.size();
            cur = k;
            if (f)
                ans = max(ans, sum + (int)stk.size() - 1);
        }
        return ans;
    }
};
