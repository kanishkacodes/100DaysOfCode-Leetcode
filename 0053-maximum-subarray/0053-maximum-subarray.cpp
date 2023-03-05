class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxSum = nums[0];
      int sum = 0;
    for (int i = 0 ; i < nums.size() ; ++i){
       sum = sum + nums[i];
       maxSum = max(sum,maxSum);
       if( sum < 0 ){
         sum = 0;
       }
    
        
    }
       return maxSum;
    }
    
    
};