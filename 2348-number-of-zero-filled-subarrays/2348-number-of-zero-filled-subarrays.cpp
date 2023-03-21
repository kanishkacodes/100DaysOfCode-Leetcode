class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    
        int n = nums.size();
        long long count = 0, zeros = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;  // increment the count of consecutive zeros
            } else {
                // calculate the number of subarrays of consecutive zeros and add to count
                count += (zeros * (zeros + 1)) / 2;
                zeros = 0;  // reset the count of consecutive zeros
            }
        }
        
        if (zeros > 0) {
        // add the number of subarrays of consecutive zeros seen so far (if any)
        count += (zeros * (zeros + 1))/2;
        }
        
        return count;
    }
};