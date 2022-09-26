/*
We know Fibonacci sequence is given by:
f(n)= f(n-1)+f(n-2);
where f(1) = 0, f(2) = 1; // base case
So by matrix multiplication properties we can write it as:
|f(n)|    =  |1 1| |f(n-1)|
                   |f(n-2)|
also we can write it as:
|f(n)|    =  |1 1| |f(n-1)|
|f(n-1)|     |1 0| |f(n-2)|
// here f(n-1) is utility added so that power of some constant term will come (in this case t is the constant term) so that we can use matrix 
// exponentiation to calculate it in O(log(n)) time complexity and the overall equation remain balanced.Upper term gives f(n) and lower term gives f(n-1)

Let us take n=5
|f(5)|    =  |1 1| |f(4)|
|f(4)|       |1 0| |f(3)|

Let us take n=4
|f(4)| = |1 1| |f(3)|
|f(3)|   |1 0| |f(2)|

Let us take n=3
|f(3)| = |1 1| |f(2)|= |1 1| |1| // since f(2) = 1 ,f(1) = 0 base case
|f(2)|   |1 0| |f(1)|= |1 0| |0|


Substituting value of |f(3)| in |f(4)| We get: |f(4)| = |1 1| |1 1| |f(2)|
                      |f(2)|    |f(3)|         |f(3)| = |1 0| |1 0| |f(1)|
  
Substituting value of |f(4)| in |f(5)| We get: |f(5)|= |1 1| |1 1| |1 1| |f(2)|
                      |f(3)|    |f(4)|         |f(4)|= |1 0| |1 0| |1 0| |f(1)|
  
Taking t = |1 1|
           |1 0|
We can write it as :
|f(5)|= t^3 |f(2)|
|f(4)|      |f(1)|
  
So the general formula become:
|f(n)|  =   t^(n-2) |f(2)|
|f(n-1) =           |f(1)|
*/



#include <bits/stdc++.h>
#ifndef LOCAL
#define dbg(x...)
#endif
#define endl '\n'
#define int long long
using namespace std;
vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return temp;
}
int fib(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    vector<vector<int>> res(2, vector<int>(2));
    res[0][0] = res[1][1] = 1;  // initialization with identity matrix so that result remain same after first multiplication.
    n -= 2;
    vector<vector<int>> ans(2, vector<int>(2));
    ans[0][0] = ans[0][1] = ans[1][0] = 1;  //initialization of t  i.e. constant term
    while (n) {
        if (n & 1) {
            res = multiply(res, ans);
        }
        ans = multiply(ans, ans);
        n >>= 1;
    }
    return res[0][0];
}
void solve() {
    int n;
    cin >> n;
    cout << fib(n);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
}
