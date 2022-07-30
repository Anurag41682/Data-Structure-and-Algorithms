//Time Complexity O(log n)
#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
int binaryExponentiation(int base, int pow) {
    int res = 1;
    while (pow) {
        if (pow & 1) res *= base;
        pow >>= 1;
        base *= base;
    }
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << binaryExponentiation(a, b);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
