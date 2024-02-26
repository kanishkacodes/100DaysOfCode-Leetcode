class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();

        // Check if the size of the original vector is compatible with the dimensions m and n
        if (size != m * n) {
            return {};
        }
        
        //initializes a 2D vector named result with dimensions m rows and n columns. Each element in the vector is    initialized with the value 0.

        vector<vector<int>> result(m, vector<int>(n, 0));
        
        

        // Fill the 2D array by iterating through the original vector
        for (int i = 0; i < size; ++i) {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};

// When i is 0:

// mat[0 / 2][0 % 2] evaluates to mat[0][0]
// When i is 1:

// mat[1 / 2][1 % 2] evaluates to mat[0][1]
// When i is 2:

// mat[2 / 2][2 % 2] evaluates to mat[1][0]
// When i is 3:

// mat[3 / 2][3 % 2] evaluates to mat[1][1]
// When i is 4:

// mat[4 / 2][4 % 2] evaluates to mat[2][0]