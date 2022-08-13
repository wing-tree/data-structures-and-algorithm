// https://www.acmicpc.net/problem/1874

#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int sequence[100001];

int main(void) {
    int N, j(1);
    queue<char> queue;
    stack<int> stack;

    scanf("%d", &N);

    for (int i(1); i <= N; ++i) {
        scanf("%d", &sequence[i]);
    }

    for (int i(1); i <= N; ++i) {
        stack.push(i);
        queue.push('+');

        while(!stack.empty()) {
            if (sequence[j] == stack.top()) {
                stack.pop();
                queue.push('-');
                j++;
            } else {
                break;
            }
        }
    }

    if (!stack.empty()) {
        printf("NO");
    } else {
        while(!queue.empty()) {
            printf("%c\n", queue.front());
            queue.pop();
        }
    }

    return 0;
}
