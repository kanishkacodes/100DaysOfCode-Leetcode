//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        // Vector to store the product except self at each index
        vector<long long int> p(n), q(n);

        // Calculate prefix products
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * nums[i - 1];
        }

        // Calculate suffix products
        q[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            q[i] = q[i + 1] * nums[i + 1];
        }

        // Calculate product except self using prefix and suffix products
        for (int i = 0; i < n; i++) {
            nums[i] = p[i] * q[i];
        }

        return nums;
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