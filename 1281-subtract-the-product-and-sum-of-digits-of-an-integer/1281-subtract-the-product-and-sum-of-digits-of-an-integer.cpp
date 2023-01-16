class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp = 1;
        int sum = 0;
        while( n!= 0){
            int d=n%10;
            sum = sum + d;
            temp = temp*d;
            n = n/10;
        }
        int sub = temp-sum;
        return sub;
        
        
    }
};