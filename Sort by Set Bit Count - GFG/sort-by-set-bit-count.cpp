//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <algorithm>
using namespace std;

class Solution {
public:
    // Comparison function to compare integers based on set bit count
    static bool comp(int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    
    // Function to sort the array based on set bit count of elements
    void sortBySetBitCount(int arr[], int n) {
        stable_sort(arr, arr + n, comp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends