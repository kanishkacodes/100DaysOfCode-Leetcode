class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int n = nums.size();
            k = k % n;	// Adjust k if it is greater than n

           	//For example, let's say we have an array nums with size n = 5 and we want to rotate it by k = 7 positions. Without the adjustment, rotating by k = 7 would result in unnecessary full rotations. However, with the adjustment k = k % n, we have k = 7 % 5 = 2, which limits the rotation to the desired amount.
            
            
            // Main Logic : Reverse the whole array---Reverse the first k elements---Reverse the remaining n-k elements
            reverse(nums.begin(), nums.end());	// Reverse the whole array
            reverse(nums.begin(), nums.begin() + k);	// Reverse the first k elements
            reverse(nums.begin() + k, nums.end());	// Reverse the remaining n-k elements
        }
};