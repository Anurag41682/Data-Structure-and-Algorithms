#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
//relation between lcm and hcf of two numbers a and b -> a * b = lcm(a, b) * hcf(a, b)(logic behind the function)
int LCM(int a, int b) { return (a * b) / GCD(a, b); }  
void solve() {
    // lcm of two numbers;
    // Time complexity O(log(min(a,b)))
    int a = 3, b = 9;
    cout << LCM(a, b) << endl;

    // lcm of multiple numbers
    // Time complextiy O(n*log(min(all the elements of array))) n is the size of
    // array
    vector<int> v = {2, 4, 6, 18};
    int ans = v[0];
    for (int i = 0; i < (int)v.size(); i++) {
        ans = LCM(ans, v[i]);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
}
