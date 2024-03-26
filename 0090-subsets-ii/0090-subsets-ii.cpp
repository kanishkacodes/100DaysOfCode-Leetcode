class Solution {
public:
    
    void backtrack(int index, vector<int>&v, vector<int>nums, vector<vector<int>>&ans, bool previous){
        
        if (index == nums.size()){
            ans.push_back(v);
        }
        else {
            backtrack(index+1,v,nums,ans,false);
            
            if (index>0 && nums[index] == nums[index-1] && (!previous)){
                return;
            }
            
            v.push_back(nums[index]);
            backtrack(index+1 , v, nums, ans ,true);
            
            
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector <int>>ans;
        vector<int>v;
        backtrack(0,v,nums,ans,false);
        return ans;
    }
};