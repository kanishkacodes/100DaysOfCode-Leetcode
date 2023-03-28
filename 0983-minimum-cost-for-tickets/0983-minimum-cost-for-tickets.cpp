class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int ndays = days[n-1];
        vector<int> dp(ndays+1); // days
        for (int i=1; i<=ndays; i++){
            if (find(days.begin(), days.end(), i)!=days.end()){ //if travel day, try all these types of passes and choose the min cost
                int a = ((i-1)>=0)?dp[i-1]:0;
                int b = ((i-7)>=0)?dp[i-7]:0;
                int c = ((i-30)>=0)?dp[i-30]:0; 
                dp[i] = min(min(a + costs[0], b+costs[1]), c+costs[2]); 
            } else {
                dp[i] = dp[i-1]; // if not a travel day, copy the previous day
            }       
        }
        return dp[ndays];
    }
};