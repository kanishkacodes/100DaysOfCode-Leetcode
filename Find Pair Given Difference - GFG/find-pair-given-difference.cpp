//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


#include <algorithm> // for sort function

bool findPair(int arr[], int size, int n) {
    // Sort the array in ascending order
    std::sort(arr, arr + size);
    
    // Initialize low and high pointers
    int left = 0;  // low pointer
    int right = 1;  // high pointer
    
    // Iterate until low and high pointers are within array bounds
    while (left < size && right < size) {
        int diff = arr[right] - arr[left];  // Calculate the difference between elements
        
        // Check if the difference matches the given value n
        if (diff == n)
            return true;
        
        // If the difference is smaller than n, move the high pointer
        else if (diff < n)
            right++;
        
        // If the difference is greater than n, move the low pointer
        else
            left++;
        
        // If low and high pointers are pointing to the same element, move the high pointer
        if (right == left)
            right++;
    }
    
    // No pair with the given difference found
    return false;
}
