//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        vector<long long> result(n, -1); // Initialize result vector with -1

        stack<int> st; // Stack to store indices

        for (int i = 0; i < n; i++) {
            // If stack is not empty and current element is greater than the
            // element at the index stored in the stack, update the result
            while (!st.empty() && arr[i] > arr[st.top()]) {
                result[st.top()] = arr[i]; // Update result for the top element
                st.pop(); // Remove the processed element from the stack
            }
            
            st.push(i); // Push the current index to the stack
        }

        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends