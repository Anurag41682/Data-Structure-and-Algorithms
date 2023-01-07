// extended eucledian theorem is used to find x and y from the equation ax + by = gcd(a,b) (Bezout's identity) where a and b are given

// ax + by = gcd(a,b)---(i)
// since gcd(a,b) == gcd(b,a%b) -- euclidean algorithm
// therefore ax + by = gcd(a,b) can also be written as
// bx1 + (a%b)y1 = gcd(b,a%b) -- after comparing the right term of this equation from (i), We suppose new x and y, x1 and y1 so that equation remain
//                               overall balanced
// since a % b == a-floor(a/b)*b -- this is what modulus is
// bx1 + (a-floor(a/b)*b)y1 = gcd(b,a%b) = gcd(a,b)
// bx1 + ay1 - floor(a/b)*b*y1 = gcd(a,b)
// bx1 - floor(a/b)*b*y1 + ay1 = gcd(a,b)
// b(x1- floor(a/b)*y1) + ay1 = gcd(a,b) 
// ay1 + b(x1-floor(a/b)*y1) = gcd(a,b) --- (ii) after comparing (ii) from (i) we get
// x=y1 and y=(x1-ceil(a/b)*y1) ---(iii) this is the required thing to find the x and y
// Here x and y are of parent equation (which we need to find) and x1 and y1 (used to find x and y) are of child equation.


// Here x become multiplicative modlulo inverse (MMI) of a under modulo b if a and b are co-prime (relativily prime) that is gcd of both is 1
// otherwise it don't exist.

#include <bits/stdc++.h>

pair<int, int> extendedGCD(int a, int b) {  // this function find x and y for give a and b
    if (b == 0) {                          
        return {1, 0};
    }
    auto t = extendedGCD(b, a % b);  // calling for next subproblem to get its x and y so that we can use equation (iii) to find current x and y
    int x = t.second;               
    int y = t.first - (a / b) * t.second;
    return {x, y};
}
int main() {
    int a, b;
    std::cin >> a >> b;
    auto ans = extendedGCD(a, b);
    std::cout << ans.first << " " << ans.second << std::endl;
}
