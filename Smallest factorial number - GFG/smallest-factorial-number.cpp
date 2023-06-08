//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findNum(int n) {
        int start = 0; // Initialize the start of the search space
        int end = 5 * n; // Initialize the end of the search space

        while (start <= end) {
            int mid = (start + end) / 2; // Calculate the midpoint of the search space
            int count = getTrailingZeroesCount(mid); // Get the count of trailing zeroes for the current number

            if (count < n) {  // it means that the current mid number does not have enough trailing zeroes in its factorial. In this case, we update start to be mid + 1, indicating that we should search in the right half of the remaining search space.
                start = mid + 1; // Adjust the search space to the right half if count is less than n
            } else {
                end = mid - 1; // it means that the current mid number has at least n trailing zeroes in its factorial. In this case, we update end to be mid - 1, indicating that we should search in the left half of the remaining search space.
            }
        }

        return start; // Return the smallest number with at least n trailing zeroes
    }


    int getTrailingZeroesCount(int num) {
        int count = 0; // Initialize the count of trailing zeroes
        int divisor = 5; // Initialize the divisor as 5 (factor we are counting)

        while (divisor <= num) {
            count += num / divisor; // Add the quotient of num divided by divisor to the count
            divisor *= 5; // Multiply divisor by 5 to consider the next higher power of 5
        }

        return count; // Return the count of trailing zeroes
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