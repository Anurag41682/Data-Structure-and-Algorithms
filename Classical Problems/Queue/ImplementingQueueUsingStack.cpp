#include <bits/stdc++.h>
using namespace std;
class que1 {
    stack<int> s1, s2;

   public:
    int front() {  // O(n)
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    void push(int num) { s1.push(num); }  // O(1)
    void pop() {                          // O(n)
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
};

class que2 {
    stack<int> s1, s2;

   public:
    int front() {
        return s1.top();  // O(1)
    }
    void push(int num) {  // O(n)
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(num);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop() {  // O(1)
        s1.pop();
    }
};

int main() {
    que1 obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << obj.front() << endl;
    obj.pop();
    obj.push(4);
    cout << obj.front() << endl;

    que2 obj1;
    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    cout << obj1.front() << endl;
    obj1.pop();
    obj1.push(4);
    cout << obj1.front() << endl;
}
