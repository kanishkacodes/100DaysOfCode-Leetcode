class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        int currentReach = 0;
        int nextReach = 0;

        for (int i = 0; i < n - 1; i++) {
            nextReach = max(nextReach, nums[i] + i);

            if (i == currentReach) {
                steps++;
                currentReach = nextReach;

                if (currentReach >= n - 1)
                    break;
            }
        }

        return steps;
    }
};
