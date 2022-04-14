class RandomizedSet {
public:
    vector<int> a;
    unordered_map<int, int> mp;
    int idx = 0;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (mp.count(val))
            return false;
        mp[val] = idx ++ ;
        a.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val))
            return false;
        mp[a[idx - 1]] = mp[val];
        swap(a[idx - 1], a[mp[val]]);
        a.pop_back();
        mp.erase(val);
        idx -- ;
        return true;
    }
    
    int getRandom() {
        return a[rand() % idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
