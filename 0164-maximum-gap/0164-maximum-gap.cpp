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


//In the loop where you calculate the differences between adjacent elements, you are accessing nums[i+1] without checking if i+1 is a valid index. This will result in an out-of-bounds access issue when i reaches the last index.

//To fix this, you should iterate up to nums.size() - 1 in the loop. 