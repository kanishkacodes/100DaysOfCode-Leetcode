class Solution {
public:
int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp){
    int n=triangle.size();
     if(i==n-1){
        return triangle[i][j];

    }
    if(dp[i][j]!=-1) return dp[i][j];
  
    int d=INT_MAX;
    int r=INT_MAX;

        d=solve(i+1,j,triangle,dp);
        r=solve(i+1,j+1,triangle,dp);
    
   
    return dp[i][j]=triangle[i][j]+min({d,r});

}
    int minimumTotal(vector<vector<int>>& triangle) {
        
         int n=triangle.size();
    
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,triangle,dp);
    }
};