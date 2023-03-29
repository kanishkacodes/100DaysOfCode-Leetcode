class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n= nums.size();
        int total = n*(n+1)/2 ;
        for ( int i = 0 ; i < nums.size(); ++i){
            sum = sum + nums[i];
        }
        int ans = total-sum;
        return ans;
        
    }
};