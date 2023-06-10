class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        
        double ans = 1;
        unsigned long long m = n;
        if (n < 0) {
            x = 1 / x;
            m = -m;
        }
        
        while (m > 0) {
            if (m % 2 == 1) {
                ans *= x;
                m -= 1;
            } else {
                x *= x;
                m /= 2;
            }
        }
        
        return ans;
    }
};

