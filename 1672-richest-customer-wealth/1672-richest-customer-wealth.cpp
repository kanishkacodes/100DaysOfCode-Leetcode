class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
        int m = v.size() , n= v[0].size() ;
        int maxi = INT_MIN;
        for(int i=0;i<m;i++){
            int sum =0 ;
            for(int j=0;j<n;j++){
                sum += v[i][j];
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};