class Solution {
public:
    int numberOfMatches(int n) {
       int match=0;
       while(n!=1){
           if(n%2!=0){
               match+=(n-1)/2;
               n=((n-1)/2)+1;
           }
           else if(n%2==0){
               match+=n/2;
               n=n/2;
           }
       } 
       return match;
    }
};