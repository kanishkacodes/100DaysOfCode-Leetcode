class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet Alice(n);
        DisjointSet Bob(n);
        int ans = 0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 3){
                bool a = Alice.findUPar(edges[i][1]) == Alice.findUPar(edges[i][2]);
                bool b = Bob.findUPar(edges[i][1]) == Bob.findUPar(edges[i][2]);
                if(a && b)
                    ans++;
                else if(!a && b)
                    Alice.unionByRank(edges[i][1],edges[i][2]);
                else if(a && !b)
                    Bob.unionByRank(edges[i][1],edges[i][2]);
                else if(!a && !b){
                    Alice.unionByRank(edges[i][1],edges[i][2]);
                    Bob.unionByRank(edges[i][1],edges[i][2]);
                }
            }
        }

        for(int i=0;i<edges.size();i++){
            if(edges[i][0] == 1){
                bool a = Alice.findUPar(edges[i][1]) == Alice.findUPar(edges[i][2]);
                if(a)
                    ans++;
                else
                    Alice.unionByRank(edges[i][1],edges[i][2]);
            }
            else if(edges[i][0] == 2){
                bool b = Bob.findUPar(edges[i][1]) == Bob.findUPar(edges[i][2]);
                if(b)
                    ans++;
                else
                    Bob.unionByRank(edges[i][1],edges[i][2]);
            }
        }
        int al = Alice.findUPar(1);
        int bo = Bob.findUPar(1);
        for(int i=1;i<=n;i++){
            if(al != Alice.findUPar(i))
                return -1;
            if(bo != Bob.findUPar(i))
                return -1;
        }
        return ans;
    }
};