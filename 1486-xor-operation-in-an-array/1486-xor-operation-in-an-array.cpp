class Solution {
public:
    int xorOperation(int n, int start) {
        int nums[n];
        int i;
        for(i=0;i<n;i++){
            nums[i]=start+(2*i);
        }
        int bitwise=0;
        for(i=0;i<n;i++){
            bitwise=bitwise^nums[i];
        }
        return bitwise;
    }
    
};