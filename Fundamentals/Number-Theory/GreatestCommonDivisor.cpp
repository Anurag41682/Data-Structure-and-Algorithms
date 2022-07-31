#include <bits/stdc++.h>
#define int long long
using namespace std;
// here a is dividend and b is divisor in function parameter(Think this way to remember the Euclidean algorithm used behind this)
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; } 
int32_t main() {
    
    // gcd of two numbers
    // Time complexity O(log(min(a,b)))
    int a = 10, b = 100;
    cout << GCD(a, b) << endl;   
    
    // gcd of multiple numbers given in an array
    // Time complexity O(n*log(min(all the elements of array))) n is size of the array
    vector<int> v = {6, 16, 8, 20};
    int ans = v[0];
    for (int i = 0; i < (int)v.size(); i++) {
        ans = GCD(ans, v[i]);
    }
    cout << ans << endl;    
}
