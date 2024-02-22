class Solution {
public:
    
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            // int temp = nums[start];
            // nums[start] = nums[end];
            // nums[end] = temp;
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = k % n; // To handle cases where k > n

        // Reverse the entire array
        reverseArray(nums, 0, n - 1);
        
        // Reverse the first part of the array (0 to k-1)
        reverseArray(nums, 0, k - 1);
        
        // Reverse the second part of the array (k to n-1)
        reverseArray(nums, k, n - 1);
    }
};
