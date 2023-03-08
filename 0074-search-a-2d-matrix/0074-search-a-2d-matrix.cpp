class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0,e=(matrix.size()*matrix[0].size())-1,mid=0;
        int rind,cind;
        int m=matrix[0].size();
        while(s<=e)
        {
            mid=s+(e-s)/2;
            rind=mid/m;
            cind=mid%m;
            
            if(matrix[rind][cind]==target)
            return true;
            else if (matrix[rind][cind]<target)
            s=mid+1;
            else
            e=mid-1;
        }
        return false;
    }
};