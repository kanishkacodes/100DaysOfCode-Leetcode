class Solution {
public:

    int mySqrt(int x) {
         int l=0,h=x;
         int ans;
        while(l<=h){

           long long int mid=l+(h-l)/2;
           long long int sq=mid*mid;

           if(sq==x){
               ans=mid;
               break;
            }
            else if(sq<x){
                //mid=ans;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};