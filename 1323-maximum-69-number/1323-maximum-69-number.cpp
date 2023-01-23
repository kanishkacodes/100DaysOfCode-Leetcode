class Solution {
public:
    int maximum69Number (int num) {
        int i=1;
        int temp = num;
        int leftmost_six = -1;
        while(temp > 0){
            int d = temp%10;
            if(d == 6){
                leftmost_six = i;
            }
            temp /= 10;
            i*=10;
        }
         return ( leftmost_six == -1 ? num : num + 3 * leftmost_six );
    }
};