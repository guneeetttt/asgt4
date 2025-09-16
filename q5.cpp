#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }
    void pop() {
        if (q1.empty()) return;
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }
    int top() {
        if (q1.empty()) return -1;
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q2.push(res);
        q1.pop();
        swap(q1, q2);
        return res;
    }
    bool empty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;

    StackOneQueue s2;
    s2.push(5);
    s2.push(15);
    s2.push(25);
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;

    return 0;
}
