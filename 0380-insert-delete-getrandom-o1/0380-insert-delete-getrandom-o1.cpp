class RandomizedSet {
private:
    vector<int>v;
    unordered_map<int,int>mp;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val] > 0){
            return false;
        }
        else{
            v.push_back(val);
            mp[val] = v.size();//store index in map
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp[val] == 0){
            return false;
        }
        else{
            int last = v.back();
            v[mp[val]-1] = v.back();
            v.pop_back();
            mp[last] = mp[val];
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */