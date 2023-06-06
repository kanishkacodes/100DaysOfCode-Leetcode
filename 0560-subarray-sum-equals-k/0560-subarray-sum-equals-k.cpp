class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount; // Map to store prefix sums and their counts
        
        // Initialize the map with prefix sum 0
        prefixSumCount[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            // Check if there is a prefix sum that complements the current sum to reach k
            int complement = sum - k;
            if (prefixSumCount.find(complement) != prefixSumCount.end()) {
                count += prefixSumCount[complement];
            }
            
            // Increment the count of the current prefix sum
            prefixSumCount[sum]++;
        }
        
        return count;
    }
};
