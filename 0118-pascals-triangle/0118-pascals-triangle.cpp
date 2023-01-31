class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec(numRows);
        for(int i=0;i<numRows;i++){
          for(int j=0;j<=i;j++){
            if(j==0 or j==i)
                vec[i].push_back(1);
            else 
                vec[i].push_back(vec[i-1][j-1]+vec[i-1][j]);
            }
        }
        return vec;
    }
};