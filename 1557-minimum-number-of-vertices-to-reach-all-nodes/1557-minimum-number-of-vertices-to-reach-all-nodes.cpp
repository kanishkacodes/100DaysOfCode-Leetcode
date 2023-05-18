class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> isSource(n, true);

        for (const auto& edge : edges) {
            int destination = edge[1];
            isSource[destination] = false;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (isSource[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
