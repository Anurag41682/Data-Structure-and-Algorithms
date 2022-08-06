#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int nCr(int n, int r) {
    int x = 1, y = 1;
    if (n - r < r) {
        r = n - r;
    }
    while (r) {
        x *= n;
        y *= r;
        int t = GCD(x, y);
        x /= t;
        y /= t;
        n--;
        r--;
    }
    return x;
}
void solve() {
      int n, r;
      cin >> n >> r;
      cout << nCr(n,r) << endl; //outputs nCr of n and r     
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;  // cin>>T;
    while (T--) solve();
}
