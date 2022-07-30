#include <bits/stdc++.h>
#define int long long
using namespace std;
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
int32_t main() {
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;
}
