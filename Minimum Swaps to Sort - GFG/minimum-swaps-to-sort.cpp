//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arrPos(n);

        // Store the array elements with their positions
        for (int i = 0; i < n; i++) {
            arrPos[i] = make_pair(nums[i], i);
        }

        // Sort the array positions based on values
        sort(arrPos.begin(), arrPos.end());

        vector<bool> visited(n, false);
        int minSwaps = 0;

        for (int i = 0; i < n; i++) {
            // If the current element is already visited or in the correct position, continue to the next iteration
            if (visited[i] || arrPos[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            // Find the cycle size by traversing the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arrPos[j].second;
                cycleSize++;
            }

            minSwaps += cycleSize - 1;
        }

        return minSwaps;
    }
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends