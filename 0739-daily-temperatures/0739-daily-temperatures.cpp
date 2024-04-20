class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);
        
        
        
        for (int i = 0 ; i < n ; i++){
            
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                
                int index = s.top();
                ans[index] = i - index;
                s.pop();
                
            }

            s.push(i);
            
        }
        
        return ans;
        
    }
};