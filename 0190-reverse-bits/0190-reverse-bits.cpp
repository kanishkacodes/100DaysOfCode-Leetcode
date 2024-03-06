class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bits = "";
        
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)) bits.push_back('1');
            else bits.push_back('0');
        }
        
        uint32_t ans = 0;
        for(int i = 31, j = 0; i >= 0; i--){
            if(bits[j++] == '1') ans = ans | (1 << i);
        }
        return ans;
    }
};