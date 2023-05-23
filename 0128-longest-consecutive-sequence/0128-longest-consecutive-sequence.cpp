class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int longest = 1;
        unordered_set<int> uniqueSet;
        for (auto num : nums) {
            uniqueSet.insert(num);
        }
        for (auto num : uniqueSet) {
            if (uniqueSet.find(num - 1) == uniqueSet.end()) {
                int count = 1;
                int currentNum = num;
                while (uniqueSet.find(currentNum + 1) != uniqueSet.end()) {
                    count++;
                    currentNum = currentNum + 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
