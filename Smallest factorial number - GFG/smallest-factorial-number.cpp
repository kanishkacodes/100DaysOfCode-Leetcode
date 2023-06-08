//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findNum(int n) {
        int start = 0;
        int end = 5 * n;

        while (start <= end) {
            int mid = (start + end) / 2;
            int count = getTrailingZeroesCount(mid);

            if (count < n) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start;
    }

private:
    int getTrailingZeroesCount(int num) {
        int count = 0;
        int divisor = 5;

        while (divisor <= num) {
            count += num / divisor;
            divisor *= 5;
        }

        return count;
    }
};



//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends