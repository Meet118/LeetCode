class TopVotedCandidate {
public:
    vector<pair<int, int>> a;
    int n;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int max_cnt = 0;
        int cand = 0;
        n = persons.size();
        a.resize(n);
        vector<int> cnt(n);
        for (int i = 0; i < n; i ++ ) {
            cnt[persons[i]] ++ ;
            if (cnt[persons[i]] >= max_cnt) {
                max_cnt = cnt[persons[i]];
                cand = persons[i];
            }
            a[i] = {times[i], cand};
        }
    }
    
    int q(int t) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1>> 1;
            if (a[mid].first <= t) l = mid;
            else r = mid - 1;
        }
        return a[l].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
