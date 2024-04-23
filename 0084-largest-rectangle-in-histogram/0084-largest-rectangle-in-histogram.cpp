class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int> s;
        int maxarea = 0;
        
        
        s.push(-1);
        
        for (int i = 0 ; i < n ; i++){
            
            while ( s.size() > 1 && heights[s.top()] > heights[i]){
                
                int h = heights[s.top()];
                s.pop();
                int lb = s.top();
                int rb = i;
                int w = rb - lb - 1;
                int area = h * w;
                
                maxarea = max (maxarea , area);
                
            }
            
            s.push(i);
            
        }
        
        while (s.size() > 1){
            
            int h = heights[s.top()];
                s.pop();
                int lb = s.top();
                int rb = heights.size();
                int w = rb - lb - 1;
                int area = h * w;
                
                maxarea = max (maxarea , area);
            
        }
        
        return maxarea;
        
    }
};