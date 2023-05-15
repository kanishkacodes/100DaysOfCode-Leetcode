class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n, 0);
        int maxReach = 0;
        int steps = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, nums[i] + i);

            if (i == currentEnd) {
                steps++;
                currentEnd = maxReach;

                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return steps;
    }
};
