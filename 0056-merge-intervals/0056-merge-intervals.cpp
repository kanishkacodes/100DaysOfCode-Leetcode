class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        
        // Sort intervals based on the start values
        sort(intervals.begin(), intervals.end());
        
        
        
        for (int i = 0; i < n; ++i) {
            
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                // Non-overlapping interval, or the first interval
                ans.push_back(intervals[i]);
            } 
            
            else {
                // Overlapping interval, merge them
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        
        return ans;
    }
};