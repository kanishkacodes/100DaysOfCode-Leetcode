class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int i = 0;
        int j = n - 1;

        while (i < m && j >= 0) {
            if (grid[i][j] < 0) {
                count += m - i;  // Increment count by the number of negative elements in the current column
                j--;             // Move to the previous column
            } else {
                i++;             // Move to the next row
            }
        }

        return count;
    }
};
