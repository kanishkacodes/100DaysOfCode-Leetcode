class Solution {
public:
    bool isit(int num){
        int originalnum = num;
        while(num > 0){
        int digit = num%10;
        if (digit == 0 or originalnum % digit != 0 ){
            return false;
        }
        num/=10;
        }
        
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int>res;
        for (int i = left ; i <= right ; i ++){
            if (isit(i)){
                res.push_back(i);
            }
        }
        
        return res ;
        
    }
};