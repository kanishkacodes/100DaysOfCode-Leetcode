class Solution {
public:
    bool isPalindrome(int n) { 
       if(n<0){
           return false;
       }
       long long temp = 0, check=n;
    while (n > 0)
    {
        int d = n % 10;
        n /= 10;
        temp = temp * 10 + d;
    }
        if (temp==check){
            return true;
        }
        return false;
    }
};