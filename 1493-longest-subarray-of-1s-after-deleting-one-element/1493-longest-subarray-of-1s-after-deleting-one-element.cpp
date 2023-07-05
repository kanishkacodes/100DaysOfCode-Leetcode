class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int D = 0;
        int N = nums[0] == 1 ? 1 : 0;
        
        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == 0){
                D = N;
                N = 0;
            }else{
                D = max(D + 1, N);
                N = N + 1;
            }
            
            res = max(res, D);
        }
        
        return res == INT_MIN ? 0 : res;
    }
};