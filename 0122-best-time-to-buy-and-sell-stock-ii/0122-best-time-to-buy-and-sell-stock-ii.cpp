class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int maxProfit = 0;
            
            // Logic : Calculte the profit and add them.
            
            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[i - 1]) // Profit Should not be negative
                {
                    int best = prices[i] - prices[i - 1];
                    maxProfit+=best;
                }
            }
            return maxProfit;
        }
};