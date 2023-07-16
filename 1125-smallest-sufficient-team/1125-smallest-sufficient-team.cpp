class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& a)
    {
        int n = req.size();
        
        map<string,int>m;
        
        for(int i=0;i<req.size();i++)
        {
            m[req[i]] = i;
        }
        
        vector<vector<int>>v;
        
        for(int i=0;i<a.size();i++)
        {
            vector<int>t;
            for(int j=0;j<a[i].size();j++)
            {
                t.push_back(m[a[i][j]]);
            }
            v.push_back(t);
        }
        
        unordered_map<int,vector<int>>dp;
         
        dp.reserve(1<<n);
        dp[0] = {};
        
        for(int i=0;i<v.size();i++)
        {
            int cur_skill = 0;
            for(int j=0;j<v[i].size();j++)
            {
                  cur_skill = (cur_skill)|(1<<v[i][j]);
            } 
            
            for(auto it = dp.begin(); it!= dp.end() ;it++)
            {
                int comb = (cur_skill)|(it->first);
                if(dp.find(comb)==dp.end() or dp[comb].size()>1+dp[it->first].size())
                {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        } 
        
        return dp[(1<<n)-1];
    }
};