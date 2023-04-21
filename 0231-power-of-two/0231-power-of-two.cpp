class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {return true;}  
        else if (n < 2) {return false;} 
        
        while (n%2 == 0 && n != 0) { 
            if (n != 2) {n = n/2;}
            else {n = 0;}  
        }
        
        return (n == 0);
    }
};