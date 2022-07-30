// Time complexity o(log (min(a,b)))
#include <bits/stdc++.h>
#define int long long
using namespace std;
// here a is dividend and b is divisor in function parameter(Think this way to remember the Euclidean algorithm used behind this)
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; } 
int32_t main() {
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;
}
