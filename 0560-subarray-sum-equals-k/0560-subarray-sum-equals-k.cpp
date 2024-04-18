class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        int presum = 0;
        unordered_map<int,int>m;
        
         m[0] = 1;
        
        
        for (int i = 0 ; i < n ; i++){
            
            presum+=nums[i];
            
            if (m.find(presum-k) != m.end()){  // if the presum-k is present
                
                count+= m[presum-k];  // increse the count by presum-k value in map
                
            }
            
            m[presum]++;   // added new presum or incresed its frequency/ count
        }
        
        
        return count;
        
    }
};