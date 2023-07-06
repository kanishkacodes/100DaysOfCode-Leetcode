//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++


class Solution {
public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> result;
        
        if (n == 0) {
            return result;
        }
        
        set<int> sortedSet;
        result.resize(n);
        result[n - 1] = -1;
        sortedSet.insert(arr[n - 1]);
        
        for (int i = n - 2; i >= 0; i--) {
            auto it = sortedSet.upper_bound(arr[i]);
            
            if (it != sortedSet.end()) {
                result[i] = *it;
            } else {
                result[i] = -1;
            }
            
            sortedSet.insert(arr[i]);
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends