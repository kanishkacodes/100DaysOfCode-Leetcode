class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        vector <int> leftmax(n);
        vector <int> rightmin(n);
        
        leftmax[0] = arr[0];
        rightmin[n-1] = arr[n-1];
        
        for (int i = 1; i < n ; i++){
            leftmax[i] = max(arr[i],leftmax[i-1]);
        }
        
        for (int i = n-2 ; i >= 0 ; i--){
            rightmin[i] = min(arr[i], rightmin[i+1]);
        }
        
        int chunks = 0;
        for (int i = 0 ; i < n -1 ; i++){
            if (leftmax[i]<=rightmin[i+1]){
                chunks++;
            }
        }
        
        return chunks+1;
    }
};