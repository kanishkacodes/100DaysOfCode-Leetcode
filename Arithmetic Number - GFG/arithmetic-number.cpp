//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int inSequence(int A, int B, int C) {
        // Calculate the difference between B and A
        int difference = B - A;
        
        // If the common difference is non-zero
        if (C != 0) {
            // If the difference is divisible evenly by C
            if (difference % C == 0 && difference / C >= 0) {
                return 1;  // B exists in the arithmetic sequence
            }
        }
        // If the common difference is zero and A is equal to B
        else if (A == B) {
            return 1;  // B exists in the arithmetic sequence
        }
        
        return 0;  // B does not exist in the arithmetic sequence
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends