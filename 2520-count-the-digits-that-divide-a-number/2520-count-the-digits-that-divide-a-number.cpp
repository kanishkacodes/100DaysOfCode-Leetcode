class Solution {
public:
    int countDigits(int num) {
        int n = num, ans = 0;
        while(num>0){
            ans += (n%(num%10)==0);
            num /= 10;
        }
        return ans;
    }
};