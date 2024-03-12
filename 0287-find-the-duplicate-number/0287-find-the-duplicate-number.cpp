class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

             for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            if (count <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

//The inner for loop has a time complexity of O(n) because it iterates over the entire array of length n. However, since it is nested inside the while loop, and the while loop performs a binary search with log n iterations, the overall time complexity becomes O(n log n).

