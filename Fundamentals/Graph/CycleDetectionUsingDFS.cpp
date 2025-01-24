class Solution {
public:
  bool fn(int node, int parent, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
      if (vis[adj[node][i]]) {
        if (parent != adj[node][i]) {
          return true;
        }
      } else {
        if (fn(adj[node][i], node, adj, vis))
          return true;
      }
    }
    return false;
  }
  bool isCycle(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n);
    bool f = false;
    for (int i = 0; i < n; i++) {
      if (!visited[i])
        f |= fn(i, -1, adj, visited);
    }
    return f;
  }
};
