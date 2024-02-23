class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        if (isSorted(nums)) {
            return true;
        }

        for (int rotations = 1; rotations < n; rotations++) {
            
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + 1);
            reverse(nums.begin() + 1, nums.end());

            if (isSorted(nums)) {
                return true;
            }
        }

        return false;
    }

private:
    bool isSorted(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
