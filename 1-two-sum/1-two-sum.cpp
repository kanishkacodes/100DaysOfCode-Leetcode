class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        vector <int> sol;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i!=j){
                    if(nums[i]+nums[j]==target){
                        sol.push_back(i);
                        sol.push_back(j);
                        return sol;
                    }
                }
            }
            
        }
        return sol;
        
    }
};