class Solution {
public:
    
    int fact(int f){
        
        int multi = f;
        
        if( f == 0 ){
            return 1;
        }
        
        else{
            
            for (int i = 1 ; i < f ; i++){
                
                multi = multi * (f-i);
            }
            
            return multi;
        }
        
    }
    
   int trailingZeroes(int n) {
        int count = 0;

        // Count the number of factors of 5 in the factorial
        while (n >= 5) {
            n /= 5;
            count += n;
        }

        return count;
    }
};