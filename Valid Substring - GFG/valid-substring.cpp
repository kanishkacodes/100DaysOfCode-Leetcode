//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
public:
    int findMaxLen(string s) {
        stack<int> stk;
        stk.push(-1); // Initialize the stack with a sentinel value

        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i); // Update the sentinel value
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }

        return maxLen;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends