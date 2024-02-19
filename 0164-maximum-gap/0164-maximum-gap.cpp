class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int maxDiff = INT_MIN;
        int diff = INT_MIN;
        
        if(nums.size() < 2){
            return 0;
        }
        else {
            sort(nums.begin(), nums.end());
        
            for (int i = 0; i < nums.size() - 1; i++) {
                diff = nums[i + 1] - nums[i];
                maxDiff = max(diff, maxDiff);
            }
        }
        
        return maxDiff;
    }
};
