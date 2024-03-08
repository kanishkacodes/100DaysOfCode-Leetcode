class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int dip = -1;
        
        // Find the "dip" index
        for (int i = n - 2; i >= 0; i--) {
            
            if (nums[i] < nums[i + 1]) {
                
                dip = i;
                break;
                
            }
            
        }
        
        // If no dip is found, reverse the entire array
        if (dip == -1) {
            
            reverse(nums.begin(), nums.end());
            
        } else {
            
            // Find the smallest element greater than dip
            for (int i = n - 1; i > dip; i--) {
                
                if (nums[i] > nums[dip]) {
                    
                    // Fix: Swap with nums[dip] changed to swap with nums[i-1]
                    swap(nums[i], nums[dip]);
                    break;
                    
                }
                
            }
            
            // Reverse the remaining elements to get the next permutation
            reverse(nums.begin() + dip + 1, nums.end());
        }
        
    }
};
