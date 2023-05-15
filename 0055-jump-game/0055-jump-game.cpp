class Solution
{
    public:
        bool canJump(vector<int> &nums)
        {
            int n = nums.size() - 1;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (i + nums[i] >= n)	//The condition i + nums[i] >= n is checking whether the current index i combined with the maximum jump value from that position, nums[i], is greater than or equal to the previous minimum index n.
                {
                    n = i;
                }
            }

            return (n == 0);
        }
};