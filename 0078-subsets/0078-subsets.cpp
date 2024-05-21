class Solution {
public:
    
    void backtrack(int index, vector<int>&v,vector<int>&nums,vector<vector<int>>&ans){
        
        if (index == nums.size()){
            ans.push_back(v);
        }
        else{
            
            v.push_back(nums[index]);// takinf the element
            backtrack(index+1,v,nums,ans);
            
            
            v.pop_back();// this is the backtrack part not taking the element 
            backtrack(index+1,v,nums,ans);
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector <vector <int>>ans;
        vector<int>v;
        backtrack(0,v,nums,ans);
        return ans;
        
    }
};