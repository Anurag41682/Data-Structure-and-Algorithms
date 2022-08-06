#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
int nPr(int n, int r) {
    int x = 1;
    while (n - r) {
        x *= n;
        n--;
    }
    return x;
}
void solve() {
    int n, r;
    cin >> n >> r;
    cout << nPr(n, r) << endl; // outputs nPr of n and r
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;  // cin>>T;
    while (T--) solve();
}
