//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends






class Solution {
public:
    vector<string> find_permutation(string S) {
        vector<string> permutations;
        sort(S.begin(), S.end());  // Sort the string to get permutations in lexicographically sorted order
        vector<bool> used(S.length(), false);  // Keep track of used characters
        string currentPermutation;
        findUniquePermutations(S, used, currentPermutation, permutations);
        return permutations;
    }

private:
    void findUniquePermutations(const string& S, vector<bool>& used, string& currentPermutation, vector<string>& permutations) {
        if (currentPermutation.length() == S.length()) {
            permutations.push_back(currentPermutation);  // Add the current permutation to the result
            return;
        }

        for (int i = 0; i < S.length(); i++) {
            if (used[i] || (i > 0 && S[i] == S[i - 1] && !used[i - 1]))
                continue;  // Skip used or duplicate characters

            used[i] = true;  // Mark the current character as used
            currentPermutation.push_back(S[i]);  // Add the current character to the current permutation
            findUniquePermutations(S, used, currentPermutation, permutations);  // Recursively find permutations
            currentPermutation.pop_back();  // Backtrack by removing the last character
            used[i] = false;  // Mark the current character as unused for the next iteration
        }
    }
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends