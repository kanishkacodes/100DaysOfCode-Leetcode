//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> nums1;
        vector<int> nums2;
        
        for (int i = 0 ; i < n ; ++i){
            if ( arr[i] >= 0 ){
                nums1.push_back(arr[i]);
            }
            
        }
            
        for (int i = 0 ; i < n ; ++i){
            if ( arr[i] < 0 ){
                nums2.push_back(arr[i]);
            }
            
        }
        for (int i = 0 ; i < nums2.size() ; ++i){
            nums1.push_back(nums2[i]);
        }
        for (int i = 0; i < n; ++i) {
            arr[i] = nums1[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends