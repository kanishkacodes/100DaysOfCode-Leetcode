class Solution {
public:
    bool dfs(int node , vector<vector<int>>& graph , vector<int>& vis , vector<int>& dfsVisited , vector<int>& check){
        vis[node] = 1;
        dfsVisited[node] = 1;
        check[node] = 0;
        for (int neighbour : graph[node]){
            if (!vis[neighbour]){
                if (dfs(neighbour , graph , vis , dfsVisited , check))
                    return true;
            }
            else if (dfsVisited[neighbour]){
                return true;
            }
        }
        check[node] = 1;
        dfsVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;

        vector<int> vis(graph.size());
        vector<int> dfsVisited(graph.size());
        vector<int> check(graph.size());

        for (int i=0 ; i<graph.size() ; i++){
            if (!vis[i]){
                dfs(i , graph , vis , dfsVisited , check);
            }
        }    

        for (int i=0 ; i<graph.size() ; i++){
            if (check[i]==1)
                ans.push_back(i);
        }

        return ans;
    }
};