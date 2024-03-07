class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {

           	// Find the size of rows (m)
            int m = matrix.size();

           	// Find the size of columns (n)
            int n = matrix[0].size();
            

            int col0 = 1;

            for (int i = 0; i < m; i++)
            {

                for (int j = 0; j < n; j++)
                {

                    if (matrix[i][j] == 0)
                    {

                        matrix[i][0] = 0;

                        if (j != 0)
                        {

                            matrix[0][j] = 0;
                        }
                        else
                        {
                            col0 = 0;
                        }
                    }
                }
            }

            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (matrix[i][j] != 0)
                    {

                        if (matrix[0][j] == 0 || matrix[i][0] == 0)
                        {

                            matrix[i][j] = 0;
                        }
                    }
                }
            }

            if (matrix[0][0] == 0)
            {

                for (int j = 0; j < n; j++)
                {
                    matrix[0][j] = 0;
                }
            }

            if (col0 == 0)
            {

                for (int i = 0; i < m; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
};