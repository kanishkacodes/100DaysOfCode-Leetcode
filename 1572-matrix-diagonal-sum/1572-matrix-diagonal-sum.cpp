class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int sum = 0;
        
        
        for (int i = 0 ; i < m ; i++){
            
            sum+= mat[i][i];
            sum+= mat[i][m-1-i];
            
        }
        
        if (m%2 != 0){
            
            sum-=mat[m/2][m/2];
            
        }
        
        return sum;
    }
};