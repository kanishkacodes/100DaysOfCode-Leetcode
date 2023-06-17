//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





// Function to swap two characters in a string
void swap(string& str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

class Solution {
public:
    // Recursive function to find the largest number after k swaps
    void findMaximumNumUtil(string& str, int k, string& maxNum, int idx) {
        // Base case: If k swaps are used or we have reached the end of the string
        if (k == 0 || idx == str.length()) {
            return;
        }

        char maxDigit = str[idx];
        int n = str.length();

        // Find the maximum digit from the remaining string
        for (int i = idx + 1; i < n; i++) {
            if (str[i] > maxDigit) {
                maxDigit = str[i];
            }
        }

        // If the maximum digit is already equal to the current digit, no need to swap
        if (maxDigit == str[idx]) {
            findMaximumNumUtil(str, k, maxNum, idx + 1);
            return;
        }

        // Try all possible swaps with the maximum digit
        for (int i = idx + 1; i < n; i++) {
            if (str[i] == maxDigit) {
                // Swap the digits
                swap(str, idx, i);

                // Check if the current number is larger than the maximum number found so far
                if (str > maxNum) {
                    maxNum = str;
                }

                // Recursive call with k-1 swaps and the next index
                findMaximumNumUtil(str, k - 1, maxNum, idx + 1);

                // Revert the swap
                swap(str, idx, i);
            }
        }
    }

    string findMaximumNum(string str, int k) {
        string maxNum = str;
        findMaximumNumUtil(str, k, maxNum, 0);
        return maxNum;
    }
};



//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends