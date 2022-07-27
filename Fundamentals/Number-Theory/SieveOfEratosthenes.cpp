#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
int N = 1e6;
vector<bool> sieve(N + 1, 1);
void doSieve() {
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i <= N; i++) {  // this complexity is O(N log (log N));
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = 0;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    // print prime no. upto n;
    for (int i = 1; i <= n; i++) {
        if (sieve[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    doSieve();
    int T = 1;
    while (T--) solve();
}
