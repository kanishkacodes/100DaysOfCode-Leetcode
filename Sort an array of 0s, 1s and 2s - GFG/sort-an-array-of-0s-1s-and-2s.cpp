//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[a[i]]++;
        }
        
        vector<int>nums;
        
        for (auto ct : m) {
            int element = ct.first;
            int count = ct.second;
            for (int i = 0; i < count; ++i) {
                nums.push_back(element);  
            }
        }
        
        for (int i = 0; i < n; ++i) {
            a[i] = nums[i];
        }
        
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends