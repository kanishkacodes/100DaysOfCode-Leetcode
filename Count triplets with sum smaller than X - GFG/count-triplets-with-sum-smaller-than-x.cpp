//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long countTriplets(long long arr[], int n, long long sum) {
        sort(arr, arr + n); // Sort the array in ascending order
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1; // Pointer for the left element
            int right = n - 1; // Pointer for the right element

            while (left < right) {
                long long tripletSum = arr[i] + arr[left] + arr[right];
                if (tripletSum < sum) {
                    // If the sum of the triplet is less than the target sum,
                    // then all the elements between left and right (inclusive) can be included
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }
};


//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends