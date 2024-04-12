class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        int count = 0;
        int sum = 0;
        
        // Add 0 as prefix sum with frequency 1 to handle subarrays starting from index 0
        prefixSumFreq[0] = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            sum += nums[i];
            // Check if there exists a prefix sum (sum - k)
            // If yes, then there exists a subarray with sum k
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }
            // Increment the frequency of the current prefix sum
            prefixSumFreq[sum]++;
        }
        
        return count;
    }
};