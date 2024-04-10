class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
    int i=0;
        int j=arr.size()-1;
        
        while(i < j && j-i+1 != k) {
            
            int diff1 = abs(arr[i] - x);
            int diff2 = abs(arr[j] - x);
            
            
            if(diff1 <= diff2) {
                j--;
            } 
            else {
                i++;
            }
        }
        
        vector<int> ans;
    
        for(int x=i;x<=j;x++) {
            ans.push_back(arr[x]);
        }
    
        return ans;
    }
};