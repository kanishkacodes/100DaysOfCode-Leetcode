class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicate i
            
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicate j
                
                int k = j + 1;
                int l = n - 1;
                
                while (k < l) {
                    
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                    
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++; // Skip duplicate k
                        while (k < l && nums[l] == nums[l + 1]) l--; // Skip duplicate l
                    } 
                    else if (sum < target) {
                        k++;
                    } 
                    else {
                        l--;
                    }
                }
            }
        }
        
        return ans;
    }
};
