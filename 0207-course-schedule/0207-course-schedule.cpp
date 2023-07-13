class Solution {
  int m;
  vector<vector<int>> g;
  vector<bool> seen, active;
  void addEdge(int u, int v) {
    g[u].push_back(v);
  }
  bool has_cycle(int u) {
    if (seen[u]) return false;
    seen[u] = true;
    active[u] = true;
    for (int v : g[u]) {
      if (active[v] || has_cycle(v))
        return true;
    }
    active[u] = false;
    return false;
  }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
      m = numCourses;
      g = vector<vector<int>>(m);
      for (int i = 0; i < pre.size(); i++) {
        addEdge(pre[i][1], pre[i][0]);
      }
      active = seen = vector<bool>(m,false);
      for (int i = 0; i < numCourses; i++) {
        if (has_cycle(i))
          return false;
      }
      return true;
    }
};