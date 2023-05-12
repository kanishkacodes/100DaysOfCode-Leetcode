class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int maxProfit = 0;
            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[i - 1])
                {
                    int best = prices[i] - prices[i - 1];
                    maxProfit+=best;
                }
            }
            return maxProfit;
        }
};