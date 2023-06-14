class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used; // Track used elements to avoid duplicates

        for (int i = index; i < nums.size(); i++) {
            // Check if the current element has already been used at this index
            if (used.find(nums[i]) != used.end()) {
                continue;
            }

            // Add the current element to the set of used elements
            used.insert(nums[i]);

            swap(nums[index], nums[i]);
            backtrack(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(0, nums, ans);
        return ans;
    }
};
