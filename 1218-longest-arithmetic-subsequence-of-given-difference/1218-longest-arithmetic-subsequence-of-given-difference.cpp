class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int score = 0;
        unordered_map<int,int> exists;
        for (int k = 0; k < arr.size(); k++) {
            exists[arr[k]] = exists[arr[k] - difference] + 1;
            score = exists[arr[k]] > score ? exists[arr[k]] : score;
        }
        return score;
    }
};