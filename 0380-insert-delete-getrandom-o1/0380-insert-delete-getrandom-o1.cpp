class RandomizedSet {
    unordered_map<int, int> index;
    vector<int>value;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(index.count(val) > 0){
            if(index[val] >= 0){
                return false;
            }
            
        }
        this->value.push_back(val);
        this->index[val] = this->value.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(index.count(val) > 0){
            if(index[val] >= 0){
                index[value.back()] = index[val];
                value[index[val]] = value.back();
                index[val] = -1;
                value.pop_back();
                return true;
            }
        }
        return false;
    }
    
    int getRandom() {
        return value[rand()%value.size()];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */