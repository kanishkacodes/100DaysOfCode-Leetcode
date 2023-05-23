class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int longest = 1;
        unordered_set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }
        for (auto num : s) {
            if (s.find(num - 1) == s.end()) {
                int count = 1;
                int currentNum = num;
                while (s.find(currentNum + 1) != s.end()) {
                    count++;
                    currentNum = currentNum + 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
