// https://www.acmicpc.net/problem/1991

#include <iostream>
#include <utility>
#include <vector>

#define SIZE 26

using namespace std;

vector<pair<char, char> > binary_tree(SIZE);

void PreorderTraversal(char node) {
    if (node == '.') {
        return;
    }

    cout << node;
    PreorderTraversal(binary_tree[node].first);
    PreorderTraversal(binary_tree[node].second);
}

void InorderTraversal(char node) {
    if (node == '.') {
        return;
    }

    InorderTraversal(binary_tree[node].first);
    cout << node;
    InorderTraversal(binary_tree[node].second);
}

void PostorderTraversal(char node) {
    if (node == '.') {
        return;
    }

    PostorderTraversal(binary_tree[node].first);
    PostorderTraversal(binary_tree[node].second);
    cout << node;
}

int main(void) {
    int N;
    char parent, left_child, right_child;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        cin >> parent >> left_child >> right_child;

        binary_tree[parent].first = left_child;
        binary_tree[parent].second = right_child;
    }

    PreorderTraversal('A');
    cout << endl;

    InorderTraversal('A');
    cout << endl;

    PostorderTraversal('A');
    cout << endl;

    return 0;
}
