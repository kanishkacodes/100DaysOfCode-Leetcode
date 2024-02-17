class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
//         vector<int>ans;
        
//         for (int i = 0 ; i < nums.size() ; i++){
            
//             ans.push_back(nums[i]);
//         }
//         for (int i = 0 ; i < nums.size() ; i++){
            
//             ans.push_back(nums[i]);
//         }
//         return ans;
        
        
    
        int n = nums.size();
        
        nums.resize( 2*n);
        
        for(int i = 0; i < n; i++){
            
            nums[n + i] = nums[i];
        }
        return nums;

    }
};
