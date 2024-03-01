class Solution {
public:
    int fungcd(int a, int b) {
    int rem = a % b;
    while (rem != 0) {
        a = b;
        b = rem;
        rem = a % b;
    }
    return b;
}

    int findGCD(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        
        for (int i = 0 ; i < nums.size() ; i ++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        
        int gcd = fungcd(maxi , mini);
        
        return gcd;
        
        
    }
};