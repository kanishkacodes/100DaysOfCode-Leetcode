class Solution {
public:
    int differenceOfSums(int n, int m) {
        int s1=0;
        int s2=0;
        
        for(int i=1;i<=n;i++){
            if(i%m==0){
                s2+=i;
            }
            else{
                s1+=i;
            }
        }
        return s1-s2;
    }
};