class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            unordered_map<string, vector < string>> m;
            for (int i; i < strs.size(); ++i)
            {
                string temp = strs[i];
                sort(strs[i].begin(), strs[i].end());
                m[strs[i]].push_back(temp);
            }
            
            vector<vector<string>> result;
            
            for(auto it = m.begin(); it != m.end() ; ++it){
                result.push_back(it->second);
                
            }
            
            return result;
        }
};