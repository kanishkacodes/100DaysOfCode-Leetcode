#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();

        if (n <= 2) {
            return 0; // No trapping is possible with less than 3 elements
        }

        std::vector<int> lb(n);
        std::vector<int> rb(n);

        // Filling the left boundary
        lb[0] = height[0];
        for (int i = 1; i < n; i++) {
            lb[i] = std::max(lb[i - 1], height[i]);
        }

        // Filling the right boundary
        rb[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rb[i] = std::max(rb[i + 1], height[i]);
        }

        int totalWater = 0;

        for (int i = 1; i < n - 1; i++) {
            int possibleWaterHeight = std::min(lb[i], rb[i]);
            totalWater += std::max(0, possibleWaterHeight - height[i]);
        }

        return totalWater;
    }
};
