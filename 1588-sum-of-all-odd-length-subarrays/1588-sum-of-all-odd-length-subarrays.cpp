class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int l=1;
        int sum=0;
        while(l<=arr.size()){
            int i=0,j=l,temp=0;
            for(int j=0;j<l;++j){
                temp+=arr[j];
            }
            sum+=temp;
            for(int j=l;j<arr.size();++j,++i){
                temp=temp+arr[j]-arr[i];
                sum+=temp;
            }
            l+=2;
        }
        return sum;
    }
};