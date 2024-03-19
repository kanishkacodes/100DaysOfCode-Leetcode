class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        
        int low = maxi;
        int high = sum;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int noofdays = finddays(weights, mid);
            
            if (noofdays <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int finddays(vector<int>& v, int capacity) {
        int totaldays = 1;
        int load = 0;
        
        for (int i = 0; i < v.size(); i++) {
            if (v[i] + load > capacity) {
                totaldays++;
                load = 0;
            }
            load += v[i];
        }
        
        return totaldays;
    }
};
