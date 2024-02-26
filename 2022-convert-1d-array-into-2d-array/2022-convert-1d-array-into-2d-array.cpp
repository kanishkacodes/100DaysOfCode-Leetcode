class Solution {
public:
    vector<std::vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();

        // Check if the size of the original vector is compatible with the dimensions m and n
        if (size != m * n) {
            return {};
        }

        vector<vector<int>> result(m, vector<int>(n, 0));

        // Fill the 2D array by iterating through the original vector
        for (int i = 0; i < size; ++i) {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};
