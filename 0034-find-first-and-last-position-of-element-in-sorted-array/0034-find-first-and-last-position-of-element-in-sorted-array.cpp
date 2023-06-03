class Solution {
public:
    int leftMost(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;
        int mid;
        int ans = -1;  // Initialize ans

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }

    int rightMost(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;
        int mid;
        int ans = -1;  // Initialize ans

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftMost(nums, target);
        int right = rightMost(nums, target);

        return {left, right};
    }
};
