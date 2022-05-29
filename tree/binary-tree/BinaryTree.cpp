#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
public:
    struct Node {
        T data;
        Node *left_child;
        Node *right_child;
    };

    Node *root;

    BinaryTree(T data) {
        root = (Node*) malloc(sizeof(struct Node));
        root->data = data;
        root->left_child = nullptr;
        root->right_child = nullptr;
    };

    void Visit(Node* node) {
        cout << node->data;
    }

    void PreorderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        }
        
        Visit(node);
        PreorderTraversal(node->left_child);
        PreorderTraversal(node->right_child);
    }

    void InorderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        }

        InorderTraversal(node->left_child);
        Visit(node);
        InorderTraversal(node->right_child);
    }

    void PostorderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        }

        PostorderTraversal(node->left_child);
        PostorderTraversal(node->right_child);
        Visit(node);
    }
};
