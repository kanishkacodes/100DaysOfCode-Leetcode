//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long int product = 1;

        // Check if any element is zero
        bool hasZero = false;
        int zeroCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                hasZero = true;
                zeroCount++;
            } else {
                product *= nums[i];
            }
        }

        vector<long long int> p(n, 0);
        
        if (hasZero) {
            if (zeroCount == 1) {
                for (int i = 0; i < n; i++) {
                    if (nums[i] == 0) {
                        p[i] = product;
                        break;
                    }
                }
            }
            // For more than one zero, product will be zero for all indices
        } else {
            for (int i = 0; i < n; i++) {
                p[i] = product / nums[i];
            }
        }

        return p;
    }
};




//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends