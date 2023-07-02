class Solution {
public:
int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
    int n=grid.size();
    int m=grid[0].size();
    if(i==n-1 && j==m-1){
        return grid[i][j];

    }
    if(dp[i][j]!=-1) return dp[i][j];
    int r=INT_MAX;
    int d=INT_MAX;
    if(i+1<n ){
        d=solve(i+1,j,grid,dp);
    }
    if(j+1<m) r=solve(i,j+1,grid,dp);
   
    return dp[i][j]=grid[i][j]+min(r,d);

}
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
    int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,grid,dp);
    }
};