class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int m = 1;
        for(int i=1; i<=n; i++) {
            res = res + m;
            if(i%7==0) m = i/7;
            m++;
        }
        return res;
    }
};