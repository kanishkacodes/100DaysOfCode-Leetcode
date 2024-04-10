class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        
        // Count occurrences of each number
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        
        vector<int> result;
        int threshold = nums.size() / 3;
        
        // Check if the count of each number exceeds the threshold
        for (auto it : m) {
            if (it.second > threshold) {
                result.push_back(it.first);
            }
        }
        
        return result;
    }
};