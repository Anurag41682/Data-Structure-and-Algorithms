#include <bits/stdc++.h>
using namespace std;
string bigAddition(string a, string b) {
    if (a.size() > b.size()) { //making sure that string b must be large value so that we can iterate till string a first.
        swap(a, b);
    }
    // reverse so that it become easy while indexing and adding carries to
    // forward direction
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    string res;
    for (int i = 0; i < (int)a.size(); i++) {
        int digitA = a[i] - '0';
        int digitB = b[i] - '0';
        int sum = digitA + digitB + carry;
        int toAppend = sum % 10;
        carry = sum / 10;
        res += (char)(toAppend + '0');
    }
    for (int i = (int)a.size(); i < (int)b.size(); i++) {
        int num = b[i] - '0' + carry;
        int toAppend = num % 10;
        carry = num / 10;
        res += (char)(toAppend + '0');
    }
    if (carry) res += '1';
    // reversing the result as it comes in reverse order
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    string a, b;
    cin >> a >> b;
    string ans = bigAddition(a, b);
    cout << ans << endl;
}
