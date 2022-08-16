//try to remember about the operation which is O(1) it will give the idea about how the other operation has to work.
#include <bits/stdc++.h>
using namespace std;
class stack1 {
    queue<int> q1, q2;

   public:
    void push(int num) {  // O(1)
        q1.push(num);
    }
    void pop() {  // O(n)
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int top() {  // O(n)
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        q2.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
};
class stack2 {
    queue<int> q1, q2;

   public:
    void push(int num) {  // O(n)
        q2.push(num);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop() {  // O(1)
        q1.pop();
    }
    int top() { return q1.front(); }  // O(1)
};

int main() {
    stack1 obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << obj.top() << endl;
    obj.pop();
    obj.push(4);
    cout << obj.top() << endl;

    stack2 obj1;
    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    cout << obj1.top() << endl;
    obj1.pop();
    obj1.push(4);
    cout << obj1.top() << endl;
}
