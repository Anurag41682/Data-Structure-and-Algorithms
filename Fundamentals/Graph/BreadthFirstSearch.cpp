#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
void bfs(int node) {
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int currnode = q.front();
        q.pop();
        if (!vis[currnode]) {
            vis[currnode] = true;
            cout << currnode << " ";
            for (auto it : adj[currnode]) {
                q.push(it);
            }
        }
    }
}
void solve() {
    // vertex(n) and edge(m)
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    vis = vector<bool>(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);  // use for loop to visit every component when more than one
             // component are present
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
}
/*

Input:
9 9
1 2
2 4
4 5
5 6
6 9
8 9
8 7
7 3
3 2

Graph:

1-2-4-5-6
  |     |
  3-7-8-9
  
*/
