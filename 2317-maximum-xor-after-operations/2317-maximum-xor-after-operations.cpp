class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int size=nums.size(),xoR=0;
        for(auto it:nums)
            xoR^=it;
        for(int i=0;i<32;i++){
            if((xoR & 1<<i))
                continue;
            for(int j=0;j<size;j++){
                if((nums[j] & 1<<i)){
                    xoR^=1<<i;
                    break;
                }
            }
        }
        return xoR;
    }
};