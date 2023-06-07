//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;  // Pointer for arr1
        int j = 0;  // Pointer for arr2
        int count = 0;  // Count of elements merged so far

        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                count++;
                if (count == k) {
                    return arr1[i];
                }
                i++;
            } else {
                count++;
                if (count == k) {
                    return arr2[j];
                }
                j++;
            }
        }

        // If there are remaining elements in arr1, add them to the count
        while (i < n) {
            count++;
            if (count == k) {
                return arr1[i];
            }
            i++;
        }

        // If there are remaining elements in arr2, add them to the count
        while (j < m) {
            count++;
            if (count == k) {
                return arr2[j];
            }
            j++;
        }

        // If k is out of range, return -1 or any suitable value
        return -1;
    }
};



//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends