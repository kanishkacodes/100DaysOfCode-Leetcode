//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution {
public:
    // Helper function to check if it is possible to allocate the books with the given maximum pages
    bool isPossible(int A[], int N, int M, int maxPages) {
        int students = 1;
        int pagesAllocated = 0;
        
        // Iterate over the books and allocate them to the students
        for (int i = 0; i < N; i++) {
            // If the current book cannot be allocated to the current student
            // then allocate it to a new student
            if (A[i] > maxPages) {
                return false;
            }
            
            // If allocating the current book to the current student exceeds the maximum pages,
            // allocate it to a new student
            if (pagesAllocated + A[i] > maxPages) {
                students++;
                pagesAllocated = A[i];
                
                // If the number of students exceeds the given number of students (M),
                // then it is not possible to allocate the books with the given maximum pages
                if (students > M) {
                    return false;
                }
            } else {
                pagesAllocated += A[i];
            }
        }
        
        return true;
    }

    // Function to find the minimum number of pages.
    int findPages(int A[], int N, int M) {
        // If the number of books is less than the number of students, it is not possible to allocate books
        if (N < M) {
            return -1;
        }
        
        // Calculate the minimum and maximum possible values for the maximum number of pages allocated to a student.
        int low = *max_element(A, A + N);
        int high = accumulate(A, A + N, 0);
        
        int result = -1;
        
        // Perform binary search within the range of possible maximum pages
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if it is possible to allocate books with the current mid value
            if (isPossible(A, N, M, mid)) {
                result = mid;
                high = mid - 1; // Look for smaller maximum pages in the left half
            } else {
                low = mid + 1; // Look for larger maximum pages in the right half
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends