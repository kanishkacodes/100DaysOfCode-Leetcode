class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
           ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int>m;
        for (int i = 0 ; i < nums.size() ; ++i){
            m[nums[i]]++;
        }
        for (auto &it : m){
            if (it.second > 1){
                return true;
            }
            }
        
     
        
        
        return false;
    }
};