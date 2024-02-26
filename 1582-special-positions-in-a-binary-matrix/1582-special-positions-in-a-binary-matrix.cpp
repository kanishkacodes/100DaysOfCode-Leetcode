#include <vector>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = 0;
        if (m > 0){
            n = mat[0].size();
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int rowsum = 0;
                    int colsum = 0;

                    // Corrected loop bounds and indexing for column sum
                    for (int p = 0; p < m; p++) {
                        // Fixed indexing from mat[i][p] to mat[p][j]
                        colsum += mat[p][j];  // <-- Fixed
                    }

                    // Corrected loop bounds and indexing for row sum
                    for (int q = 0; q < n; q++) {
                        // Fixed indexing from mat[q][j] to mat[i][q]
                        rowsum += mat[i][q];  // <-- Fixed
                    }

                    // If the current element is the only 1 in its row and column
                    if (rowsum == 1 && colsum == 1) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
