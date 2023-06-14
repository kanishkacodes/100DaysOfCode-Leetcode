class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSubset;
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates
        backtrack(0, currSubset, nums, ans);
        return ans;
    }

private:
    void backtrack(int index, vector<int>& currSubset, vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(currSubset);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue; // Skip duplicate elements
            }

            currSubset.push_back(nums[i]);
            backtrack(i + 1, currSubset, nums, ans);
            currSubset.pop_back();
        }
    }
};
