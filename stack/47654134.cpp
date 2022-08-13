// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, X;
    string command;
    stack<int> stack;

    cin >> N;

    for (int i(0); i < N; ++i) {
        cin >> command;

        if (command.compare("push") == 0) {
            cin >> X;
            stack.push(X);
        } else if (command.compare("pop") == 0)  {
            if (stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.top() << endl;
                stack.pop();
            }
        } else if (command.compare("size") == 0) {
            cout << stack.size() << endl;
        } else if (command.compare("empty") == 0) {
            cout << stack.empty() << endl;
        } else if (command.compare("top") == 0) {
            if (stack.empty()) {
                cout << -1 << endl;
            } else {
                cout << stack.top() << endl;
            }
        }
    }

    return 0;
}
