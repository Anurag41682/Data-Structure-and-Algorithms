// extended eucledian theorem is used to find x and y
// from the equation ax + by = gcd(a,b)
// where a and b are given

// ax + by = gcd(a,b)---(i)
// since gcd(a,b) == gcd(b,a%b)
// therefore ax + by = gcd(a,b) can also be written as
// bx1 + (a%b)y1 = gcd(b,a%b)---- after comparing from (i) and right term of
// this equation, we suppose new x and y, x1 and y1 so that equation remain
// overall balanced
// since a%b == a-ceil(a/b)*b
// bx1 + (a-ceil(a/b)*b)y1 = gcd(b,a%b) = gcd(a,b)
// bx1 + ay1 - ceil(a/b)*y1 = gcd(a,b) bx1 - ceil(a/b)*y1
// + ay1 = gcd(a,b) b(x1- ceil(a/b)*y1) + ay1 = gcd(a,b) ay1 + b(x1-
// ceil(a/b)*y1) = gcd(a,b) --- (ii) after comparing (ii) from (i) we get
// x=y1 and y=(x1-ceil(a/b)*y1) ---(iii)

#include <bits/stdc++.h>

pair<int, int> extendedGCD(int a, int b) {  // this function find x and y for
    if (b == 0) {                           // give a and b
        return {1, 0};
    }
    auto t = extendedGCD(
        b, a % b);  // calling for next subproblem to get its x and y
    int x =
        t.second;  // so that we can use equation (iii) to find current x and y
    int y = t.first - (a / b) * t.second;
    return {x, y};
}
int main() {
    int a, b;
    std::cin >> a >> b;
    auto ans = extendedGCD(a, b);
    std::cout << ans.first << " " << ans.second << std::endl;
}
