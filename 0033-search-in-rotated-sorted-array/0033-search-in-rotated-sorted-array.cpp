class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int dip = findRotationPoint(nums);

        // Binary search in the first sorted part
        int result = binarySearch(nums, target, 0, dip - 1);

        // If not found in the first part, search in the second sorted part
        if (result == -1) {
            result = binarySearch(nums, target, dip, nums.size() - 1);
        }

        return result;
    }

private:
    int findRotationPoint(const vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }

        return low;
    }

    int binarySearch(const vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Target not found
    }
};
