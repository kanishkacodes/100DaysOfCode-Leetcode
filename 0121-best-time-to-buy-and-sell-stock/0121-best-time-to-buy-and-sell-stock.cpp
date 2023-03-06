//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& v) {
        int a=INT_MIN,b=INT_MAX;
        int ans=-1;
        for(int i=0;i<v.size();i++){
        
            b=min(b,v[i]);
ans=max(ans,v[i]-b);
        }
        return ans;
    }
};