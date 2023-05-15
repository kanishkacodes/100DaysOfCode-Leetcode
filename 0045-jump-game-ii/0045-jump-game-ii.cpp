class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        int currentMaxReach = nums[0];
        int nextMaxReach = nums[0];
        int steps = 1;

        for (int i = 1; i < n; i++) {
            if (i > currentMaxReach) {
                currentMaxReach = nextMaxReach;
                steps++;

                if (currentMaxReach >= n - 1)
                    return steps;
            }

            nextMaxReach = max(nextMaxReach, nums[i] + i);
        }

        return steps;
    }
};
