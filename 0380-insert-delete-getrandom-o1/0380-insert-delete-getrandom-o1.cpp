class RandomizedSet {
public:
unordered_set<int> check;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(check.count(val)){
            return false;
        }

        check.insert(val);
        return true;
    }
    
    bool remove(int val) {
        
        if(check.count(val)){
            check.erase(val);
            return true;
        }

        return false;
    }
    
    int getRandom() {
        vector<int> temp(check.begin(), check.end()); // Convert set to vector
        return temp[rand() % temp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */