class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxlength = INT_MIN;
        int length = 0;
        int n = nums.size();
        
        
        for (int i = 0 ; i < n ; i ++){
            
            if (nums[i] == 1){
                length++;
            }
            
            else if (nums[i] != 1){
                length=0;
            }
            
            maxlength = max(length,maxlength);
        } 
        
        
        return maxlength;
    }
};