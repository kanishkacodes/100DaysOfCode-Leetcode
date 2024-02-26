#include <vector>

class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int count = 0;
        int m = mat.size();
        int n = (m > 0) ? mat[0].size() : 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    int rowsum = 0;
                    int colsum = 0;

                    // Check the entire column for the presence of 1
                    for (int p = 0; p < m; p++) {
                        colsum += mat[p][j];
                    }

                    // Check the entire row for the presence of 1
                    for (int q = 0; q < n; q++) {
                        rowsum += mat[i][q];
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
