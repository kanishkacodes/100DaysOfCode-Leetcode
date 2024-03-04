class Solution {
public:
    int uniquePaths(int m, int n) {
     
        int N = m + n - 2;  // (m-1)+(n-1)
        int r = m - 1;      // or I can take n-1 also
        long long result = 1;  // Use long long to avoid integer overflow
        
        for (int i = 1; i <= r; i++) {
            result = result * (N - r + i) / i;   // Ncr formula   
        }
        
        return static_cast<int>(result);  // Cast back to int before returning
    }
};


//aslo solve pascal triangle