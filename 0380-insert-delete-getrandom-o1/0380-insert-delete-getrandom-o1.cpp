class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(ump.count(val)) return false;
        nums.push_back(val);
        ump.insert({val, nums.size()-1});
        return true;
        
    }
    
    bool remove(int val) {
        if(!ump.count(val)) return false;
        int last = nums.back();
        ump[last] = ump[val];
        nums[ump[val]] = last;
        nums.pop_back();
        ump.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
        
    }
    private:
        vector<int>nums;
        unordered_map<int, int>ump;
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */